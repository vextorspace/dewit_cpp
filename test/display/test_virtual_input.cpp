#include <gtest/gtest.h>

#include "display/ConsoleInput.h"

TEST(ConsoleInput, gets_string_from_cin) {
    std::istringstream input_string("hello");
    auto original_cin_buf = std::cin.rdbuf();
    std::cin.rdbuf(input_string.rdbuf());

    const std::string input = ConsoleInput().read_line();
    ASSERT_EQ(input, "hello");

    std::cin.rdbuf(original_cin_buf);
}
