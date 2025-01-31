
#ifndef MENU_H
#define MENU_H
#include "Command.h"
#include "DisplayList.h"
#include "Output.h"
#include "items/ItemStore.h"


class Menu {
public:
    Menu() = delete;
    explicit Menu(ItemStore *store, DisplayList *display_list);

    Menu(ItemStore * store, DisplayList * list, Output *output);

    ~Menu();

    [[nodiscard]] std::vector<const Command *> get_commands() const;

    void print_commands() const;

    void print_items() const;

    void print() const;

private:
    ItemStore *store;
    DisplayList *display_list;
    std::vector<Command *> commands;
    Output *output;
};



#endif //MENU_H
