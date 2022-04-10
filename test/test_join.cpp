//
// Created by core on 03/02/2021.
//

#include <catch2/catch.hpp>
#include <torquis.hpp>

/*
 * tests for character type: char
 */

TEST_CASE("join/char/0")
{
	std::vector<std::string> vec;
	auto join = torquis::join(vec, "-");
	CHECK(join.empty());
}

TEST_CASE("join/char/1")
{
	std::vector<std::string> vec = {{ "a" }, { "b" }, { "c" }};
	auto join = torquis::join(vec, std::string(""));
	CHECK(join == "abc");
}

TEST_CASE("join/char/2")
{
	std::vector<std::string_view> vec = {{ "a" }, { "b" }, { "c" }};
	auto join = torquis::join(vec, std::string_view("-"));
	CHECK(join == "a-b-c");
}



/*
 * tests for character type: wchar_t
 */

TEST_CASE("join/wchar_t/0")
{
	std::vector<std::wstring> vec;
	auto join = torquis::join(vec, L"-");
	CHECK(join.empty());
}

TEST_CASE("join/wchar_t/1")
{
	std::vector<std::wstring> vec = {{ L"a" }, { L"b" }, { L"c" }};
	auto join = torquis::join(vec, std::wstring(L""));
	CHECK(join == L"abc");
}

TEST_CASE("join/wchar_t/2")
{
	std::vector<std::wstring_view> vec = {{ L"a" }, { L"b" }, { L"c" }};
	auto join = torquis::join(vec, std::wstring_view(L"-"));
	CHECK(join == L"a-b-c");
}
