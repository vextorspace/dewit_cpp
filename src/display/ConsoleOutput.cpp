
#include "ConsoleOutput.h"

#include <iostream>
#include <ostream>
#include <string>

void ConsoleOutput::write_line(const std::string &line) {
    std::cout << line << std::endl;
}
