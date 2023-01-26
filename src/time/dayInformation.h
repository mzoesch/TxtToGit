#ifndef DAY_INFORMATION_H
#define DAY_INFORMATION_H

#include <ctime>

const int timeStandard [] = {
    0       // second
    , 0     // minute
    , 0     // hour
    , 0     // day (1-based)
    , 0     // month (0-based)
    , -1900 // year (since 1900)
}
;

class DayInformation {

public:

    DayInformation(
        int year
        , int month
        , int day
    )
    ;
    ~DayInformation();

private:

    int year;
    int month;
    int day;
    int _dayOfWeek;

private:

    int calculateDayOfWeek();

public:

    int dayOfWeek() const { return this->_dayOfWeek; }
    
}
;





#endif
