#include "timeStuff.h"


bool isLeapYear(
    int year
    ) {
    // Using gregorian calendar
    // Rule 1:
    //      A year is a leap year if it is divisible by 4
    // Rule 2:
    //      A year is not a leap year if it is divisible by 100
    // Rule 3:
    //      A year is a leap year if it is divisible by 400
    // 

    return (
            (
                (year % 4) == 0
            ) && (
                (year % 100) != 0 
            )
        ) || (
            (year % 400) == 0 
        )
        ;
}


int getSufficientDaysIndexAtBeginning(
    std::vector<DayInformation> &days
    , int firstDayOfWeek
    ) {
    
    int i = 0;

    while (days[i].dayOfWeek() != firstDayOfWeek) {
        if (i > 6)
            throw new FirstDayOfWeekException("First day of week is not in the first 7 days of the year.");
        
        i++;
    }

    return i;
}


int getSufficientDaysIndexAtEnd(
    std::vector<DayInformation> &days
    , int firstDayOfWeek
    ) {
    
    int i = 0;
    while (days[days.size() - i - 1].dayOfWeek() != (firstDayOfWeek + 6) % 7) {
        if (i > 6)
            throw new FirstDayOfWeekException("First day of week is not in the last 7 days of the year.");
        
        i++;
    }

    return days.size() - i - 1;
}


std::vector<DayInformation> getAllDaysInYear(
    int year
    ) {
        
    std::vector<DayInformation> daysInYear;
    daysInYear.reserve(366); // Max days in a year

    for (int month = 0; month < 12; month++) {
        
        int daysInThisMonth = daysInMonth[month];
        if (month == 1 && isLeapYear(year))
            daysInThisMonth++;
        
        for (int day = 1; day <= daysInThisMonth; day++) {
            
            DayInformation dayInfo = DayInformation(year, month, day);
            daysInYear.push_back(dayInfo);
        }        
    }

    return daysInYear;
}
