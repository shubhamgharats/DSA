#include <iostream>

// Define a macro named DEBUG
#define DEBUG

int main() {
    int x = 5, y = 10;
    int sum = x + y;

    // This block will only be compiled if DEBUG is defined
    #ifdef DEBUG
        std::cout << "[DEBUG] x = " << x << std::endl;
        std::cout << "[DEBUG] y = " << y << std::endl;
        std::cout << "[DEBUG] sum = " << sum << std::endl;
    #endif

    // Always compiled
    std::cout << "Sum: " << sum << std::endl;

    return 0;
}