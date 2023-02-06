#ifndef DAY_INFORMATION_H
#define DAY_INFORMATION_H

#include "tDateHolder.h"

#include <ctime>
#include <string>

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
    bool commit;
    int _dayOfWeek;

private:

    int calculateDayOfWeek();

public:

    bool isCommitable();
    void setCommitable(bool commit);
    int dayOfWeek() const { return this->_dayOfWeek; }
    int getDay() const { return this->day; }
    std::string getDate() const {
        return std::to_string(this->day) + " " + std::to_string(this->month) + " " + std::to_string(this->year);
    }
    tDateHolder getDate();
    
}
;





#endif
