#include <string>
#include <gtest/gtest.h>
#include "UuidGenerator.h"

using std::string;

TEST(UUID, is_string_with_atleast_36) {
    string id = UuidGenerator().generate();
    ASSERT_GE(id.size(), 36);
}