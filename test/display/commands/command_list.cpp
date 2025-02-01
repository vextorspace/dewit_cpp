#include <gtest/gtest.h>
#include "display/commands/CommandList.h"


TEST(CommandList, default_contains_nothing) {
    CommandList commands = CommandList();

    ASSERT_EQ(commands.size(), 0);
}
