#ifndef CHRS_H
#define CHRS_H

#include <vector>
#include <unordered_map>


const std::unordered_map<char, std::vector<bool>> validChars = {
    

#pragma region Punctation I (0x20 - 0x2F)


    {
        ' ' // Space
        ,
        {
          false, false, false, false, false, false, false
        , false, false, false, false, false, false, false
        , false, false, false, false, false, false, false
        , false, false, false, false, false, false, false
        , false, false, false, false, false, false, false
        }
    }
    ,
    {
        '!'
        ,
        {
              true , true , true , true , true , false, true
        }
    }
    ,
    {
        '"'
        ,
        {
              true , true , false, false, false, false, false
            , false, false, false, false, false, false, false
            , true , true , false, false, false, false, false
        }
    }
    ,
    {
        '#'
        ,
        {
              false, false, true , false, true , false, false
            , false, true , true , true , true , true , false
            , false, false, true , false, true , false, false
            , false, true , true , true , true , true , false
            , false, false, true , false, true , false, false
        }
    }
    ,
    {
        '$'
        ,
        {
              false, true , true , true , false, true , false
            , false, true , false, true , false, true , false
            , true , true , true , true , true , true , true 
            , false, true , false, true , false, true , false
            , false, true , false, true , true , true , false
        }
    }
    ,
    {
        '%'
        ,
        {
          true , true , false, false, false, true , false
        , true , true , false, false, true , false, false
        , false, false, false, true , false, false, false
        , false, false, true , false, false, true , true 
        , false, true , false, false, false, true , true 
        }
    }
    ,
    {
        '&' 
        ,
        {
          false, true , true , false, true , true , false
        , true , false, false, true , false, false, true 
        , true , false, false, true , true , false, true 
        , true , false, true , false, false, true , false
        , false, true , false, false, true , false, true 
        }
    }
    ,
    {
        '\''
        ,
        {
              true , true , false, false, false, false, false
        }
    }
    ,
    {
        '('
        ,
        {
              false, true , true , true , true , true , false
            , true , false, false, false, false, false, true
            , true , false, false, false, false, false, true
            , true , false, false, false, false, false, true
        }
    }
    ,
    {
        ')'
        ,
        {
              true , false, false, false, false, false, true
            , true , false, false, false, false, false, true
            , true , false, false, false, false, false, true
            , false, true , true , true , true , true , false
        }
    }
    ,
    {
        '*'
        ,
        {
              false, true , false, true , false, false, false
            , false, false, true , false, false, false, false
            , false, true , false, true , false, false, false
        }
    }
    ,
    {
        '+'
        ,
        {
              false, false, false, true , false, false, false
            , false, false, false, true , false, false, false
            , false, true , true , true , true , true , false
            , false, false, false, true , false, false, false
            , false, false, false, true , false, false, false
        }
    }
    ,
    {
        ','
        ,
        {
              false, false, false, false, false, false, true
            , false, false, false, false, false, true , true 
        }
    }
    ,
    {
        '-'
        ,
        {
              false, false, false, true , false, false, false
            , false, false, false, true , false, false, false
            , false, false, false, true , false, false, false
            , false, false, false, true , false, false, false
            , false, false, false, true , false, false, false
        }
    }
    ,
    {
        '.'
        ,
        {
              false, false, false, false, false, false, true
        }
    }
    ,
    {
        '/'
        ,
        {
              false, false, false, false, false, false, true 
            , false, false, false, false, false, true , false
            , false, false, true , true , true , false, false
            , false, true , false, false, false, false, false
            , true , false, false, false, false, false, false
        }
    }
    ,

#pragma endregion Punctation I (0x21 - 0x2F)


#pragma region Numbers (0x30 - 0x39)


    {
        '0'
        ,
        {
              false, true , true , true , true , true , false
            , true , false, false, false, false, false, true 
            , true , false, false, false, false, false, true 
            , true , false, false, false, false, false, true 
            , false, true , true , true , true , true , false
        }
    }
    ,
    {
        '1'
        ,
        {
              false, false, true , false, false, false, true 
            , false, true , false, false, false, false, true 
            , true , true , true , true , true , true , true 
            , false, false, false, false, false, false, true 
            , false, false, false, false, false, false, true 
        }
    }
    ,
    {
        '2'
        ,
        {
              false, true , false, false, false, false, true 
            , true , false, false, false, false, true , true 
            , true , false, false, false, true , false, true 
            , true , false, false, true , false, false, true 
            , false, true , true , false, false, false, true 
        }
    }
    ,
    {
        '3'
        ,
        {
              true , false, false, false, false, false, true 
            , true , false, false, true , false, false, true 
            , true , false, false, true , false, false, true 
            , true , false, false, true , false, false, true 
            , false, true , true , false, true , true , false
        }
    }
    ,
    {
        '4'
        ,
        {
              false, false, false, true , false, false, false
            , false, false, true , true , false, false, false
            , false, true , false, true , false, false, false
            , true , true , true , true , true , true , true 
            , false, false, false, true , false, false, false
        }
    }
    ,
    {
        '5'
        ,
        {
              false, true , true , false, false, false, false
            , true , false, false, true , false, false, true 
            , true , false, false, true , false, false, true 
            , true , false, false, true , false, false, true 
            , false, false, false, false, true , true , false
        }
    }
    ,
    {
        '6'
        ,
        {
              false, true , true , true , true , true , false
            , true , false, false, true , false, false, true 
            , true , false, false, true , false, false, true 
            , true , false, false, true , false, false, true 
            , false, false, false, false, true , true , false
        }
    }
    ,
    {
        '7'
        ,
        {
              true , false, false, false, false, false, false
            , true , false, false, false, false, false, true 
            , true , false, false, false, false, true , false
            , true , false, false, false, true , false, false
            , true , true , true , true , false, false, false
        }
    }
    ,
    {
        '8'
        ,
        {
              false, true , true , false, true , true , false
            , true , false, false, true , false, false, true 
            , true , false, false, true , false, false, true 
            , true , false, false, true , false, false, true 
            , false, true , true , false, true , true , false
        }
    }
    ,
    {
        '9'
        ,
        {
              false, true , true , false, false, false, false
            , true , false, false, true , false, false, true 
            , true , false, false, true , false, false, true 
            , true , false, false, true , false, false, true 
            , false, true , true , true , true , true , false
        }
    }
    ,


#pragma endregion Numbers (0x30 - 0x39)


#pragma region Punctation II (0x3A - 0x40)


    {
        ':'
        ,
        {
              false, false, true , false, true , false, false
        }
    }
    ,
    {
        ';'
        ,
        {
              false, false, false, false, false, false, true
            , false, false, false, true , false, true , true
            , false, false, false, false, false, false, false
            , false, false, false, false, false, false, false
            , false, false, false, false, false, false, false
        }
    }
    ,
    {
        '<'
        ,
        {
              false, false, false, true , false, false, false
            , false, false, true , false, true , false, false
            , false, false, true , false, true , false, false
            , false, true , false, false, false, true , false
            , false, true , false, false, false, true , false
        }
    }
    ,
    {
        '='
        ,
        {
              false, false, true , false, true , false, false
            , false, false, true , false, true , false, false
            , false, false, true , false, true , false, false
            , false, false, true , false, true , false, false
            , false, false, true , false, true , false, false
        }
    }
    ,
    {
        '>'
        ,
        {
              false, true , false, false, false, true , false
            , false, true , false, false, false, true , false
            , false, false, true , false, true , false, false
            , false, false, true , false, true , false, false
            , false, false, false, true , false, false, false
        }
    }
    ,
    {
        '?'
        ,
        {
              false, true , false, false, false, false, false
            , true , false, false, false, false, false, false
            , true , false, false, true , true , false, true
            , true , false, false, true , false, false, false
            , false, true , true , false, false, false, false
        }
    }
    ,
    {
        '@'
        ,
        {
              true , true , true , true , true , true , true 
            , true , false, false, false, false, false, true 
            , true , false, true , true , true , false, true 
            , true , false, false, false, true , false, true 
            , true , true , true , true , true , false, true 
        }
    }
    ,


#pragma endregion Punctation II (0x3A - 0x40)


#pragma region UpperCase (0x41 - 0x5A)


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
    {
        'D'
        ,
        {
              true , true , true , true , true , true , true
            , true , false, false, false, false, false, true
            , true , false, false, false, false, false, true
            , true , false, false, false, false, false, true
            , false, true , true , true , true , true , false
        }
    }
    ,
    {
        'E'
        ,
        {
              true , true , true , true , true , true , true
            , true , false, false, true , false, false, true
            , true , false, false, true , false, false, true
            , true , false, false, true , false, false, true
            , true , false, false, false, false, false, true
        }
    }
    ,
    {
        'F'
        ,
        {
              true , true , true , true , true , true , true
            , true , false, false, true , false, false, false
            , true , false, false, true , false, false, false
            , true , false, false, true , false, false, false
            , true , false, false, false, false, false, false
        }
    }
    ,
    {
        'G'
        ,
        {
              false, true , true , true , true , true , false
            , true , false, false, false, false, false, true
            , true , false, false, false, false, false, true
            , true , false, false, true , false, false, true
            , false, true , false, true , true , true , false
        }
    }
    ,
    {
        'H'
        ,
        {
              true , true , true , true , true , true , true
            , false, false, false, true , false, false, false
            , false, false, false, true , false, false, false
            , false, false, false, true , false, false, false
            , true , true , true , true , true , true , true
        }
    }
    ,
    {
        'I'
        ,
        {
              true , false, false, false, false, false, true
            , true , false, false, false, false, false, true
            , true , true , true , true , true , true , true
            , true , false, false, false, false, false, true
            , true , false, false, false, false, false, true
        }
    }
    ,
    {
        'J'
        ,
        {
              true , false, false, false, false, true , false
            , true , false, false, false, false, false, true
            , true , false, false, false, false, false, true 
            , true , false, false, false, false, false, true 
            , true , true , true , true , true , true , false
        }
    }
    ,
    {
        'K'
        ,
        {
              true , true , true , true , true , true , true
            , false, false, false, true , false, false, false
            , false, false, true , false, true , false, false
            , false, true , false, false, false, true , false
            , true , false, false, false, false, false, true
        }
    }
    ,
    {
        'L'
        ,
        {
              true , true , true , true , true , true , true
            , false, false, false, false, false, false, true
            , false, false, false, false, false, false, true
            , false, false, false, false, false, false, true
            , false, false, false, false, false, false, true
        }
    }
    ,
    {
        'M'
        ,
        {
              true , true , true , true , true , true , true 
            , false, true , false, false, false, false, false
            , false, false, true , false, false, false, false
            , false, true , false, false, false, false, false
            , true , true , true , true , true , true , true 
        }
    }
    ,
    {
        'N'
        ,
        {
              true , true , true , true , true , true , true 
            , false, true , false, false, false, false, false
            , false, false, true , true , true , false, false
            , false, false, false, false, false, true , false
            , true , true , true , true , true , true , true 
        }
    }
    ,
    {
        'O'
        ,
        {
              false, true , true , true , true , true , false
            , true , false, false, false, false, false, true
            , true , false, false, false, false, false, true
            , true , false, false, false, false, false, true
            , false, true , true , true , true , true , false
        }
    }
    ,
    {
        'P'
        ,
        {
              true , true , true , true , true , true , true
            , true , false, false, true , false, false, false
            , true , false, false, true , false, false, false
            , true , false, false, true , false, false, false
            , false, true , true , false, false, false, false
        }
    }
    ,
    {
        'Q'
        ,
        {
              false, true , true , true , true , true , false
            , true , false, false, false, false, false, true
            , true , false, false, false, true , false, true
            , true , false, false, false, false, true , true
            , false, true , true , true , true , true , true 
        }
    }
    ,
    {
        'R'
        ,
        {
              true , true , true , true , true , true , true
            , true , false, false, true , false, false, false
            , true , false, false, true , false, false, false
            , true , false, false, true , true , false, false
            , false, true , true , false, false, true , true 
        }
    }
    ,
    {
        'S'
        ,
        {
              false, true , true , false, false, false, true 
            , true , false, false, true , false, false, true
            , true , false, false, true , false, false, true
            , true , false, false, true , false, false, true
            , true , false, false, false, true , true , false
            }
    }
    ,
    {
        'T'
        ,
        {
              true , false, false, false, false, false, false
            , true , false, false, false, false, false, false
            , true , true , true , true , true , true , true
            , true , false, false, false, false, false, false
            , true , false, false, false, false, false, false
        }
    }
    ,
    {
        'U'
        ,
        {
              true , true , true , true , true , true , false
            , false, false, false, false, false, false, true
            , false, false, false, false, false, false, true
            , false, false, false, false, false, false, true
            , true , true , true , true , true , true , false
        }
    }
    ,
    {
        'V'
        ,
        {
              true , true , true , true , true , false, false
            , false, false, false, false, false, true , false
            , false, false, false, false, false, false, true
            , false, false, false, false, false, true , false
            , true , true , true , true , true , false, false
        }
    }
    ,
    {
        'W'
        ,
        {
              true , true , true , true , true , true , true 
            , false, false, false, false, false, true , false
            , false, false, false, false, true , false, false 
            , false, false, false, false, false, true , false
            , true , true , true , true , true , true , true 
        }
    }
    ,
    {
        'X'
        ,
        {
              true , false, false, false, false, false, true
            , false, true , true , false, true , true , false
            , false, false, false, true , false, false, false
            , false, true , true , false, true , true , false
            , true , false, false, false, false, false, true
        }
    }
    ,
    {
        'Y'
        ,
        {
              true , false, false, false, false, false, false
            , false, true , true , false, false, false, false
            , false, false, false, true , true , true , true
            , false, true , true , false, false, false, false
            , true , false, false, false, false, false, false
        }
    }
    ,
    {
        'Z'
        ,
        {
              true , false, false, false, false, true , true
            , true , false, false, false, true , false, true
            , true , false, false, true , false, false, true
            , true , false, true , false, false, false, true
            , true , true , false, false, false, false, true
        }
    }
    ,


#pragma endregion UpperCase (0x41 - 0x5A)


#pragma region Punctuation III (0x5B - 0x60)


    {
        '['
        ,
        {
              true , true , true , true , true , true , true
            , true , false, false, false, false, false, true
            , true , false, false, false, false, false, true
            , true , false, false, false, false, false, true
            , true , false, false, false, false, false, true
        }
    }
    ,
    {
        '\\'
        ,
        {
              true , false, false, false, false, false, false
            , false, true, false, false, false, false, false
            , false, false, true , true , true , false, false
            , false, false, false, false, false, true , false
            , false, false, false, false, false, false, true
        }
    }
    ,
    {
        ']'
        ,
        {
              true , false, false, false, false, false, true
            , true , false, false, false, false, false, true
            , true , false, false, false, false, false, true
            , true , false, false, false, false, false, true
            , true , true , true , true , true , true , true
        }
    }
    ,
    {
        '^'
        ,
        {
              false, false, true , false, false, false, false
            , false, true , false, false, false, false, false
            , true , false, false, false, false, false, false
            , false, true , false, false, false, false, false
            , false, false, true , false, false, false, false
        }
    }
    ,
    {
        '_'
        ,
        {
              false, false, false, false, false, false, true
            , false, false, false, false, false, false, true
            , false, false, false, false, false, false, true
            , false, false, false, false, false, false, true
            , false, false, false, false, false, false, true
        }
    }
    ,
    {
        '`'
        ,
        {
              true , false, false, false, false, false, false
            , false, true , false, false, false, false, false
            , false, false, true , false, false, false, false
        }
    }
    ,


#pragma endregion Punctuation III (0x5B - 0x60)


#pragma region LowerCase (0x61 - 0x7A)


    {
        'a'
        ,
        {
              false, false, false, false, false, true , false
            , false, false, true , false, true , false, true 
            , false, false, true , false, true , false, true 
            , false, false, true , false, true , false, true 
            , false, false, false, true , true , true , true 
        }
    }
    ,
    {
        'b'
        ,
        {
              false, true , true , true , true , true , true 
            , false, false, false, false, true , false, true 
            , false, false, false, false, true , false, true 
            , false, false, false, false, true , false, true 
            , false, false, false, false, false, true , false
        }
    }
    ,
    {
        'c'
        ,
        {
              false, false, false, false, true, true , false
            , false, false, false, true, false, false, true 
            , false, false, false, true, false, false, true 
            , false, false, false, true, false, false, true 
            , false, false, false, true, false, false, true
        }
    }
    ,
    {
        'd'
        ,
        {
              false, false, false, false, false, true , false
            , false, false, false, false, true , false, true 
            , false, false, false, false, true , false, true 
            , false, false, false, false, true , false, true 
            , false, true , true , true , true , true , true
        }
    }
    ,
    {
        'e'
        ,
        {
              false, false, false, true , true , true , false
            , false, false, true , false, true , false, true 
            , false, false, true , false, true , false, true 
            , false, false, true , false, true , false, true 
            , false, false, false, true , false, false, true
        }
    }
    ,
    {
        'f'
        ,
        {
                false, false, false, false, true , false, false
              , false, true , true , true , true , true , true 
              , false, true , false, false, true , false, false
        }
    }
    ,
    {
        'g'
        ,
        {
              false, false, false, false, true , false, false
            , false, false, false, true , false, true , false 
            , false, false, false, true , false, true , true 
            , false, false, false, true , false, true , true
            , false, false, false, true , true , true , false
        }
    }
    ,
    {
        'h'
        ,
        {
              false, true , true , true , true , true , true 
            , false, false, false, false, true , false, false
            , false, false, false, false, true , false, false
            , false, false, false, false, true , false, false
            , false, false, false, false, false, true , true
        }
    }
    ,
    {
        'i'
        ,
        {
              false, false, true , false, true , true , true 
        }
    }
    ,
    {
        'j'
        ,
        {
              false, false, false, false, false, false, true 
            , false, false, true , false, true , true , false
        }
    }
    ,
    {
        'k'
        ,
        {
              false, false, true , true , true , true , true 
            , false, false, false, false, false, true , false
            , false, false, false, false, true , false, true
        }
    }
    ,
    {
        'l'
        ,
        {
              true , false, false, false, false, false, false
            , true , true , true , true , true , true , false 
            , false, false, false, false, false, false, true 
            , false, false, false, false, false, false, true
        }
    }
    ,
    {
        'm'
        ,
        {
              false, false, false, false, true , true , true
            , false, false, false, true , false, false, false
            , false, false, false, false, true , true , true
            , false, false, false, true , false, false, false
            , false, false, false, false, true , true , true
        }
    }
    ,
    {
        'n'
        ,
        {
              false, false, false, false, true , true , true
            , false, false, false, true , false, false, false
            , false, false, false, true , false, false, false
            , false, false, false, true , false, false, false
            , false, false, false, false, true , true , true
        }
    }
    ,
    {
        'o'
        ,
        {
              false, false, false, true , true , true , false
            , false, false, true , false, false, false, true 
            , false, false, true , false, false, false, true 
            , false, false, true , false, false, false, true 
            , false, false, false, true , true , true , false
        }
    }
    ,
    {
        'p'
        ,
        {
              false, false, false, true , true , true , true 
            , false, false, true , false, false, true , false 
            , false, false, true , false, false, true , false 
            , false, false, true , false, false, true , false 
            , false, false, false, true , true , false, false
        }
    }
    ,
    {
        'q'
        ,
        {
              false, false, false, true , true , false, false
            , false, false, true , false, false, true , false 
            , false, false, true , false, false, true , false 
            , false, false, true , false, false, true , false 
            , false, false, true , false, false, true , false
            , false, false, false, true , true , true , true  
        }
    }
    ,
    {
        'r'
        ,
        {
              false, false, false, false, true , true , true 
            , false, false, false, true , false, false, false
            , false, false, false, true , false, false, false
        }
    }
    ,
    {
        's'
        ,
        {
              false, false, false, true , false, false, true 
            , false, false, true , false, true , false, true 
            , false, false, true , false, true , false, true 
            , false, false, true , false, false, true , false 
        }
    }
    ,
    {
        't'
        ,
        {
              false, false, false, false, true , false, false
            , false, true , true , true , true , true , true 
            , false, false, false, false, true , false, true
        }
    }
    ,
    {
        'u'
        ,
        {
              false, false, false, true , true , true , true
            , false, false, false, false, false, false, true 
            , false, false, false, false, false, false, true 
            , false, false, false, false, false, false, true 
            , false, false, false, true , true , true , true
        }
    }
    ,
    {
        'v'
        ,
        {
              false, false, false, true , true , false, false
            , false, false, false, false, false, true , false 
            , false, false, false, false, false, false, true 
            , false, false, false, false, false, true , false 
            , false, false, false, true , true , false, false
        }
    }
    ,
    {
        'w'
        ,
        {
              false, false, false, true , true , true , false
            , false, false, false, false, false, false, true  
            , false, false, false, false, false, true , false
            , false, false, false, false, false, false, true  
            , false, false, false, true , true , true , false
        }
    }
    ,
    {
        'x'
        ,
        {
              false, false, false, false, true , false, true  
            , false, false, false, false, false, true , false
            , false, false, false, false, true , false, true  
        }
    }
    ,
    {
        'y'
        ,
        {
              false, false, false, true , false, false, true
            , false, false, false, false, true , false, true 
            , false, false, false, false, false, true , true 
            , false, false, false, false, true , false, false  
            , false, false, false, true , false, false, false 
        }
    }
    ,
    {
        'z'
        ,
        {
              false, false, true , false, false, true , true 
            , false, false, true , false, true , false, true  
            , false, false, true , false, true , false, true  
            , false, false, true , true , false, false, true  
        }
    }
    ,


#pragma endregion LowerCase (0x61 - 0x7A)


#pragma region Punctation IV (0x7B - 0x7E)

    {
        '{'
        ,
        {
              false, false, false, true , false, false, false
            , false, false, true , true , true , false, false
            , false, true , false, false, false, true , false
            , true , false, false, false, false, false, true 
            , true , false, false, false, false, false, true 
        }
    }
    ,
    {
        '|'
        ,
        {
            true , true , true , true , true , true , true
        }
    }
    ,
    {
        '}'
        ,
        {
              true , false, false, false, false, false, true 
            , true , false, false, false, false, false, true 
            , false, true , false, false, false, true , false
            , false, false, true , true , true , false, false
            , false, false, false, true , false, false, false
        }
    }
    ,
    {
        '~'
        ,
        {
              false, true , false, false, false, false, false
            , true , false, false, false, false, false, false
            , true , true , false, false, false, false, false
            , false, true, false, false, false, false, false
            , true , false, false, false, false, false, false
        }
    }
    ,


#pragma endregion Punctation IV (0x7B - 0x7E)


}
;

#endif
