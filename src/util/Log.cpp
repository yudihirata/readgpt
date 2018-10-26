//
// Created by marco.hirata on 16/10/2018.
//

#include "Log.h"
using namespace readgpt;
Log * Log::_instance = nullptr;
log_type Log::_log_type = NONE;

Log *Log::get_instance(){
    if (Log::_instance == nullptr){
        Log::_instance = new Log();
    }
    return Log::_instance;
}

log_type Log::get_log_type(){
    return Log::_log_type;
}

void Log::set_log_type(log_type type){
    Log::_log_type = type;
}



void Log::write_log(int ltType, const char *fmt, ...){
    va_list args;
    va_start (args, fmt);

    if (ltType & FILE_LOG){
        FILE * pFile;
        char file_name[FILENAME_MAX]   = {'\0'};

#ifdef OS_WIN
        sprintf(file_name,"%s\\readgpt.log",getenv ("TEMP") );
#else
        sprintf(file_name,"%s/readgpt.log",getenv ("HOME") );
#endif
        pFile = ::fopen (file_name,"a+");
        vfprintf (pFile,fmt,args);
        fclose(pFile);
    }
    if (ltType & VERBOSE){
        vfprintf (stdout,fmt,args);
    }
}

void Log::write_log(const char *fmt, ...){
    Log::write_log(Log::get_log_type(), fmt);
}

