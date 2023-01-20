#ifndef EXEPTIONS_H
#define EXEPTIONS_H

class FailedToReadFlagsException : public std:: exception {

private:
    
    const char *message;

public:

    FailedToReadFlagsException(const char *message) : message(message) {}

    const char *what() const throw() {
        return message;
    }
}
;

#endif
