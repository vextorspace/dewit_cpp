
#ifndef INPUT_H
#define INPUT_H

#include <string>

class Input {
  public:
    Input() = default;
    virtual ~Input() = default;
    [[nodiscard]] virtual std::string read_line() = 0;
};

#endif //INPUT_H
