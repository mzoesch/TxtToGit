#ifndef ALL_DAYS_H
#define ALL_DAYS_H

#include "chrs.h"
#include "../ex/exs.h"
#include "../time/dayInformation.h"
#include "../time/timeStuff.h"

#include <stdlib.h>
#include <string>

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
    int _beginRel; // True index
    int _endRel; // Ture index
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
    bool workableBoundsInYear(int x);

public:

    void addChar(
        char c
        , int space
        , bool useMonospace
        )
        ;

    const char *toCharPointer();

}
;

#endif
