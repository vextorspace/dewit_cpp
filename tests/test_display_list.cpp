#include <gtest/gtest.h>

#include "Item.h"
#include "DisplayList.h"

TEST(DisplayList, made_with_item) {
    Item root_item = Item("root");
    DisplayList list = DisplayList(root_item);
    Item item = list.get_root();
    ASSERT_EQ(item, root_item);
}

TEST(DisplayList, returns_sub_items) {
    Item root_item = Item("root");
    Item sub_item = Item("sub");
    root_item.add_sub_item(sub_item);
    DisplayList list = DisplayList(root_item);
    ItemList items = list.display_items();
    ASSERT_EQ(items.size(), 1);
    ASSERT_EQ(items.get_items()[0], sub_item);
}