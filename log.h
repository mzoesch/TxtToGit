#ifndef LOG_H
#define LOG_H

#include <iostream>

struct Log {

    Log();
    ~Log();
    
    void log (
        const char* message
        , bool newline = true
        , bool writeToFile = false
        , bool withTime = true
        , bool writeToConsole = true
        , bool consoleWithTime = true
    )
    ;
   
}
;

#endif
