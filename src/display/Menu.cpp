
#include "Menu.h"

#include "AddItem.h"

Menu::Menu(ItemStore *store, DisplayList *display_list) : store(store), display_list(display_list) {
    this->commands = std::vector<Command *>{new AddItem(store, display_list)};
}

Menu::~Menu() {
    while (!this->commands.empty()) {
        auto *command = this->commands.back();
        this->commands.pop_back();
        delete command;
    }
}


std::vector<const Command *> Menu::get_commands() const {
    std::vector<const Command *> command_list;
    for (const auto &command: this->commands) {
        command_list.push_back(command);
    }
    return command_list;
}


