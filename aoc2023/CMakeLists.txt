cmake_minimum_required(VERSION 3.28)
project(aoc2023 CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_VISIBILITY_INLINES_HIDDEN ON)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)

include(GNUInstallDirs)

# FMT is too valuable
find_package(fmt REQUIRED)
link_libraries(fmt::fmt)

# Common includes
include_directories(${CMAKE_CURRENT_LIST_DIR}/include)

# Common Compiler warnings
add_compile_options(-pedantic -Wall -Wextra -Werror)

if(NOT CMAKE_BUILD_TYPE MATCHES Debug)
    # Enable LTO
    set(CMAKE_INTERPROCEDURAL_OPTIMIZATION ON)
    # Enable CPU features
    add_compile_options(-march=native)
endif()

# Each day of AOC
add_subdirectory(day1)