#include "log.h"
#include "common.h"

#include <iostream>

int main() {

    Log log;
    AppTime appTime;
    

    log.log("Hello World!");

    double t = appTime.AppRunTime();
    std::cout << "App Run Time: " << t << std::endl;


    int year = 2018;
    
    
    
    return 0;
}
