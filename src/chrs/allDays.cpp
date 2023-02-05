#include "allDays.h"
#include <iostream>


AllDays::AllDays(
    int year
    , int firstDayOfWeek
) {
    
    this->_blockedDays = 0;
    this->year = year;

    this->_allDaysInYear = getAllDaysInYear(this->year);

    try {
        
        this->_beginRel = getSufficientDaysIndexAtBeginning(this->_allDaysInYear, firstDayOfWeek);
        this->_endRel = getSufficientDaysIndexAtEnd(this->_allDaysInYear, firstDayOfWeek);
        
        if ((this->endRel() - this->beginRel() + 1) % 7 != 0)
            throw new FirstDayOfWeekException("First day of week is not in the first 7 days of the year.");

        this->_usableDays = this->weeksToWork() * HEIGHT;
        this->cursor = this->beginRel();

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

    cursor += 7 * space; // TODO: Make immediate a var.
    
    // There MUST be always enough space for this char
    std::vector<bool> charAsVector = validChars.find(c)->second;
    for (bool b : charAsVector) {
        this->_allDaysInYear.at(this->cursor).setCommitable(b);
        this->cursor++;
    }

    return;
}


AllDays::~AllDays() {
    // TODO Auto-generated destructor stub

    return;
}


const char *AllDays::toCharPointer() {
    

    std::cout << std::to_string(this->beginRel()) << " : " << std::to_string(this->endRel()) << "\n";
    std::cout << std::to_string(this->weeksToWork()) << " : " << std::to_string(this->_usableDays) <<"\n";
    std::cout << std::to_string(this->_allDaysInYear.size()) << "\n";
    std::cout << std::to_string(this->_allDaysInYear.size() - this->beginRel() - (this->_allDaysInYear.size() - this->endRel())) << std::endl;



    // Unsafe - fix: Allocate in static space not stack
    static std::string s;
    int cursor = this->beginRel();
    int multiplied = 0;

    if (this->beginRel() != 0) // Year cannot start with an insufficient day
        s.append("X");
    
    
    while (true) {
        
        if (!this->workableBoundsInYear(cursor)) {

            if (this->endRel() != this->_allDaysInYear.size() - 1) { // Add end-insufficient days
                if (cursor > this->_allDaysInYear.size() - 1)
                    s.append("X");
                else
                    s.append("0");
            }
            
            cursor -= 7 * multiplied;
            cursor++;
            multiplied = 0;

            if (cursor >= this->beginRel() + 7)
                break;
            
            s.append("\n");

            if (this->beginRel() != 0) { // Add begin-insufficient days
                if (cursor - 7 < 0)
                    s.append("X");
                else
                    s.append("0");
            }

            continue;
        }


        s.append(std::to_string(this->_allDaysInYear[cursor].isCommitable()));
        
        cursor += 7;
        multiplied++;
        continue;
    }
    

    return s.c_str();
}


bool AllDays::workableBoundsInYear(
    int x
) {

    // ?? return this->_allDaysInYear.size() - this->beginRel() - (this->_allDaysInYear.size() - this->endRel());

    if (x < this->beginRel())
        return false;
    if (x > this->endRel())
        return false;

    return true;
}
