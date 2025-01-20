#include <gtest/gtest.h>
#include "ItemList.h"

TEST(ItemList, empty_size_0) {
    ItemList list = ItemList();
    ASSERT_EQ(list.size(), 0);
}
