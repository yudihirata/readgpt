#include <iostream>
#include <getopt.h>
#include <limits.h>
#include "include/Log.h"
#include "include/version.h"
#include "include/GPT.h"

using namespace readgpt;
using namespace std;

void usage();
void print_gpt(const char * filepath);

int main(int argc, char **argv) {
    char *pFilename = nullptr;
    char output[PATH_MAX] = {'\0'};
    log_type flag = NONE;

    struct option long_options[] = {
            /* These options set a flag. */
            /* These options don't set a flag.
             We distinguish them by their indices. */
            {"version", no_argument,       no_argument, 'z'},
            {"output",  required_argument, no_argument, 'o'},
            {"file",    required_argument, no_argument, 'f'},
            {"help",    no_argument,       no_argument, 'h'},
            {"debug",   no_argument,       no_argument, 'd'},
            {"verbose", no_argument,       no_argument, 'v'},
            {"gpt",     required_argument, no_argument, 't'},
            {nullptr, 0, nullptr,                         0}
    };
    //Log::set_log_type(VERBOSE);
    while (true) {
        /* getopt_long stores the option index here. */
        int option_index = 0;

        const auto opt = getopt_long(argc, argv, "o:f:hzdv", long_options,
                                     &option_index);

        /* Detect the end of the options. */
        if (opt == -1) {
            break;
        }

        switch (opt) {
            case 'z' :
                cout << VER_PRODUCTNAME_STR << " " << VERSION;
#ifdef OS_WIN
#if defined (_WIN64) || defined (__CYGWIN64__)
            cout << " - 64 bit Operating System" << endl;
#else
            cout << " - 32 bit Operating System" << endl;
#endif
#else
#if __x86_64__
                cout << " - x86_64 Linux version" << endl;
#else
                cout << " - i386 Linux version" << endl;
#endif
#endif // OS_WIN
                cout << endl << "AUTHOR" << endl << "Written by " << AUTHOR << endl;


                cout << "REPORTING BUGS" << endl << "Report " << VER_PRODUCTNAME_STR <<
                     "bugs to " << EMAIL_SUPPORT << endl;
                cout << VER_COPYRIGHT_STR << endl;
                exit(0);
                break;
            case 'f':
                pFilename = optarg;
                break;
            case 'd':
                flag = (log_type) (flag | FILE_LOG);
                break;
            case 'v':
                flag = (log_type) (flag | VERBOSE);
                break;
            case 't':
                pFilename = optarg;
                break;
            case 'o':
                strcpy(output, optarg);
                break;
            case 'h':
                usage();
                exit(0);
                break;

            default:
                printf("help");
        }
    }
    Log::set_log_type(flag);
    print_gpt(pFilename);
    return 0;
}

void usage() {
    cout << "READGPT - " << VERSION << "\t\t" << CODENAME << "\t\t\t" <<
         VER_FILE_DESCRIPTION_STR << endl;
    cout << "Usage: " << VER_PRODUCTNAME_STR << " [OPTION...] [FILE...]" << endl;
    cout << VER_PRODUCTNAME_STR << ": read GPT from file.\n" << endl;
    cout << "\t--help          display this help and exit" << endl;
    cout << "\t-z, --version   output version information and exit" << endl;
    cout << "\t-f, --file      The argument following the -f is used to indicate the "
            "binary file" << endl;
}

void print_gpt(const char * filepath){
    try{
        GPT * obj_gpt  = new GPT(filepath);
        obj_gpt->print();
        delete(obj_gpt);
    }
    catch(exception &e){
        cout << e.what() << endl;
    }
}
