cmake_minimum_required(VERSION 3.30)
project(dewit VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Download and include GoogleTest
include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.15.2
)
FetchContent_MakeAvailable(googletest)

# Enable testing
enable_testing()

# Automatically include all source files
file(GLOB_RECURSE PROGRAM_SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp")

file(GLOB_RECURSE TEST_SOURCES "${CMAKE_SOURCE_DIR}/tests/*.cpp")

# Your main executable
add_executable(dewit main.cpp
        ${PROGRAM_SOURCES}
)


# Create tests executable
add_executable(
        dewit_tests
        ${PROGRAM_SOURCES}
        ${TEST_SOURCES}
)

# Link the tests executable with Google Test
target_link_libraries(
        dewit_tests PRIVATE
        GTest::gtest
        GTest::gtest_main
)

target_include_directories(
        dewit PRIVATE
        ${CMAKE_SOURCE_DIR}/src
)

target_include_directories(
        dewit_tests PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)

# Register tests
include(GoogleTest)
gtest_discover_tests(dewit_tests)

