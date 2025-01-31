#include <gtest/gtest.h>

#include "display/Command.h"
#include "display/DisplayList.h"
#include "display/Menu.h"
#include "items/ItemStore.h"
#include "display/Output.h"
#include "OutputSpy.h"

TEST(Menu, get_commands_has_add_item) {
    auto store = ItemStore();
    auto list = DisplayList(&store);
    auto menu = Menu(&store, &list);

    std::vector<const Command *> commands = menu.get_commands();

    ASSERT_EQ(commands.size(), 1);
    ASSERT_EQ(commands[0]->get_name(), "Add Item");
}

TEST(Menu, print_commands_writes_list) {
    auto store = ItemStore();
    auto list = DisplayList(&store);
    auto output = OutputSpy();
    auto menu = Menu(&store, &list, &output);

    menu.print_commands();
}