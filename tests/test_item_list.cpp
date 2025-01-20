#include <gtest/gtest.h>
#include <vector>

#include "ItemList.h"
#include "Item.h"


TEST(ItemList, empty_size_0) {
    ItemList list = ItemList();
    ASSERT_EQ(list.size(), 0);
}

TEST(ItemList, empty_gives_empty_list) {
    ItemList list = ItemList();
    std::vector<Item> items = list.get_items();
    ASSERT_EQ(0, items.size());
}

TEST(ItemList, is_empty_of_empty) {
    ItemList list = ItemList();
    ASSERT_TRUE(list.is_empty());
}