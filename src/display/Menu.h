
#ifndef MENU_H
#define MENU_H
#include "Command.h"
#include "DisplayList.h"
#include "items/ItemStore.h"


class Menu {
public:
    Menu() = delete;
    explicit Menu(ItemStore *store, DisplayList *display_list);
    ~Menu();

    [[nodiscard]] std::vector<const Command *> get_commands() const;

private:
    ItemStore *store;
    DisplayList *display_list;
    std::vector<Command *> commands;
};



#endif //MENU_H
