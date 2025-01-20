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