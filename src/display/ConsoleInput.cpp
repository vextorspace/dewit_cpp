#include "ConsoleInput.h"

#include <iostream>

std::string ConsoleInput::read_line() {
    std::string input;
    std::cin >> input;
    return input;
}
