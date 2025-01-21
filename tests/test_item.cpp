#include <gtest/gtest.h>

#include "Item.h"

TEST(Item, has_content) {
    Item item("Test Item");
    ASSERT_EQ(item.get_content(), "Test Item");
}

TEST(Item, has_id) {
    Item item("Test Item");
    ASSERT_FALSE(item.get_id().size() == 0);
}

TEST(Item, can_make_with_id) {
    Item item("Test Item", "123");
    ASSERT_EQ(item.get_id(), "123");
}

TEST(Item, has_equals) {
    Item item("Test Item", "SAME_ID");
    Item item2("Test Item", "SAME_ID");
    ASSERT_TRUE(item == item2);
}

TEST(Item, has_not_equals) {
    Item item("Test Item", "SAME_ID");
    Item item2("Test Item", "DIFFERENT_ID");
    ASSERT_TRUE(item != item2);
}

TEST(Item, can_be_assigned) {
    Item item("Test Item");
    Item item2 = item;
    ASSERT_TRUE(item == item2);
}

TEST(Item, initiall_no_sub_items) {
    Item item("Test Item");
    ItemList items = item.get_sub_items();
    ASSERT_EQ(items.size(), 0);
}

TEST(Item, constructed_with_items_has_subs) {

    Item item("Test Item", "id1", std::vector{Item("child1"), Item("child2")});
    auto items = item.get_sub_items().get_items();
    ASSERT_EQ(items.size(), 2);
    ASSERT_EQ(items[0].get_content(), "child1");
    ASSERT_EQ(items[1].get_content(), "child2");
}

TEST(Item, can_add_sub_item) {
    Item item("Test Item");
    item.add_sub_item(Item("child1"));
    auto items = item.get_sub_items().get_items();
    ASSERT_EQ(items.size(), 1);
    ASSERT_EQ(items[0].get_content(), "child1");
}
