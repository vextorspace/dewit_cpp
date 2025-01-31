
#ifndef OUTPUTSPY_H
#define OUTPUTSPY_H
#include <string>

#include "display/Output.h"

class OutputSpy : public Output {
public:
    void write_line(const std::string &text) override;

    const std::string get_output() const;

private:
    std::string output;
};



#endif //OUTPUTSPY_H
