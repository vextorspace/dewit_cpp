
#include "OutputSpy.h"


void OutputSpy::write_line(const std::string &text) {
  output = text;
}

const std::string OutputSpy::get_output() const {
    return output;
}