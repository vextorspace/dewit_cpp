
#ifndef CONSOLEOUTPUT_H
#define CONSOLEOUTPUT_H
#include <string>
#include "Output.h"

class ConsoleOutput : public Output {
public:
    ConsoleOutput() = default;
    ~ConsoleOutput() override = default;
    void write_line(const std::string &message) override;
};



#endif //CONSOLEOUTPUT_H
