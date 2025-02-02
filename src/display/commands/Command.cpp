//
// Created by vextorspace on 1/29/25.
//

#include "Command.h"

Command::Command(const string &name): name(std::move(name)) {
}

const string Command::get_name() const {
    return name;
}

bool Command::matches_this_command(const string &command_string) const {
    return to_lower(get_name()).rfind(to_lower(command_string), 0) == 0;
}

string Command::to_lower(const string &str) {
    string result;
    for (char c : str) {
        result += tolower(c);
    }
    return result;
}
