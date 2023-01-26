#include "app.h"


int main(int argc, char const *argv[]) {
    
    readFlags(
        &year
        , &first_day_of_week
        , &useMonospace
        , &align
        , &message
        , &spaceBetweenChars
        , &cleanAfterExecution
    )
    ;

    std::vector<DayInformation> allDaysInYear = getAllDaysInYear(year);

    try {
        beginRel = removeInsufficientDaysAtBeginning(allDaysInYear, first_day_of_week);
        endRel = removeInsufficientDaysAtEnd(allDaysInYear, first_day_of_week);
    
    } catch (FirstDayOfWeekException *e) {
        std::cout << e->what() << std::endl;
        
        return 1;
    }
    
    if ((endRel - beginRel + 1) % 7 != 0)
        throw new InvalidWeeksToWorkException("The number of days in the year is not divisible by 7.");
    // This MUST always return an integer
    weeksToWork = (endRel - beginRel + 1) / 7; 
    
    
    // bool *a;
    // a = getCharAsArray('A');


    return 0;
}
