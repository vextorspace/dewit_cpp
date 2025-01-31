#include <gtest/gtest.h>

#include "display/ConsoleOutput.h"

TEST(ConsoleOutput, writes_text_to_cout) {
    std::stringstream buffer;
    std::streambuf *oldCoutBuffer = std::cout.rdbuf(buffer.rdbuf());

    std::string output = "hello there";
    ConsoleOutput().write_line(output);

    std::cout.rdbuf(oldCoutBuffer); // Restore the original buffer

    ASSERT_EQ(buffer.str(), "hello there\n");
}
