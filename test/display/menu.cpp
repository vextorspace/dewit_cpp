#include <format>
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

    ASSERT_EQ(output.get_output(), "Add Item\n");
}


TEST(Menu, print_items_writes_selected_item_and_children) {
    auto store = ItemStore();
    const Item* item1 = store.create("item1");
    const Item* item2 = store.create("item2");
    optional<const Item*> child1 = store.create_in("child1", item1->get_id());
    optional<const Item*> child2 = store.create_in("child2", item1->get_id());
    auto list = DisplayList(&store);
    list.select_item(item1);
    auto output = OutputSpy();
    auto menu = Menu(&store, &list, &output);

    menu.print_items();

    ASSERT_EQ(output.get_output(), std::format("{}\n => {}\n => {}\n", item1->get_content(), child1.value()->get_content(), child2.value()->get_content()));
}