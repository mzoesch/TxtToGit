#ifndef APP_H
#define APP_H

#include "io/readFlags.h"
#include "time/timeStuff.h"
#include "ex/exs.h"
#include "chrs/chrs.h"

#include <iostream>
#include <vector>


// ./.flags
int year = 0;
int first_day_of_week = 6;
bool useMonospace = true;
int align = 0;
std::vector<char> message;
std::vector<int> spaceBetweenChars;
bool cleanAfterExecution = true;

// general
int beginRel = 0;
int endRel = 0;
int weeksToWork = 0;

int main(
    int argc
    , char const *argv[]
    )
    ;

#endif
