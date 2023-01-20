#include "log.h"


void log(
    const char *message
    , bool newline
    , bool writeToFile
    , bool withTime
    , bool writeToConsole
    , bool consoleWithTime
    ) {
    
    std::cout << message << std::endl;
    
    return;
}
