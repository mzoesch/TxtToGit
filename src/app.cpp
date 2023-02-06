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
    

    AllDays ad = AllDays(
        year
        , first_day_of_week
        )
        ;
    
    for (int i = 0; i < message.size(); ++i) {
        ad.addChar(message[i], spaceBetweenChars[i], useMonospace);
    }
    ad.align(align);
    
    std::cout << ad.toCharPointer() << std::endl;

    return 0;
}
