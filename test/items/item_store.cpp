#include <gtest/gtest.h>

#include "items/ItemStore.h"
#include "items/Item.h"

TEST(ItemStore, constructs_with_new_root_item) {
    ItemStore store = ItemStore();
    const Item * root = store.get_root();
    ASSERT_EQ(root->get_content(), "root");
}
