#include <gtest/gtest.h>
#include <string>

#include "items/UuidGenerator.h"

using namespace std;
TEST(UuidGenerator, makes_different_strings) {
    string id1 = UuidGenerator::generate();
    string id2 = UuidGenerator::generate();

    ASSERT_NE(id1, id2);
}

TEST(UuidGenerator, makes_36_char_uuids) {
    ASSERT_GE(UuidGenerator::generate().size(), 36);
}
