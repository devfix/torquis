[torquis.hpp]: https://github.com/devfix/torquis/blob/main/include/torquis.hpp

```
_______  _____   ______  _____  _     _ _____ _______
   |    |     | |_____/ |   __| |     |   |   |______
   |    |_____| |    \_ |____\| |_____| __|__ ______|

                  c++ string library
```

## Features
* small header-only library
* very lightweight, only one file
* various function overloads for string-views, strings and c-strings
* MIT license

## Functions
* split
* join

## Simple usage
* copy the <b>[torquis.hpp][torquis.hpp]</b> file into your project and include it

## CMake integration
If you are using CMake version 1.14 or later you can use [FetchContent](https://cmake.org/cmake/help/latest/module/FetchContent.html):
```cmake
Include(FetchContent)

FetchContent_Declare(
        torquis
        GIT_REPOSITORY https://github.com/devfix/torquis.git
        GIT_TAG        v0.1)
FetchContent_MakeAvailable(torquis)

add_executable(my_fancy_executable main.cpp)
target_include_directories(my_fancy_executable PRIVATE ${torquis_SOURCE_DIR}/include)
```