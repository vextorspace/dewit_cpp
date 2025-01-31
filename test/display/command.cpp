#include <gtest/gtest.h>

#include "display/AddItem.h"
#include "display/Command.h"

TEST(AddItemCommand, nammed_add_item) {
    auto add_item = AddItem(nullptr, nullptr);
    ASSERT_EQ(add_item.get_name(), "Add Item");
}