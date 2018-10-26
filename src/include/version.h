//
// Created by marco.hirata on 18/10/2018.
//

#ifndef READGPT_VERSION_H
#define READGPT_VERSION_H
#define STRINGIZE2(s) #s
#define STRINGIZE(s) STRINGIZE2(s)
#define VERSION_MAJOR               1
#define VERSION_MINOR               0
#define VERSION_REVISION            0
#define VERSION_BUILD               0
#define VER_FILE_DESCRIPTION_STR    "Read GUID Partition Table"
#define VER_FILE_VERSION            VERSION_MAJOR, VERSION_MINOR, \
                                    VERSION_REVISION, VERSION_BUILD
#define CODENAME                    "BETA"
#ifdef _DEBUG
#define VER_FILE_VERSION_STR        STRINGIZE(VERSION_MAJOR)        \
                                    "." STRINGIZE(VERSION_MINOR)    \
                                    "." STRINGIZE(VERSION_REVISION) \
                                    ".debug"
#else
#define VER_FILE_VERSION_STR        STRINGIZE(VERSION_MAJOR)        \
                                    "." STRINGIZE(VERSION_MINOR)    \
                                    "." STRINGIZE(VERSION_REVISION)
#endif
#define VER_PRODUCTNAME_STR         "readgpt"
#define VER_PRODUCT_VERSION         VER_FILE_VERSION
#define VER_PRODUCT_VERSION_STR     VER_FILE_VERSION_STR
#define VER_ORIGINAL_FILENAME_STR   VER_PRODUCTNAME_STR ".exe"
#define VER_INTERNAL_NAME_STR       VER_ORIGINAL_FILENAME_STR
#define VER_COPYRIGHT_STR           "Copyright (c) 2018 Yudi Hirata.\
                                    All Rights Reserved."
#define AUTHOR                      "Marco Yudi Hirata"
#define EMAIL_SUPPORT               "yudihirata@gmail.com"
#define VERSION VER_FILE_VERSION_STR
#endif //READGPT_VERSION_H
