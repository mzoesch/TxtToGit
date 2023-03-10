#ifndef ALL_DAYS_H
#define ALL_DAYS_H

#include "chrs.h"
#include "../ex/exs.h"
#include "../time/dayInformation.h"
#include "../time/timeStuff.h"

#include <stdlib.h>
#include <string>


const int HEIGHT = 7;
const int MONO_WIDTH = 5;


class AllDays {

public:

    AllDays(
        int year
        , int firstDayOfWeek
        , int minCommits
        , int maxCommits
        , int makeCommitsInDifferentRepo
        , std::string nameOfDifferentRepo
        , int ignoreExistingGitRepo
    )
    ;
    ~AllDays();

private:
    
    const static char INSUFFICIENT = 'X';
    const static char IS_COMMIT = '@';
    const static char IS_NOT_COMMIT = '.';
    const static char NEW_LINE = '\n';

    const static int MONOSPACE_SIZE = 35;
    const static int DAYS_IN_WEEK = 7;

    const std::string pwd = "pwd";
    const std::string space = " ";
    const std::string goToHome = "cd ~";
    const std::string mkdir = "mkdir";
    const std::string initGit = "git init";
    const std::string addGit = "git add";
    const std::string andGate = "&&";
    const std::string createChangeFile = "touch";
    const std::string extForChangeFile = ".txt";
    const std::string goTo = "cd";
    std::string changeFile;
    const std::string touch = "touch";
    const std::string README = "README.md";
    const std::string gitHubLink = "https://www.github.com/mzoesch/TxtToGit";
    const std::string author = "https://www.github.com/mzoesch";

    
    int year;
    int firstDayOfWeek;
    int _blockedDays;
    int _usableDays;
    int _beginRel; // True index
    int _endRel; // True index
    int cursor;
    int minCommits;
    int maxCommits;
    int makeCommitsInDifferentRepo;
    std::string nameOfDifferentRepo;
    std::vector<DayInformation> _allDaysInYear;
    int ignoreExistingGitRepo;

private:

    int blockedDays() const { return this->_blockedDays; }
    int usableDays() const { return this->_usableDays; }
    int weeksToWork() const { return (this->endRel() - this->beginRel() + 1) / HEIGHT; }
    int beginRel() const { return this->_beginRel; }
    int endRel() const { return this->_endRel; }
    int addBlockedDays(int days);
    int weeksToFillUpInMonospace(int days) const { return (this->MONOSPACE_SIZE - days) / this->DAYS_IN_WEEK; }
    bool charIsValid(char c);
    bool workableBoundsInYear(int x);
    void rotateRight(int weeks);
    void rotateLeft(int weeks);
    void prepareGitRepo();
    void deleteOldRepo();
    void createREADME(
        std::__fs::filesystem::path pathToREADME
    )
    ;
    
public:

    void addChar(
        char c
        , int space
        , bool useMonospace
        )
        ;
    void align(int n);
    void commitEverything();
    const char *toCharPointer();

}
;

#endif
