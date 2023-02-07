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
        , &minNumberOfCommitsAtOneDay
        , &maxNumberOfCommitsAtOneDay
        , &makeCommitsInDifferentRepo
        , &pathToDifferentRepo
    )
    ;
    

    AllDays ad = AllDays(
        year
        , first_day_of_week
        , minNumberOfCommitsAtOneDay
        , maxNumberOfCommitsAtOneDay
        , makeCommitsInDifferentRepo
        , pathToDifferentRepo
        )
        ;
    
    for (int i = 0; i < message.size(); ++i) {
        ad.addChar(message[i], spaceBetweenChars[i], useMonospace);
    }
    ad.align(align);
    
    std::cout << "Preview (Year: " << year << "):\n";
    std::cout << ad.toCharPointer() << std::endl;
    std::cout << "$" << std::endl;

    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        std::ifstream f;
        f.open(".tmp.txt");

        if (!f.is_open()) {
            std::cout << "Could not read temporary config file." << std::endl;
            return EXIT_FAILURE;
        }

        std::string l;
        l = "";

        if (std::getline(f, l)) {
            
            if (l == "0")
                continue;

            if (l == "1") {
                f.close();
                break;
            }

            if (l == "-1") {
                f.close();
                std::cout << "Not committing. Aborting . . ." << std::endl;
                return EXIT_SUCCESS;
            }

            f.close();
            std::cout << l << "\nUnkown content in temporary config file." << std::endl;
            
            return EXIT_FAILURE;            
        }

        f.close();
        continue;
    }    

    std::cout << "Now commiting . . ." << std::endl;
    ad.commitEverything();

    return EXIT_SUCCESS;
}
