
#ifndef MENU_H
#define MENU_H
#include "commands/Command.h"
#include "DisplayList.h"
#include "Input.h"
#include "Output.h"
#include "items/ItemStore.h"


class Menu {
public:
    Menu() = delete;
    explicit Menu(ItemStore *store, DisplayList *display_list);

    Menu(ItemStore * store, DisplayList * list, Output *output);
    Menu(ItemStore * store, DisplayList * list, Output *output, Input *input);

    ~Menu();

    [[nodiscard]] std::vector<const Command *> get_commands() const;

    void print_commands() const;

    void print_items() const;

    void print() const;

    std::string get_user_selection();

    void execute(const std::string &selection);

private:
    ItemStore *store;
    DisplayList *display_list;
    std::vector<Command *> commands;
    Output *output;
    Input *input;
};



#endif //MENU_H
