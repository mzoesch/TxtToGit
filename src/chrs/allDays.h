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
        , int minCommits
        , int maxCommits
        , int makeCommitsInDifferentRepo
        , std::string pathToDifferentRepo
    )
    ;
    ~AllDays();

private:
    
    const static char INSUFFICIENT = 'X';
    const static char IS_COMMIT = '@';
    const static char IS_NOT_COMMIT = '.';
    const static char NEW_LINE = '\n';

    const static int MONOSPACE_SIZE = 35;
    const static int DAYS_IN_WEEK = 7;

    int year;
    int firstDayOfWeek;
    int _blockedDays;
    int _usableDays;
    int _beginRel; // True index
    int _endRel; // True index
    int cursor;
    int minCommits;
    int maxCommits;
    int makeCommitsInDifferentRepo;
    std::string pathToDifferentRepo;
    std::vector<DayInformation> _allDaysInYear;  

private:

    int blockedDays() const { return this->_blockedDays; }
    int usableDays() const { return this->_usableDays; }
    int weeksToWork() const { return (this->endRel() - this->beginRel() + 1) / HEIGHT; }
    int beginRel() const { return this->_beginRel; }
    int endRel() const { return this->_endRel; }
    int addBlockedDays(int days);
    int weeksToFillUpInMonospace(int days) const { return (this->MONOSPACE_SIZE - days) / this->DAYS_IN_WEEK; }
    bool charIsValid(char c);
    bool workableBoundsInYear(int x);
    void rotateRight(int weeks);
    void rotateLeft(int weeks);
    
public:

    void addChar(
        char c
        , int space
        , bool useMonospace
        )
        ;
    void align(int n);
    void commitEverything();
    const char *toCharPointer();

}
;

#endif
