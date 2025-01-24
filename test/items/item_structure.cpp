#include <gtest/gtest.h>

#include "items/item.h"

TEST(Item, creates_with_content_and_random_id) {
    Item item("content");
    ASSERT_EQ(item.get_content(), "content");
}

TEST(Item, uses_different_ids) {
    Item item1("content");
    Item item2("content");
    ASSERT_NE(item1.get_id(), item2.get_id());
}

TEST(Item, creates_with_content_and_id) {
    Item item("content", "id");
    ASSERT_EQ(item.get_content(), "content");
    ASSERT_EQ(item.get_id(), "id");
}

TEST(Item, can_change_contents) {
    Item item("content");
    item.set_content("new content");
    ASSERT_EQ(item.get_content(), "new content");
}

TEST(Item, can_add_sub_item) {
    Item item("content");
    ASSERT_EQ(item.get_items().size(), 0);
    Item child("child");
    item.add_item(&child);
    ASSERT_EQ(item.get_items().size(), 1);
}

TEST(Item, equals_by_id) {
    Item item1("content", "id");
    Item item2("content doesn't matter", "id");
    Item item3("content", "id3");
    ASSERT_EQ(item1, item2);
    ASSERT_NE(item1, item3);
    ASSERT_TRUE(item1 != item3);
}

TEST(Item, will_not_duplicate_children) {
    Item item("content");
    Item child("child");
    item.add_item(&child);
    item.add_item(&child);
    ASSERT_EQ(item.get_items().size(), 1);
}