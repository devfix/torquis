cmake_minimum_required(VERSION 3.14)

#-----------------------------------------------------------------
# use ccache (optional)
#-----------------------------------------------------------------
find_program(CCACHE_PROGRAM ccache)
if (CCACHE_PROGRAM)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CCACHE_PROGRAM}")
else ()
    message(STATUS "ccache not found (optional, not an error)")
endif ()


#-----------------------------------------------------------------
# project setup
#-----------------------------------------------------------------
project(torquis)

set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -Wno-long-long")

# download Catch2 testing framework
Include(FetchContent)
FetchContent_Declare(
        catch2_git
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v2.13.1
        GIT_SHALLOW TRUE
        GIT_PROGRESS TRUE
)
FetchContent_MakeAvailable(catch2_git)


#-----------------------------------------------------------------
# create testrunner target
#-----------------------------------------------------------------
file(GLOB include_files "${CMAKE_CURRENT_SOURCE_DIR}/include/*")
file(GLOB torquis_include_files "${CMAKE_CURRENT_SOURCE_DIR}/include/torquis/*")
file(GLOB TEST_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/test/*.cpp)
add_executable(testrunner ${include_files} ${torquis_include_files} ${TEST_SOURCES})
target_include_directories(testrunner PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(testrunner PRIVATE Catch2::Catch2)

set(TORQUIS_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/include PARENT_SCOPE)  # make torquis available
