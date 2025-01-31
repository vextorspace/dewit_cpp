#ifndef CONSOLEINPUT_H
#define CONSOLEINPUT_H
#include <string>


class ConsoleInput {
public:
    [[nodiscard]] std::string read_line();
};



#endif //CONSOLEINPUT_H
