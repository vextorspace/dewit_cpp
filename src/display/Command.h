#ifndef COMMAND_H
#define COMMAND_H
#include <string>

using namespace std;

class Command {
public:
    Command() = delete;
    explicit Command(const string &name);
    virtual ~Command() = default;

    [[nodiscard]] const string get_name() const;
private:
    string name;
};



#endif //COMMAND_H
