#ifndef CHRS_H
#define CHRS_H

#include <vector>
#include <unordered_map>


const std::unordered_map<char, std::vector<bool>> validChars = {
    
#pragma region UpperCase

    {
        'A'
        ,
        {
              false, false, true , true , true , true , true
            , false, true , false, true , false, false, false
            , true , false, false, true , false, false, false
            , false, true , false, true , false, false, false
            , false, false, true , true , true , true , true

        }

    }
    ,
    {
        'B'
        ,
        {
              true , true , true , true , true , true , true
            , true , false, false, true , false, false, true
            , true , false, false, true , false, false, true
            , true , false, false, true , false, false, true
            , false, true , true , true , true , true , false
        }
    }
    ,
    {
        'C'
        ,
        {
              false, true , true , true , true , true , false
            , true , false, false, false, false, false, true
            , true , false, false, false, false, false, true
            , true , false, false, false, false, false, true
            , false, true , false, false, false, true , false
        }
    }
    ,

#pragma endregion UpperCase

#pragma region Punctuation

    {
        '!'
        ,
        {
              true , true , true , true , true , false, true
        }
    }
    ,

#pragma endregion Punctuation

}
;

#endif
