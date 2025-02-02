
#include "CommandList.h"

CommandList::CommandList() {
    commands = std::vector<std::unique_ptr<Command>>{};
}

CommandList::~CommandList() {
}

[[nodiscard]] size_t CommandList::size() const {
    return commands.size();
}

void CommandList::add(std::unique_ptr<Command> command) {
    this->commands.push_back(std::move(command));
}

void CommandList::execute(const string &command_string) {
    for (const auto &command: commands) {
        if (command->matches_this_command(command_string)) {
            // Assuming a `matches` method exists in Command
            command->execute(); // Assuming an `execute` method exists in Command
            break; // Stop after executing the matching command
        }
    }
}
