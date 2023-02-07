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
    , int *minNumberOfCommitsAtOneDay
    , int *maxNumberOfCommitsAtOneDay
    , int *makeCommitsInDifferentRepo
    , std::string *pathToDifferentRepo
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

        if (strcmp(key.c_str(), "year") == 0) {
            *year = std::stoi(value);
            continue;
        }
        if (strcmp(key.c_str(), "firstDayOfWeek") == 0) {
            *first_day_of_week = std::stoi(value);
            continue;
        }
        if (strcmp(key.c_str(), "useMonospace") == 0) {
            *useMonospace = std::stoi(value);
            continue;
        }
        if (strcmp(key.c_str(), "align") == 0) {
            *align = std::stoi(value);
            continue;
        }
        if (strcmp(key.c_str(), "message") == 0) {
            for (char c : value) message->push_back(c);
            continue;
        }
        if (strcmp(key.c_str(), "spacesBetweenChars") == 0) {
            *spaceBetweenChars = convertStringToVectorOfInts(&value);
            continue;
        }
        if (strcmp(key.c_str(), "cleanAfterExecution") == 0) {
            *cleanAfterExecution = std::stoi(value);
            continue;
        }
        if (strcmp(key.c_str(), "minNumberOfCommitsAtOneDay") == 0) {
            *minNumberOfCommitsAtOneDay = std::stoi(value);
            continue;
        }
        if (strcmp(key.c_str(), "maxNumberOfCommitsAtOneDay") == 0) {
            *maxNumberOfCommitsAtOneDay = std::stoi(value);
            continue;
        }
        if (strcmp(key.c_str(), "makeCommitsInDifferentRepo") == 0) {
            *makeCommitsInDifferentRepo = std::stoi(value);
            continue;
        }
        if (strcmp(key.c_str(), "pathToDifferentRepo") == 0) {
            *pathToDifferentRepo = value;
            continue;
        }
        
        break;      
    }

    return;
}
