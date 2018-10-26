/*
 * GUID Partition Table
 * GUID Partition Table (GPT) is a partitioning scheme that is part of the Unified Extensible
 * Firmware Interface specification; it uses globally unique identifiers (GUIDs), or UUIDs in
 * the Linux world, to define partitions and partition types. It is designed to succeed the
 * Master Boot Record partitioning scheme method.
 *
 * Created by marco.hirata on 16/10/2018.
*/


#ifndef READGPT_GPT_H
#define READGPT_GPT_H
using namespace std;
#include <stdint.h>
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include "Log.h"
#define TRADITIONAL_SECTOR_SIZE 512
#define FOURK_SECTOR_SIZE  4096
#define GPT_ENTRIES 128
#define GPT_NAMELEN 36
#define KBYTE 1024
#define LINE_SEPARATOR(byte, size)    std::cout << std::setfill (byte) << std::setw (size)<< "\n";
#define GPT_FLAG_SYSTEM (1ULL << 0)
#define GPT_FLAG_BOOTABLE (1ULL << 2)
#define GPT_FLAG_READONLY (1ULL << 60)
#define GPT_FLAG_DOAUTOMOUNT (1ULL << 63)
#define COLUMN_SIZE 112
#define GPT_HEADER_SIGNATURE "EFI PART"

#define GUID_SIZE            45



namespace readgpt{

    typedef struct _GUID {          // size is 16
        uint64_t  Data1;
        uint32_t  Data2;
        uint32_t  Data3;
        char      Data4[8];
    } GUID;

// it should be passed in little endian order
    struct GPT_entry_raw {
        uint8_t type_guid[16];
        uint8_t partition_guid[16];
        uint64_t first_lba; // little endian
        uint64_t last_lba;
        uint64_t flags;
        uint16_t name[GPT_NAMELEN]; // UTF-16 LE
    };

    struct GPT_mapping {
        void *map_ptr;
        void *ptr;
        unsigned size;
    };

    struct GPT_entry_table {
        int fd;

        struct GPT_mapping header_map;
        struct GPT_mapping entries_map;
        struct GPT_mapping sec_header_map;
        struct GPT_mapping sec_entries_map;

        struct GPT_header *header;
        struct GPT_entry_raw *entries;
        struct GPT_header *second_header;
        struct GPT_entry_raw *second_entries;

        unsigned sector_size;
        unsigned partition_table_size;
        int second_valid;
    };

    struct GPT_header {
        uint8_t signature[8];
        uint32_t revision;
        uint32_t header_size;
        uint32_t header_checksum;
        uint32_t reserved_zeros;
        uint64_t current_lba;
        uint64_t backup_lba;
        uint64_t first_usable_lba;
        uint64_t last_usable_lba;
        uint8_t disk_guid[16];
        uint64_t entries_lba;
        uint32_t entries_count;
        uint32_t entry_size;
        uint32_t partition_array_checksum;
        // the rest should be filled with zeros
    } __attribute__((packed));

    struct GPT_content {
        struct GPT_header header;
        struct GPT_entry_raw *entries;
    };



    class GPT {

    public:
        GPT(const char *file_name);
     //   json_object * get_json_gpt();
        double get_sector_size();
        double sectors_to_bytes(double value);
        double sectors_to_kbytes(double value);
        double bytes_to_sectors(double value);
        double kbytes_to_sectors(double value);
        struct GPT_content get_content();
        struct GPT_header get_header();
        uint8_t * get_disk_guid();
        GUID get_guid();
        void print();
        double get_sector_size() const;
        void set_sector_size(double _sector_size);
        virtual ~GPT();
        static void wtoc(char* Dest, const uint16_t* Source);

    private:
        double _sector_size;
        struct GPT_content _content;
        GUID _disk_guid;
    };
};

#endif //READGPT_GPT_H
