#include <gtest/gtest.h>

#include "Item.h"
#include "DisplayList.h"

TEST(DisplayList, made_with_item) {
    Item root_item = Item("root");
    DisplayList list = DisplayList(root_item);
    Item item = list.get_root();
    ASSERT_EQ(item, root_item);
}