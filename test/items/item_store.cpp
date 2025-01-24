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

TEST(ItemStore, find_by_id) {
    ItemStore store = ItemStore();
    const Item * item = store.create("content");

    const std::optional<const Item *> found = store.find_by_id(item->get_id());
    ASSERT_TRUE(found.has_value());
    ASSERT_EQ(found.value(), item);
}

TEST(ItemStore, find_by_id_returns_null_not_found) {
    ItemStore store = ItemStore();

    const std::optional<const Item *> found = store.find_by_id("NON_EXISTENT ID");
    ASSERT_FALSE(found.has_value());
}

TEST(ItemStore, create_in_parent) {
    ItemStore store = ItemStore();
    const Item * parent = store.create("parent");
    const std::optional<const Item *> child = store.create_in("child", parent->get_id());
    ASSERT_TRUE(child.has_value());

    ASSERT_EQ(parent->get_items().size(), 1);
    ASSERT_EQ(parent->get_items()[0]->get_content(), "child");
    ASSERT_EQ(child.value(), parent->get_items()[0]);
    ASSERT_EQ(store.size(), 3);
    ASSERT_EQ(store.get_all_items().back(), child.value());
}

TEST(ItemStore, create_with_id) {
    ItemStore store = ItemStore();
    const Item * item = store.create("content", "id");

    ASSERT_EQ(item->get_id(), "id");
    ASSERT_EQ(store.size(), 2);
    ASSERT_EQ(store.get_all_items().back(), item);

    const Item * item2 = store.create("content", "id");
    ASSERT_EQ(store.size(), 2);
    ASSERT_EQ(item, item2);
}

TEST(ItemStore, create_in_parent_with_id) {
    ItemStore store = ItemStore();
    const Item * parent = store.create("parent");

    const std::optional<const Item *> child = store.create_in("child", "child's id", parent->get_id());

    ASSERT_TRUE(child.has_value());

    ASSERT_EQ(parent->get_items().size(), 1);
    ASSERT_EQ(parent->get_items()[0]->get_id(), "child's id");
    ASSERT_EQ(child.value(), parent->get_items()[0]);
    ASSERT_EQ(store.size(), 3);
    ASSERT_EQ(store.get_all_items().back(), child.value());

    const std::optional<const Item *> child2 = store.create_in("child", "child's id", parent->get_id());
    ASSERT_TRUE(child2.has_value());
    ASSERT_EQ(child.value(), child2.value());
    ASSERT_EQ(parent->get_items().size(), 1);

}

TEST(ItemStore, create_in_does_not_rearrange_pointers) {
    ItemStore store = ItemStore();
    const Item * parent = store.create("parent");
    ASSERT_FALSE(parent->get_id().empty());

    const std::optional<const Item *> child = store.create_in("child", "child's id", parent->get_id());
    auto parent_id = parent->get_id();
    ASSERT_FALSE(parent_id.empty());
}