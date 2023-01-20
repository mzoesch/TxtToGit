#ifndef COMMITDAY_H
#define COMMITDAY_H

#include <random>

class CommitDay {

    CommitDay(
        char day
        , bool commit = false
        , int minRange=1
        , int maxRange=1
    )
    ;
    ~CommitDay();

private:

    char day;
    int numOfCommits;

private:

    int generateCommits(int minRange, int maxRange);

public:

    void Commit();
    // TODO: RETURN GEN AND LIST ??

}
;

#endif
