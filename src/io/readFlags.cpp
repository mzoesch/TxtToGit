#include "readFlags.h"

std::vector<int> convertStringToVectorOfInts(
    std::string *values
    ) {
    
    if (values->empty())
        return std::vector<int>(-1);

    if (values->at(0) == '[')
        values->erase(0, 1);
    if (values->at(values->size() - 1) == ']')
        values->erase(values->size() - 1, 1);
    
    const double posOfFirstSep = values->find(", ");
    if (posOfFirstSep == OUT_OF_BOUNDS)
        return {
            std::stoi(*values)
            }
            ;
    
    int space = std::stoi(values->substr(0, posOfFirstSep));
    values = new std::string(values->substr(posOfFirstSep + 2));
    
    std::vector<int> spaceBetweenChars = {space};
    std::vector<int> secondVector = convertStringToVectorOfInts(values);
    spaceBetweenChars.insert(std::end(spaceBetweenChars), std::begin(secondVector), std::end(secondVector));

    return spaceBetweenChars;
}

void readFlags(
    int *year
    , int *first_day_of_week
    , bool *useMonospace
    , int *align
    , std::vector<char> *message
    , std::vector<int> *spaceBetweenChars
    , bool *cleanAfterExecution
    ) {

    std::ifstream file("./.flags");
    if (!file.is_open()) {
        throw std::runtime_error("Missing ./.flags file");
        return;
    }

    std::string currentLine;
    while (std::getline(file, currentLine)) {

        const double posOfEqualSign = currentLine.find("=");
        if (posOfEqualSign == OUT_OF_BOUNDS) {            
            throw std::runtime_error("Missing equalation in flags ./.flags");
            continue;
        }

        const std::string key = currentLine.substr(0, posOfEqualSign);
        std::string value = currentLine.substr(posOfEqualSign + 1);

        switch (key[0]) {
            case 'y':
                *year = std::stoi(value);
                break;
            case 'f':
                *first_day_of_week = std::stoi(value);
                break;
            case 'u':
                *useMonospace = std::stoi(value);
                break;
            case 'a':
                *align = std::stoi(value);
                break;
            case 'm':
                for (char c : value) message->push_back(c);
                break;
            case 's':
                *spaceBetweenChars = convertStringToVectorOfInts(&value);
                break;
            case 'c':
                *cleanAfterExecution = std::stoi(value);
                break;

            default:
                break;
        }        
    }

    return;
}
