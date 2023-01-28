#include "dayInformation.h"

DayInformation::DayInformation(
    int year
    , int month
    , int day
) {

    this->year = year;
    this->month = month;
    this->day = day;
    this->commit = false;

    this->_dayOfWeek = this->calculateDayOfWeek();

    return;
}
;

int DayInformation::calculateDayOfWeek() {

    // For more info see the header for this file
    std::tm mark = {
        0
        , 0
        , 0
        , this->day
        , this->month
        , this->year - 1900
    }
    ;

    std::time_t t = std::mktime(&mark);
    const std::tm *tOut = std::localtime(&t);

    // Sunday == 0, Monday == 1, and so on . . .
    return tOut->tm_wday;
}


bool DayInformation::isCommitable() {
    return this->commit;
}

void DayInformation::setCommitable(bool commit) {
    this->commit = commit;
}
;


DayInformation::~DayInformation() {
    // TODO: Auto-generated destructor stub

    return;
}
;
