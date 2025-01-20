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