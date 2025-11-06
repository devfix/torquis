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


#-----------------------------------------------------------------
# create torquis_testrunner target
#-----------------------------------------------------------------
file(GLOB include_files "${CMAKE_CURRENT_SOURCE_DIR}/include/*")
file(GLOB torquis_include_files "${CMAKE_CURRENT_SOURCE_DIR}/include/torquis/*")
file(GLOB TEST_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/test/*.cpp)
add_executable(torquis_testrunner ${include_files} ${torquis_include_files} ${TEST_SOURCES})
target_include_directories(torquis_testrunner PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)


#-----------------------------------------------------------------
# add library Catch2 testing framework
#-----------------------------------------------------------------
find_package(Catch2 QUIET)
if(NOT Catch2_FOUND)
    Include(FetchContent)
    FetchContent_Declare(
        catch2_targz
        URL https://github.com/catchorg/Catch2/archive/refs/tags/v3.11.0.tar.gz
        URL_HASH SHA256=82fa1cb59dc28bab220935923f7469b997b259eb192fb9355db62da03c2a3137
        DOWNLOAD_EXTRACT_TIMESTAMP 1
    )
    FetchContent_MakeAvailable(catch2_targz)
endif()

# add library to target
target_include_directories(torquis_testrunner PRIVATE ${catch2_targz_SOURCE_DIR}/single_include)
target_link_libraries(torquis_testrunner PRIVATE Catch2::Catch2WithMain)
