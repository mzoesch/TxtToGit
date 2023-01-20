#include "commitDay.h"

CommitDay::CommitDay(
    char day
    , bool commit
    , int minRange
    , int maxRange
) {

    this->day = day;
    this->numOfCommits = commit ? generateCommits(minRange, maxRange) : 0;

}
;

int CommitDay::generateCommits(int minRange, int maxRange) {
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(minRange, maxRange);
    
    return distr(gen);
}

void CommitDay::Commit() {
    // TODO Auto-generated destructor stub

    return;
}

CommitDay::~CommitDay() {
    // TODO Auto-generated destructor stub
}
