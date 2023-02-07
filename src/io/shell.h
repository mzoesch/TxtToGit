#ifndef SHELL_H
#define SHELL_H

#include <string>
#include <array>
#include <stdexcept>
#include <memory>
#include <iostream>
#include <cstdio>

static std::string exec(const char *cmd) {

    std::array<char, 128> buffer;
    std::string output;

    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    
    if (!pipe)
        throw std::runtime_error("Fatal error:\npopen() failed!");
    
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        output +=buffer.data();

        continue;
    }

    return output;
}

#endif
