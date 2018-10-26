//
// Created by marco.hirata on 16/10/2018.
//

#include <cstring>
#include "GPT.h"
using namespace readgpt;


GPT::GPT(const char *file_name){
    FILE * pfile = nullptr;
    int seek;
    int sector_sizes[2] = {TRADITIONAL_SECTOR_SIZE,FOURK_SECTOR_SIZE};

    set_sector_size(TRADITIONAL_SECTOR_SIZE);
    memset(&_content,0x00,sizeof(struct GPT_content));

    if ( ( pfile = fopen( file_name, "rb" ) )  == nullptr ){
        DEBUG_INFO("%s - failed to open the file %s\n", __func__, file_name);
        throw std::invalid_argument( "failed to open GPT" );
    }

    /* Traditionally 512 bytes for hard disk drives (HDDs).
    * Newer HDDs use 4096-byte (4 KiB) sectors, which are known as the Advanced
    * Format (AF). https://en.wikipedia.org/wiki/Disk_sector   */

    for (int i = 0; sizeof(get_sector_size())/sizeof(int); i++){
        seek = sector_sizes[i];
        fseek(pfile, seek, SEEK_SET);
        if ( (fread( (uint8_t*)&_content.header, 1, sizeof(struct GPT_header),
                     pfile)) != sizeof(struct GPT_header) ){
            fclose(pfile);
            DEBUG_INFO("%s - failed to  read GPT HEADER\n",__func__);
            throw std::runtime_error(" failed to  read GPT HEADER");
        }
        if (!strncmp((const char*)_content.header.signature,GPT_HEADER_SIGNATURE,
                     strlen(GPT_HEADER_SIGNATURE))){
            set_sector_size(sector_sizes[i]);
            break;
        }
    }
    _content.entries = ( struct GPT_entry_raw *) malloc(
            sizeof(GPT_entry_raw)*_content.header.entries_count);
    if (_content.entries == nullptr){
        fprintf(stderr, "%s: malloc failed\n", __func__);
        throw std::invalid_argument( "malloc failed" );
    }

    fseek(pfile,seek * 2,SEEK_SET);
    if ( fread( _content.entries, 1, _content.header.entries_count *
    sizeof(GPT_entry_raw) ,pfile) !=  ( _content.header.entries_count * sizeof(GPT_entry_raw) ) ){
        fclose(pfile);
        DEBUG_INFO("%s - failed to  read GPT entries\n",__func__);
        throw std::runtime_error(" failed to  read GPT entries");
    }
    /* GUID Disk */
    memcpy((void * )&_disk_guid,(const void * )_content.header.disk_guid,  sizeof(GUID));

    if (pfile != nullptr){
        fclose(pfile);
    }
}

GPT::~GPT(){
    free(_content.entries);
}

double GPT::get_sector_size() const {
    return _sector_size;
}

void GPT::set_sector_size(double sector_size) {
    _sector_size = sector_size;
}

GPT_content GPT::get_content(){
    return _content;
}


/* Traditionally 512 bytes for hard disk drives (HDDs).
 * Newer HDDs use 4096-byte (4 KiB) sectors, which are known as the Advanced
 * Format (AF). https://en.wikipedia.org/wiki/Disk_sector */
double GPT::get_sector_size(){
    return _sector_size;
}

double GPT::sectors_to_bytes(double value){
    return (value * get_sector_size());
}

double GPT::sectors_to_kbytes(double value){
    return ( sectors_to_bytes(value) / KBYTE );
}

double GPT::bytes_to_sectors(double value){
    return (value / get_sector_size());
}

double GPT::kbytes_to_sectors(double value){
    return ( bytes_to_sectors(value * KBYTE) );
}

GUID GPT::get_guid(){
    return _disk_guid;
}

uint8_t * GPT::get_disk_guid(){
    return _content.header.disk_guid;
}

struct GPT_header GPT::get_header(){
    return _content.header;
}

