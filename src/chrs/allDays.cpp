#include "allDays.h"
#include <iostream>


AllDays::AllDays(
    int year
    , int firstDayOfWeek
    , int minCommits
    , int maxCommits
    , int makeCommitsInDifferentRepo
    , std::string pathToDifferentRepo
) {
    
    this->_blockedDays = 0;
    this->year = year;
    this->minCommits = minCommits;
    this->maxCommits = maxCommits;

    this->makeCommitsInDifferentRepo = makeCommitsInDifferentRepo;
    this->pathToDifferentRepo = pathToDifferentRepo;

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
    , int space // Space in weeks
    , bool useMonospace
) {

    int spaceToAdd;
    int charSize;

    try {
        
        spaceToAdd = this->DAYS_IN_WEEK * space;
        if (this->addBlockedDays(spaceToAdd))
            throw new NotEnoughSpaceToDisplayMessageException(new char(c)); // On heap

        if (!this->charIsValid(c))
            throw new UnknownCharException(new char(c));
        charSize = useMonospace ? this->MONOSPACE_SIZE : validChars.find(c)->second.size();
        if (this->addBlockedDays(charSize) == -1)
            throw new NotEnoughSpaceToDisplayMessageException(new char(c));

    } catch (std::exception *e) {
        
        std::cerr << e->what() << std::endl;
        exit(EXIT_FAILURE);
    }

    cursor += spaceToAdd;
    
    std::vector<bool> charAsVector = validChars.find(c)->second;
    
    if (charAsVector.size() == this->MONOSPACE_SIZE || !useMonospace) {
        
        for (bool b : charAsVector) {
            this->_allDaysInYear.at(this->cursor).setCommitable(b);
            this->cursor++;
        }

        return;
    }

    // Fill char with false statements (Monospace == true)
    int weeksToFillUp = this->weeksToFillUpInMonospace(charAsVector.size());
    bool append = true; // If above var is odd, a week will be more appended than prepended

    while (weeksToFillUp > 0) {
        
        int i = 0;
        while (i < this->DAYS_IN_WEEK) {
                        
            charAsVector.insert(append ? charAsVector.end() : charAsVector.begin(), false);
            i++;

            continue;
        }
        
        append = !append;
        weeksToFillUp--;

        continue;
    }

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

    // Unsafe - fix: Allocate in static space not stack
    static std::string s;
    s = ""; // Clear string if this method is called multiple times
    int cursor = this->beginRel();
    int multiplied = 0;

    if (this->beginRel() != 0) // Year cannot start with an insufficient day
        s.push_back(this->INSUFFICIENT);

    while (true) {
        
        if (!this->workableBoundsInYear(cursor)) {
            
            if (this->endRel() != this->_allDaysInYear.size() - 1) // Add end-insufficient days
                s.push_back(
                    cursor > this->_allDaysInYear.size() - 1 ? this->INSUFFICIENT : this->IS_NOT_COMMIT
                )
                ;

            cursor -= 7 * multiplied;
            cursor++;
            multiplied = 0;

            if (cursor >= this->beginRel() + 7)
                break;
            
            s.push_back(this->NEW_LINE);

            if (this->beginRel() != 0) // Add begin-insufficient days
                s.push_back(
                    cursor - 7 < 0 ? this->INSUFFICIENT : this->IS_NOT_COMMIT
                )
                ;

            continue;
        }

        s.push_back(
            this->_allDaysInYear[cursor].isCommitable() ? this->IS_COMMIT : this->IS_NOT_COMMIT
        )
        ;
        
        cursor += 7;
        multiplied++;
        continue;
    }
    

    return s.c_str();
}


bool AllDays::workableBoundsInYear(
    int x
) {

    if (x < this->beginRel())
        return false;
    if (x > this->endRel())
        return false;

    return true;
}


