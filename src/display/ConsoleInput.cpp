#include "ConsoleInput.h"

#include <iostream>

std::string ConsoleInput::read_line() {
    std::string input;
    std::getline(std::cin, input);
    return input;
}
