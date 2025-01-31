#ifndef CONSOLEINPUT_H
#define CONSOLEINPUT_H
#include <string>
#include "Input.h"

class ConsoleInput : public Input {
public:
    [[nodiscard]] std::string read_line() override;
};



#endif //CONSOLEINPUT_H
