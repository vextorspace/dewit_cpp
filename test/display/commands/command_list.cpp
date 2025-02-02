#include <gtest/gtest.h>

#include "display/commands/AddItem.h"
#include "display/commands/CommandList.h"
#include "CommandSpy.h"

TEST(CommandList, default_contains_nothing) {
    CommandList commands = CommandList();

    ASSERT_EQ(commands.size(), 0);
}

TEST(CommandList, add_increases_size) {
    CommandList commands = CommandList();

    auto command = std::make_unique<AddItem>(nullptr, nullptr);
    commands.add(std::move(command));

    ASSERT_EQ(commands.size(), 1);
}

TEST(CommandList, executes_first_matching_command) {
    CommandList commands = CommandList();
    auto spy1 = Spy();
    auto spy2 = Spy();
    commands.add(std::move(std::make_unique<CommandSpy>("Command 1", &spy1)));
    commands.add(std::move(std::make_unique<CommandSpy>("Command 2", &spy2)));
    commands.execute("Command 2");

    ASSERT_FALSE(spy1.was_caught());
    ASSERT_TRUE(spy2.was_caught());
}