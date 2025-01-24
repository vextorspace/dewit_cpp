#include <gtest/gtest.h>

#include "items/ItemStore.h"
#include "items/Item.h"

TEST(ItemStore, constructs_with_new_root_item) {
    ItemStore store = ItemStore();
    const Item * root = store.get_root();
    ASSERT_EQ(root->get_content(), "root");
    ASSERT_EQ(store.get_all_items()[0], root);
}

TEST(ItemStore, get_root_returns_same_item) {
    ItemStore store = ItemStore();
    const Item * root = store.get_root();
    ASSERT_EQ(root, store.get_root());
}

TEST(ItemStore, different_store_gives_different_root) {
    ItemStore store1 = ItemStore();
    ItemStore store2 = ItemStore();
    ASSERT_NE(store1.get_root(), store2.get_root());
}

TEST(ItemStore, selected_item_default_root) {
    ItemStore store = ItemStore();
    ASSERT_EQ(store.get_selected_item(), store.get_root());
}

TEST(ItemStore, create_adds_to_root) {
    ItemStore store = ItemStore();
    const Item * item = store.create("content");

    ASSERT_EQ(store.get_root()->get_items().size(), 1);
    ASSERT_EQ(store.get_root()->get_items()[0]->get_content(), "content");
    ASSERT_EQ(item, store.get_root()->get_items()[0]);
}

TEST(ItemStore, get_all_items) {
    ItemStore store = ItemStore();
    const Item * item = store.create("content");

    std::vector<const Item *> all_items = store.get_all_items();

    ASSERT_EQ(all_items.size(), 2);
    ASSERT_EQ(*all_items[1], *item);
    ASSERT_EQ(*all_items[0], *store.get_root());
}