void AllDays::align(
    int alignment
) {

    if (alignment == 0) // Text is automatically aligned left
        return;

    if (alignment == 1) { // Center

        int spaceBeforeTxtInWeeks = 0;
        int spaceAfterTxtInWeeks = 0;

        while (true) {

            if (this->_allDaysInYear[this->beginRel() + spaceBeforeTxtInWeeks].isCommitable() == true)
                break;

            spaceBeforeTxtInWeeks++;

            continue;
        }
        
        while (true) {
            
            if (this->_allDaysInYear[this->endRel() - spaceAfterTxtInWeeks].isCommitable() == true)
                break;

            spaceAfterTxtInWeeks++;

            continue;
        }

        spaceBeforeTxtInWeeks /= this->DAYS_IN_WEEK;
        spaceAfterTxtInWeeks /= this->DAYS_IN_WEEK;

        if (spaceBeforeTxtInWeeks == spaceAfterTxtInWeeks)
            return;
        
        int delta = spaceBeforeTxtInWeeks - spaceAfterTxtInWeeks;
        int transform = delta / 2;
        if (transform == 0)
            return;

        if (transform < 0)
            this->rotateRight(transform);
        if (transform > 0)
            this->rotateLeft(transform);

        return;
    }

    if (alignment == 2) { // Right
        
        int spaceBeforeTxtInWeeks = 0;
        int spaceAfterTxtInWeeks = 0;

        while (true) {

            if (this->_allDaysInYear[this->beginRel() + spaceBeforeTxtInWeeks].isCommitable() == true)
                break;

            spaceBeforeTxtInWeeks++;

            continue;
        }
        
        while (true) {
            
            if (this->_allDaysInYear[this->endRel() - spaceAfterTxtInWeeks].isCommitable() == true)
                break;

            spaceAfterTxtInWeeks++;

            continue;
        }

        spaceBeforeTxtInWeeks /= this->DAYS_IN_WEEK;
        spaceAfterTxtInWeeks /= this->DAYS_IN_WEEK;

        int transform = spaceBeforeTxtInWeeks - spaceAfterTxtInWeeks;
        if (transform == 0)
            return;
        
        if (transform < 0)
            this->rotateRight(transform);
        if (transform > 0)
            this->rotateLeft(transform);
        
        return;
    }

    return;
}


void AllDays::rotateRight(int weeks) {

    if (weeks == 0)
        return;

    std::vector<bool> cms(
        abs(weeks * this->DAYS_IN_WEEK)
        )
        ;
    int cursor = 0;
    int idxCMs = 0;
    
    while (true) {
        
        if (cursor > this->_allDaysInYear.size() - 1)
            break;

        bool cm = this->_allDaysInYear[cursor].isCommitable();
        this->_allDaysInYear[cursor].setCommitable(cms[idxCMs]);
        cms[idxCMs] = cm;
        idxCMs = (idxCMs + 1) % cms.size();
        cursor++;

        continue;
    }
    
    return;
}


void AllDays::rotateLeft(int weeks) {

    if (weeks == 0)
        return;
    
    std::vector<bool> cms(
        abs(weeks * this->DAYS_IN_WEEK)
    )
    ;
    int cursor = this->_allDaysInYear.size() - 1;
    int idxCMs = 0;

    while (true) {
        
        if (cursor < 0)
            break;
        
        bool cm = this->_allDaysInYear[cursor].isCommitable();
        this->_allDaysInYear[cursor].setCommitable(cms[idxCMs]);
        cms[idxCMs] = cm;
        idxCMs = (idxCMs + 1) % cms.size();
        cursor--;

        continue;    
    }
    
    return;
}


void AllDays::commitEverything() {

    for (DayInformation di : this->_allDaysInYear) {

        if (di.isCommitable() == false)
            continue;

        if (this->makeCommitsInDifferentRepo == 1)
            di.gitCommit(this->minCommits, this->maxCommits, this->pathToDifferentRepo);
        else
            di.gitCommit(this->minCommits, this->maxCommits);

        break;
    }

    return;
}