void GPT::print(){
    cout << "[+] Partition table header" <<endl;
    LINE_SEPARATOR('=',COLUMN_SIZE);
    cout << "Signature:      " << hex << uppercase  << _content.header.signature << endl;
    cout << "Checksum:       0x" << hex << uppercase   << _content.header.header_checksum << endl;
    cout << "Revision:       0x" << hex << uppercase   << _content.header.revision << endl;
    // Globally unique identifier (GUID) 00000000-0000-0000-0000-000000000000
    cout << "GUID    :       ";
    cout << setw(8) << hex << std::setfill('0') << (0xFFFFFFFF &_disk_guid.Data1) << "-";
    cout << setw(4) << std::setfill('0') << hex << (0xFFFF & _disk_guid.Data2) << "-";
    cout << setw(4) << std::setfill('0') << hex << (0xFFFF &_disk_guid.Data3) << "-";
    cout << setw(2) << std::setfill('0') << hex << (0xFF & _disk_guid.Data4[0]);
    cout << setw(2) << std::setfill('0') << hex << (0xFF & _disk_guid.Data4[1]) << "-";
    cout << setw(2) << std::setfill('0') << hex << (0xFF & _disk_guid.Data4[2]);
    cout << setw(2) << std::setfill('0') << hex << (0xFF &_disk_guid.Data4[3]);
    cout << setw(2) << std::setfill('0') << hex << (0xFF &_disk_guid.Data4[4]);
    cout << setw(2) << std::setfill('0') << hex << (0xFF &_disk_guid.Data4[5]);
    cout << setw(2) << std::setfill('0') << hex << (0xFF &_disk_guid.Data4[6]);
    cout << setw(2) << std::setfill('0') << hex << (0xFF &_disk_guid.Data4[7]) <<endl;


    cout << "[+] GUID Partition Table" << endl;
    cout << "Index |        Partition |         Offset          |        Size   |"
           "  GUID                " << endl;

    for(unsigned int i=0; i < this->_content.header.entries_count; i++ ){
        GUID guid;
        char name[GPT_NAMELEN];  /* Convert the partition name wide-character
                                    (16bits) string  encode to char */
        double size          = 0;
        memset(name,'\0',GPT_NAMELEN);
        wtoc(name, this->_content.entries[i].name);
        if (strlen(name) == 0 ){
            continue;
        }
        memcpy((void * )&this->_disk_guid,(const void * )_content.header.disk_guid,
               sizeof(GUID));
        memcpy((void * )&guid,(const void * )this->_content.entries[i].
                partition_guid,sizeof(GUID));
        size = (int)this->sectors_to_kbytes(this->_content.entries[i].last_lba -
                                            this->_content.entries[i].first_lba + 1);
        if (size > 0 ){
            cout << setw(5) << std::dec << std::setfill(' ') << i << " | ";
            cout << setw(16) << std::setfill(' ') << name << " |  ";
            cout << "0x" << setw(8) << std::setfill('0') << hex << (0xFFFFFFFF &
                _content.entries[i].first_lba) << "-";
            cout << "0x" << setw(8) << std::setfill('0') << hex << (0xFFFFFFFF &
                _content.entries[i].last_lba ) << "  |  ";
            cout << setw(10) << std::dec << std::setfill(' ') << (int)size << "K  |  ";
            cout << setw(8) << std::setfill('0') << hex << (0xFFFFFFFF & guid.Data1 ) << "-";
            cout << setw(4) << std::setfill('0') << hex << (0xFFFF & guid.Data2) << "-";
            cout << setw(4) << std::setfill('0') << hex << (0xFFFF &guid.Data3) << "-";
            cout << setw(2) << std::setfill('0') << hex << (0xFF & guid.Data4[0]) ;
            cout << setw(2) << std::setfill('0') << hex << (0xFF & guid.Data4[1])  << "-";
            cout << setw(2) << std::setfill('0') << hex << (0xFF & guid.Data4[2]);
            cout << setw(2) << std::setfill('0') << hex << (0xFF & guid.Data4[3]);
            cout << setw(2) << std::setfill('0') << hex << (0xFF & guid.Data4[4]);
            cout << setw(2) << std::setfill('0') << hex << (0xFF & guid.Data4[5]);
            cout << setw(2) << std::setfill('0') << hex << (0xFF & guid.Data4[6]);
            cout << setw(2) << std::setfill('0') << hex << (0xFF & guid.Data4[7]) <<endl;
        }
    }
}

/*
Unfortunately the function wcstombs does not work here.
The size of wchar_t is 4 bytes  on 64bit OS
http://man7.org/linux/man-pages/man3/wcstombs.3.html
Convert the partition name wide-character(16bits) string  encode to char
*/
void GPT::wtoc(char* Dest, const uint16_t* Source){
    int i = 0;
    while(Source[i] != '\0'){
        Dest[i] = static_cast<char>(wctob(Source[i]));
        ++i;
    }
}

