#include "common.h"

#include <thread>

AppTime::AppTime() {    
    this->start = std::chrono::high_resolution_clock::now();
}


double AppTime::AppRunTime() {
    
    std::chrono::high_resolution_clock::time_point tp = std::chrono::high_resolution_clock::now();
    double timeElapsed = std::chrono::duration<double, std::milli>(tp - this->start).count();
    return timeElapsed;
};


AppTime::~AppTime() {
    // TODO Auto-generated destructor stub
}
