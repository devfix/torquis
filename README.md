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
* tolower
* toupper
* replace

## Simple usage
* copy the content of the `include` directory and include `torquis.hpp`

## CMake integration
If you are using CMake version 1.14 or later you can use [FetchContent](https://cmake.org/cmake/help/latest/module/FetchContent.html) with `FetchContent_MakeAvailable`:
```cmake
Include(FetchContent)

FetchContent_Declare(
        torquis_targz
        URL https://github.com/devfix/torquis/archive/refs/tags/XXX.tar.gz  # insert correct version here
        URL_HASH SHA256=0  # insert correct hash here
        DOWNLOAD_EXTRACT_TIMESTAMP 1
)
FetchContent_MakeAvailable(torquis_targz)

# add library to target
add_executable(my_fancy_executable main.cpp)
target_include_directories(my_fancy_executable PRIVATE ${torquis_targz_SOURCE_DIR}/include)
target_include_directories(my_fancy_executable PRIVATE ${torquis_INCLUDE_DIRS})
```