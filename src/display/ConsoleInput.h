#ifndef CONSOLEINPUT_H
#define CONSOLEINPUT_H
#include <string>


class ConsoleInput {
public:
    ConsoleInput() = default;
    ~ConsoleInput() = default;

    [[nodiscard]] std::string read_line();
};



#endif //CONSOLEINPUT_H
