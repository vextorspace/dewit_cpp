
#include "Menu.h"
#include "commands/AddItem.h"
#include "ConsoleOutput.h"

#include <format>

Menu::Menu(ItemStore *store, DisplayList *display_list)
: Menu(store, display_list, nullptr) {}

Menu::Menu(ItemStore *store, DisplayList *list, Output *output)
: Menu(store, list, output, nullptr) {}

Menu::Menu(ItemStore *store, DisplayList *list, Output *output, Input *input) : store(store), display_list(list), output(output), input(input) {
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

void Menu::print_commands() const {
    std::string command_names;
    for (const auto &command: commands) {
        if (!command_names.empty()) {
            command_names += " | ";
        }
        command_names += command->get_name();
    }
    output->write_line(command_names);
}

void Menu::print_items() const {
    output->write_line(display_list->get_selected_item()->get_content());
    size_t index = 0;
    for (const auto item: this->display_list->items()) {
        output->write_line(
            std::format(" => {}. {}"
                , index++
                , item->get_content()));
    }
}

void Menu::print() const {
    print_items();
    output->write_line("");
    print_commands();
}

std::string Menu::get_user_selection() {
    return input->read_line();
}

void Menu::execute(const std::string &selection) {
    std::string trimmed_selection = selection;
    trimmed_selection.erase(0, trimmed_selection.find_first_not_of(' '));
    trimmed_selection.erase(trimmed_selection.find_last_not_of(' ') + 1);

    if (!trimmed_selection.empty() && std::all_of(trimmed_selection.begin(), trimmed_selection.end(), ::isdigit)) {
        int number = std::stoi(trimmed_selection);
        this->display_list->select_child_at(number);
    } else {

    }
}


