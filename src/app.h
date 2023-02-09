#ifndef APP_H
#define APP_H

#include "io/readFlags.h"
#include "ex/exs.h"
#include "chrs/chrs.h"
#include "chrs/allDays.h"

#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>

// ./.flags
int year = 0;
int first_day_of_week = 6;
bool useMonospace = true;
int align = 0;
std::vector<char> message;
std::vector<int> spaceBetweenChars;
bool cleanAfterExecution = true;
int minNumberOfCommitsAtOneDay = 1;
int maxNumberOfCommitsAtOneDay = 5;
int makeCommitsInDifferentRepo = 1;
std::string nameOfDifferentRepo;
int ignoreExistingGitRepo = 0;

// general
std::vector<DayInformation> allDaysInYear;
int beginRel = 0;
int endRel = 0;
int weeksToWork = 0;
std::string input;


int main(
    int argc
    , char const *argv[]
    )
    ;


#endif
