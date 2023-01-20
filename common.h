#ifndef common_h
#define common_h

#include <iostream>

struct AppTime {

private:

    std::chrono::high_resolution_clock::time_point start;


public:

    AppTime();
    ~AppTime();

    double AppRunTime();

}
;

#endif
