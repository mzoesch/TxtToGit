#include "dayInformation.h"


DayInformation::DayInformation(
    int year
    , int month
    , int day
) {

    this->year = year;
    this->month = month;
    this->day = day;
    this->commit = false;

    this->_dayOfWeek = this->calculateDayOfWeek();

    return;
}


int DayInformation::calculateDayOfWeek() {

    // For more info see the header for this file
    std::tm mark = {
        0
        , 0
        , 0
        , this->day
        , this->month
        , this->year - 1900
    }
    ;

    std::time_t t = std::mktime(&mark);
    const std::tm *tOut = std::localtime(&t);

    // Sunday == 0, Monday == 1, and so on . . .
    return tOut->tm_wday;
}


bool DayInformation::isCommitable() {
    return this->commit;
}


void DayInformation::setCommitable(bool commit) {
    this->commit = commit;
}


DayInformation::~DayInformation() {
    // TODO: Auto-generated destructor stub

    return;
}


tDateHolder DayInformation::getDate() {

        tDateHolder tdh = tDateHolder();

        tdh.day = this->day;
        tdh.month = this->month;
        tdh.year = this->year;

        return tdh;
}
;


void DayInformation::gitCommit(
    int min
    , int max
    , std::string changeFile
    ) {
    
    std::string s = exec(this->pwd.c_str());

    gitCommit(
        min
        , max
        , s
        , changeFile
    )
    ;

    return;
}


void DayInformation::gitCommit(
    int min
    , int max
    , std::string pathToDifferentRepo
    , std::string changeFile
    ) {

    int numCommits = min + (rand() % (max - min + 1));
    std::__fs::filesystem::path p = pathToDifferentRepo;
    std::__fs::filesystem::path pathToWrite = p;
    pathToWrite.append(changeFile);

    for (int i = 0; i < numCommits; i++) {

        std::string s;
        s = "Commit on: ";
        s.append(std::to_string(this->year));
        s.append(std::to_string(this->month));
        s.append(std::to_string(this->day));
        s += "\nCommit #: ";
        s.append(std::to_string(i));

        std::ofstream f;
        f.open(
            pathToWrite, std::ofstream::out
            | std::ofstream::trunc
            )
            ;
        
        if (!f.is_open()) {
            f.close();
            throw std::runtime_error("Fatal Error:\nCould not write to change-file.");
            return;
        }

        f << s;
        f.close();

        std::string prepareExec = "";

        prepareExec.append(this->goToHome);

        prepareExec.append(this->space);
        prepareExec.append(this->andGate);
        prepareExec.append(this->space);

        prepareExec.append(this->goTo);
        prepareExec.append(this->space);
        prepareExec.append(p.string());

        prepareExec.append(this->space);
        prepareExec.append(this->andGate);
        prepareExec.append(this->space);

        prepareExec.append(this->gitAdd);
        prepareExec.append(this->space);
        prepareExec.append(changeFile);

        prepareExec.append(this->space);
        prepareExec.append(this->andGate);
        prepareExec.append(this->space);

        prepareExec.append(this->gitC);
        prepareExec.append(this->space);
        
        prepareExec.append(this->gitCommitFalgMsg);
        prepareExec.append(this->space);
        prepareExec.append(this->qMarks);
        prepareExec.append(this->getISO8601(i));
        prepareExec.append(this->qMarks);
        prepareExec.append(this->space);
        
        prepareExec.append(this->gitCommitFlagDate);
        prepareExec.append(this->space);
        prepareExec.append(this->qMarks);
        prepareExec.append(this->getISO8601(i));
        prepareExec.append(this->qMarks);

        std::cout << prepareExec << " . . . ";        
        exec(prepareExec.c_str());
        std::cout << "ok\n";
    
        continue;
    }

    return;
}
;


std::string DayInformation::getISO8601(
    int s
) {

    int m = 0;
    int h = 0;

    while (s >= 60) {

        s -= 60;
        m++;

        if (m >= 60) {
            m -= 60;
            h++;

            if (h >= 24) {
                throw std::runtime_error("Exceeding time in one day.");
            }
        }

        continue;
    }

    std::stringstream ssS;
    ssS << std::setw(2) << std::setfill('0') << s;
    std::stringstream ssM;
    ssM << std::setw(2) << std::setfill('0') << m;
    std::stringstream ssH;
    ssH << std::setw(2) << std::setfill('0') << h;

    std::string ISO = "";
    ISO.append(std::to_string(this->year));
    ISO.append(this->minus);
    ISO.append(std::to_string(this->month + 1)); // ISO not zero based
    ISO.append(this->minus);
    ISO.append(std::to_string(this->day));
    ISO.append(this->space);
    ISO.append(ssH.str());
    ISO.append(this->col);
    ISO.append(ssM.str());
    ISO.append(this->col);
    ISO.append(ssS.str());

    return ISO;
}
