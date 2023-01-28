#ifndef ALL_DAYS_H
#define ALL_DAYS_H

#include "chrs.h"
#include "../ex/exs.h"
#include "../time/dayInformation.h"
#include "../time/timeStuff.h"

#include <stdlib.h>

const int HEIGHT = 7;
const int MONO_WIDTH = 5;

class AllDays {

public:

    AllDays(
        int year
        , int firstDayOfWeek
    )
    ;
    ~AllDays();

private:

    int year;
    int firstDayOfWeek;
    int _blockedDays;
    int _usableDays;
    int _beginRel;
    int _endRel;
    int cursor;
    std::vector<DayInformation> _allDaysInYear;  

public:

    int blockedDays() const { return this->_blockedDays; }
    int usableDays() const { return this->_usableDays; }
    int beginRel() const { return this->_beginRel; }
    int endRel() const { return this->_endRel; }
    int weeksToWork() const { return (this->endRel() - this->beginRel() + 1) / HEIGHT; }

private:

    int addBlockedDays(int days);
    bool charIsValid(char c);

public:

    void addChar(
        char c
        , int space
        , bool useMonospace
        )
        ;

    char *toCharPointer();

}
;

#endif
