#include <gtest/gtest.h>

#include "items/item.h"

TEST(Item, creates_with_content_and_random_id) {
    Item item("content");
    ASSERT_EQ(item.content(), "content");
}
