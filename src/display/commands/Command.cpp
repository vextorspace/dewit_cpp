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
    return to_lower(get_name()) == to_lower(command_string);
}

string Command::to_lower(const string &str) {
    string result;
    for (char c : str) {
        result += tolower(c);
    }
    return result;
}
