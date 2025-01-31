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
        "${CMAKE_SOURCE_DIR}/src/src/*.cpp"
        "${CMAKE_SOURCE_DIR}/src/src/items/*.cpp"
        "${CMAKE_SOURCE_DIR}/src/src/display/*.cpp"
)
file(GLOB_RECURSE PROGRAM_HEADERS
        "${CMAKE_SOURCE_DIR}/src/*.h"
        "${CMAKE_SOURCE_DIR}/src/test/*.h"
        "${CMAKE_SOURCE_DIR}/src/items/*.h"
        "${CMAKE_SOURCE_DIR}/src/display/*.h"
)

file(GLOB_RECURSE TEST_SOURCES
        "${CMAKE_SOURCE_DIR}/test/*.cpp"
        "${CMAKE_SOURCE_DIR}/test/items/*.cpp"
        "${CMAKE_SOURCE_DIR}/test/display/*.cpp"
)

add_executable(dewit main.cpp
        ${PROGRAM_SOURCES}
        ${PROGRAM_HEADERS}
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