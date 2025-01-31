cmake_minimum_required(VERSION 3.30)
project(dewit VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.15.2
)
FetchContent_MakeAvailable(googletest)

enable_testing()

file(GLOB_RECURSE PROGRAM_SOURCES
        "${CMAKE_SOURCE_DIR}/src/*.cpp"
        "${CMAKE_SOURCE_DIR}/src/test/*.cpp"
)
file(GLOB_RECURSE PROGRAM_HEADERS
        "${CMAKE_SOURCE_DIR}/src/*.h"
        "${CMAKE_SOURCE_DIR}/src/test/*.h"
)
file(GLOB_RECURSE TEST_SOURCES
        "${CMAKE_SOURCE_DIR}/test/*.cpp"
        "${CMAKE_SOURCE_DIR}/test/items/*.cpp"
)

add_executable(dewit main.cpp
        ${PROGRAM_SOURCES}
        ${PROGRAM_HEADERS}
        test/display/display_list.cpp
        src/display/DisplayList.cpp
        src/display/DisplayList.h
        test/display/command.cpp
        src/display/Command.cpp
        src/display/Command.h
        src/display/AddItem.cpp
        src/display/AddItem.h
        test/display/console_input.cpp
        src/display/ConsoleInput.cpp
        src/display/ConsoleInput.h
)

add_executable(dewit_tests
        ${PROGRAM_SOURCES}
        ${PROGRAM_HEADERS}
        ${TEST_SOURCES}
)

target_link_libraries(dewit PRIVATE GTest::gtest)

target_link_libraries(dewit_tests PRIVATE
        GTest::gtest
        GTest::gtest_main
)

target_include_directories(dewit PRIVATE
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/src/test
)

target_include_directories(dewit_tests PRIVATE
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/src/test
)

include(GoogleTest)
gtest_discover_tests(dewit_tests)