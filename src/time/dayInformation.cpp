#include "dayInformation.h"
#include <iostream>

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


tDateHolder DayInformation::getDate() {

        tDateHolder tdh = tDateHolder();

        tdh.day = this->day;
        tdh.month = this->month;
        tdh.year = this->year;

        return tdh;
}
;


void DayInformation::gitCommit(int min, int max) {
    std::cout << "Commits in same repo" << std::endl;

    std::cout << exec("pwd") << std::endl;

    // int numCommits = min + (rand() % (max - min + 1));
    // std::cout << "numCommits: " << numCommits << std::endl;

    return;
}
;


void DayInformation::gitCommit(int min, int max, std::string pathToDifferentRepo) {
    std::cout << "Commits in an other repo" << std::endl;

    std::cout << exec("pwd") << std::endl;

    return;
}
;
