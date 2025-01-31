
#include "InputFake.h"

InputFake::InputFake(const std::string &fake_input)
    : fake_input(fake_input) {};

[[nodiscard]] std::string InputFake::read_line() {
  return this->fake_input;
};