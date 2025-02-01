//
// Created by vextorspace on 1/29/25.
//

#include "Command.h"

Command::Command(const string &name): name(std::move(name)) {
}

const string Command::get_name() const {
    return name;
}
