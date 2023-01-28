#include "allDays.h"

#include <iostream>

AllDays::AllDays(
    int year
    , int firstDayOfWeek
) {
    
    this->_blockedDays = 0;
    this->cursor = 0;
    this->year = year;

    this->_allDaysInYear = getAllDaysInYear(this->year);

    try {
        
        this->_beginRel = getInsufficientDaysIndexAtBeginning(this->_allDaysInYear, firstDayOfWeek);
        this->_endRel = getInsufficientDaysIndexAtEnd(this->_allDaysInYear, firstDayOfWeek);
        
        if ((this->endRel() - this->beginRel() + 1) % 7 != 0)
            throw new FirstDayOfWeekException("First day of week is not in the first 7 days of the year.");

        this->_usableDays = this->weeksToWork() * HEIGHT;

    } catch (std::exception *e) {
        
        std::cerr << e->what() << std::endl;
        exit(EXIT_FAILURE);
    }

    return;
}


int AllDays::addBlockedDays(
    int days
) {
    
    if (this->blockedDays() + days > this->usableDays())
        return -1;

    this->_blockedDays += days;

    return 0;
}


bool AllDays::charIsValid(
    char c
) {
    
    return validChars.find(c) != validChars.end();
}


void AllDays::addChar(
    char c
    , int space
    , bool useMonospace
) {

    // TODO: Build space and useMonospace

    try {
        
        if (!this->charIsValid(c))
            throw new UnknownCharException(new char(c)); // On heap

        if (this->addBlockedDays(validChars.find(c)->second.size()) == -1)
            throw new NotEnoughSpaceToDisplayMessageException(new char(c)); // Heap
    
    } catch (std::exception *e) {
        
        std::cerr << e->what() << std::endl;
        exit(EXIT_FAILURE);
    }

    // There MUST be always enough space for this char
    std::vector<bool> charAsVector = validChars.find(c)->second;
    for (bool b : charAsVector) {
        
        if (b != true ) {
            this->cursor++;
            continue;
        }

        this->_allDaysInYear.at(this->cursor).setCommitable(b);
        this->cursor++;
    }

    return;
}


AllDays::~AllDays() {
    // TODO Auto-generated destructor stub

    return;
}


char *AllDays::toCharPointer() {
    
    

    
    return NULL;
}
