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

TEST(ItemList, constructor_with_items_returns_items) {
    std::vector<Item> items = {Item("item1"), Item("item2")};
    ItemList list = ItemList(items);
    ASSERT_EQ(items, list.get_items());
}

TEST(ItemList, constructed_with_items_gives_correct_size) {
    std::vector<Item> items = {Item("item1"), Item("item2")};
    ItemList list = ItemList(items);
    ASSERT_EQ(items.size(), list.size());
}

TEST(ItemList, constructed_with_items_not_empty) {
    std::vector<Item> items = {Item("item1"), Item("item2")};
    ItemList list = ItemList(items);
    ASSERT_FALSE(list.is_empty());
}

TEST(ItemList, add_item_adds_to_end) {
    ItemList list = ItemList(std::vector<Item>{Item("Item 0")});
    Item item = Item("item1");
    bool success = list.add_item(item);
    ASSERT_EQ(item, list.get_items()[1]);
    ASSERT_TRUE(success);
}

TEST(ItemList, add_item_already_there_does_nothing) {
    ItemList list = ItemList(std::vector<Item>{Item("Item 0", "id0")});
    Item item = Item("Item 0", "id0");
    bool success = list.add_item(item);
    ASSERT_EQ(1, list.size());
    ASSERT_FALSE(success);
}