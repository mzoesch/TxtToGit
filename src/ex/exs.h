#ifndef EX_H
#define EX_H

#include <exception>
#include <string>


class FirstDayOfWeekException : public std::exception {

private:
    
    const char *message;

public:
    
    FirstDayOfWeekException(const char *message) : message(message) {}

    const char *what() const throw() {
        
        // FIXED by static:
        // Address of stack memory associated with local variable 'msg' returned
        static std::string msg = "Fatal Error:\n";
        msg += message;
        return msg.c_str();
    }

}
;


class InvalidWeeksToWorkException : public std::exception {

private:
    
    const char *message;

public:

    InvalidWeeksToWorkException(const char *message) : message(message) {}

    const char *what() const throw() {

        static std::string msg = "Fatal Error:\n";
        msg += message;
        return msg.c_str();
    }

}
;


class UnknownCharException : public std::exception {

private:
    
    const char *message;

public:

    UnknownCharException(const char *message) : message(message) {}

    const char *what() const throw() {

        static std::string msg = "Fatal Error:\nUnknown char: ";        
        msg += message;
        return msg.c_str();
    }

}
;


class NotEnoughSpaceToDisplayMessageException : public std::exception {

private:
    
    const char *message;

public:

    NotEnoughSpaceToDisplayMessageException(const char *message) : message(message) {}

    const char *what() const throw() {

        static std::string msg = "Fatal Error: You need to shorten the message.\nFailed at char: ";
        msg += message;
        return msg.c_str();
    }

}
;

#endif
