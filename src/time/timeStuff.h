#ifndef TIME_STUFF_H
#define TIME_STUFF_H


#include "dayInformation.h"
#include "../ex/exs.h"

#include <vector>


const std::vector<int> daysInMonth = {
    31
    , 28
    , 31
    , 30
    , 31
    , 30
    , 31
    , 31
    , 30
    , 31
    , 30
    , 31
}
;


bool isLeapYear(
    int year
    )
    ;


int getSufficientDaysIndexAtBeginning(
    std::vector<DayInformation> &days
    , int firstDayOfWeek
    )
    ;


int getSufficientDaysIndexAtEnd(
    std::vector<DayInformation> &days
    , int firstDayOfWeek
    )
    ;


std::vector<DayInformation> getAllDaysInYear(
    int year
    )
    ;

#endif
