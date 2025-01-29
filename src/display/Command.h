#ifndef COMMAND_H
#define COMMAND_H
#include <string>

using namespace std;

class Command {
public:
    Command() = delete;
    explicit Command(const string &name);

    const string get_name() const;
private:
    string name;
};



#endif //COMMAND_H
