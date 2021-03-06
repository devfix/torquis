cmake_minimum_required(VERSION 3.14)

# ---------------------------------------------------------------------------------------
# use ccache (optional)
# ---------------------------------------------------------------------------------------
find_program(CCACHE_PROGRAM ccache)
if (CCACHE_PROGRAM)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CCACHE_PROGRAM}")
else ()
    message(STATUS "ccache not found (optional, not an error)")
endif ()


# ---------------------------------------------------------------------------------------
# project setup
# ---------------------------------------------------------------------------------------
project(torquis)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -Wno-long-long")

# download Catch2 testing framework
Include(FetchContent)
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v2.13.1)
FetchContent_MakeAvailable(Catch2)


# ---------------------------------------------------------------------------------------
# create testrunner target
# ---------------------------------------------------------------------------------------
file(GLOB include_files "include/*")
file(GLOB torquis_include_files "include/torquis/*")
add_executable(testrunner ${include_files} ${torquis_include_files} test/testrunner.cpp test/test_split.cpp test/test_join.cpp test/test_inter.cpp test/test_tolower.cpp test/test_toupper.cpp test/test_replace.cpp)
target_include_directories(testrunner PRIVATE .)
target_link_libraries(testrunner PRIVATE Catch2::Catch2)
