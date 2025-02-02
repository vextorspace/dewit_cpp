#include <gtest/gtest.h>

#include "display/DisplayList.h"
#include "display/commands/AddItem.h"
#include "display/commands/Command.h"

TEST(AddItemCommand, nammed_add_item) {
    auto add_item = AddItem(nullptr, nullptr);
    ASSERT_EQ(add_item.get_name(), "Add Item");
}


TEST(AddItemCommand, execute_adds_item_with_cin_and_selected_item) {
    ItemStore store = ItemStore();
    DisplayList list = DisplayList(&store);
    const Item *child = store.create("parent");
    list.select_item(child);

    std::istringstream input_string("new");
    auto original_cin_buf = std::cin.rdbuf();
    std::cin.rdbuf(input_string.rdbuf());

    auto add_item = AddItem(&store, &list);
    add_item.execute();

    ASSERT_EQ(child->get_items().size(), 1);
    ASSERT_EQ(child->get_items()[0]->get_content(), "new");
    ASSERT_EQ(store.size(), 3);

    std::cin.rdbuf(original_cin_buf);
}

TEST(Command, matches_with_lowercase) {
    auto add_item = AddItem(nullptr, nullptr);
    ASSERT_TRUE(add_item.matches_this_command("add item"));
}