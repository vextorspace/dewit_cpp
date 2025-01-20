#include <string>
#include <gtest/gtest.h>
#include "UuidGenerator.h"

using std::string;

TEST(UUID, is_string_with_atleast_36) {
    string id = UuidGenerator().generate();
    ASSERT_GE(id.size(), 36);
}

TEST(UUID, no_same_twice) {
    string id1 = UuidGenerator().generate();
    string id2 = UuidGenerator().generate();
    ASSERT_NE(id1, id2);
}