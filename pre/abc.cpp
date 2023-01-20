#include <chrono>
#include <iostream>

int main() {

    
    auto now = std::chrono::high_resolution_clock::now();
    
    std::cout << "now: " << now.time_since_epoch().count() << std::endl;

}
