#include <gtest/gtest.h>

#include "display/AddItem.h"
#include "display/Command.h"

TEST(Command, has_name) {
    Command command = Command("name");

    ASSERT_EQ(command.get_name(), "name");
}

TEST(AddItemCommand, nammed_add_item) {
    Command add_item = AddItem();
    ASSERT_EQ(add_item.get_name(), "Add Item");
}