#ifndef CHRS_H
#define CHRS_H

#include <vector>
#include <map>


const std::map<char, std::vector<bool>> validChars = {
    {
        'A'
        ,
        {
              false, false, true , false, false
            , false, true , false, true , false
            , true , false, false, false, true
            , true , false, false, false, true
            , true , true , true , true , true
            , true , false, false, false, true
            , true , false, false, false, true
        }

    }
    ,
    {
        'B'
        ,
        {
              true , true , true , true , false
            , true , false, false, false, true
            , true , false, false, false, true
            , true , true , true , true , false
            , true , false, false, false, true
            , true , false, false, false, true
            , true , true , true , true , false
        }
    }
    ,
    {
        'C'
        ,
        {
              false, true , true , true , false
            , true , false, false, false, true
            , true , false, false, false, false
            , true , false, false, false, false
            , true , false, false, false, false
            , true , false, false, false, true
            , false, true , true , true , false
        }
    }
}
;

#endif
