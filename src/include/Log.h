//
// Created by marco.hirata on 16/10/2018.
//

#ifndef READGPT_LOG_H
#define READGPT_LOG_H
#include <unistd.h>
#if defined (_WIN64) || defined (__CYGWIN64__)
#include <windows.h>
#endif
#include <stdio.h>
#include <iostream>
#include <stdarg.h>
#include <sys/types.h>
#include <string.h>
#include <cstdlib>     /* getenv */

#define DEBUG_INFO(x,...) Log::get_instance()->write_log("DEBUG : " x,##__VA_ARGS__)
#define LOG_INFO(x,...)   Log::get_instance()->write_log(FILE_LOG,"INFO : " x,##__VA_ARGS__)

namespace readgpt {
    enum log_type {
        NONE      = 0,
        VERBOSE   = 1,
        FILE_LOG  = 2
    };

    class Log {
    private:
        static Log *_instance;
        static log_type _log_type;
    public:
        static  Log * get_instance();
        void write_log(int ltType, const char *fmt, ...);
        void write_log(const char *fmt, ...);
        static log_type get_log_type();
        static void set_log_type(log_type type);
    };
}


#endif //READGPT_LOG_H
