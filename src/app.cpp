#include "app.h"

int main(int argc, char const *argv[]) {
    
    int year = 0;
    int first_day_of_week = 6;
    bool useMonospace = true;
    int align = 0;
    std::vector<char> message;
    std::vector<int> spaceBetweenChars;
    bool cleanAfterExecution = true;

    
    readFlags(
        &year
        , &first_day_of_week
        , &useMonospace
        , &align
        , &message
        , &spaceBetweenChars
        , &cleanAfterExecution
    );

    return 0;
}
