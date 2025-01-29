#include <gtest/gtest.h>

#include "display/DisplayList.h"
#include "items/ItemStore.h"

TEST(DisplayList, has_store) {
    ItemStore store = ItemStore();
    DisplayList list = DisplayList(&store);

    ASSERT_EQ(store.get_root(), list.get_root());
}
