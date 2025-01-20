#include <gtest/gtest.h>

#include "Item.h"

TEST(Item, hasName) {
    Item item("Test Item");
    ASSERT_EQ(item.get_name(), "Test Item");
}
