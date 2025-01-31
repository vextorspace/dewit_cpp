
#ifndef INPUTFAKE_H
#define INPUTFAKE_H

#include "display/Input.h"

class InputFake : public Input {
public:
  explicit InputFake(const std::string &fake_input);
  [[nodiscard]] std::string read_line() override;

private:
    const std::string fake_input;
};

#endif //INPUTFAKE_H
