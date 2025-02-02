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
    virtual void execute() = 0;

    [[nodiscard]] bool matches_this_command(const string &command_string) const;

private:
    static string to_lower(const string &str);
    string name;
};



#endif //COMMAND_H
