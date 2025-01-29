#include <gtest/gtest.h>

#include "display/Command.h"

TEST(Command, has_name) {
    Command command = Command("name");

    ASSERT_EQ(command.get_name(), "name");
}