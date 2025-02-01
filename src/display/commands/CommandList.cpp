
#include "CommandList.h"

CommandList::CommandList() {
    commands = std::vector<std::unique_ptr<Command>>{};
}

CommandList::~CommandList() {
}

[[nodiscard]] size_t CommandList::size() const {
    return commands.size();
}