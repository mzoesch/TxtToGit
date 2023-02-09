#ifndef READFLAGS_H
#define READFLAGS_H

#include <vector>
#include <fstream>
#include <iostream>
#include <string>

const double OUT_OF_BOUNDS = std::string::npos; // 18446744073709551615

std::vector<int> convertStringToVectorOfInts(
    std::string *value
    )
    ;

void readFlags(
    int *year
    , int *first_day_of_week
    , bool *useMonospace
    , int *align
    , std::vector<char> *message
    , std::vector<int> *spaceBetweenChars
    , bool *cleanAfterExecution
    , int *minNumberOfCommitsAtOneDay
    , int *maxNumberOfCommitsAtOneDay
    , int *makeCommitsInDifferentRepo
    , std::string *nameOfDifferentRepo
    , int *ignoreExistingGitRepo
    )
    ;

#endif
