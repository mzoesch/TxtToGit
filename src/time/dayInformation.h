#ifndef DAY_INFORMATION_H
#define DAY_INFORMATION_H

#include "tDateHolder.h"
#include "../io/shell.h"

#include <filesystem>
#include <ctime>
#include <string>
#include <dirent.h>
#include <fstream>
#include <errno.h>
#include <sstream>
#include <iostream>


const int timeStandard [] = {
    0       // second
    , 0     // minute
    , 0     // hour
    , 0     // day (1-based)
    , 0     // month (0-based)
    , -1900 // year (since 1900)
}
;


class DayInformation {

public:

    DayInformation(
        int year
        , int month
        , int day
    )
    ;
    ~DayInformation();

private:

    int year;
    int month;
    int day;
    bool commit;
    int _dayOfWeek;

    const std::string andGate = "&&";
    const std::string space = " ";
    const std::string gitAdd = "git add";
    const std::string gitC = "git commit";
    const std::string gitCommitFalgMsg = "-m";
    const std::string gitCommitFlagDate = "--date";
    const std::string qMarks = "\"";
    const std::string minus = "-";
    const std::string col = ":";
    const std::string goToHome = "cd ~";
    const std::string goTo = "cd";
    const std::string pwd = "pwd";

private:

    int calculateDayOfWeek();
    std::string getISO8601(int s); // s into the day

public:

    bool isCommitable();
    void setCommitable(bool commit);
    int dayOfWeek() const { return this->_dayOfWeek; }
    int getDay() const { return this->day; }
    std::string getDate() const {
        return std::to_string(this->day) + " " + std::to_string(this->month) + " " + std::to_string(this->year);
    }
    tDateHolder getDate();
    void gitCommit(
        int min
        , int max
        , std::string changeFile
        )
        ;
    void gitCommit(
    int min
    , int max
    , std::string pathToDifferentRepo
    , std::string changeFile
    )
    ;
    
}
;

#endif
