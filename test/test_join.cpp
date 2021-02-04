//
// Created by core on 03/02/2021.
//

#include <catch2/catch.hpp>
#include <include/torquis.hpp>

TEST_CASE("join - 0")
{
	std::vector<std::string> vec;
	auto join = torquis::join(vec, "-");
	CHECK(join.empty());
}

TEST_CASE("join - 1")
{
	std::vector<std::string> vec = {{ "a" }, { "b" }, { "c" }};
	auto join = torquis::join(vec, std::string(""));
	CHECK(join == "abc");
}

TEST_CASE("join - 2")
{
	std::vector<std::string_view> vec = {{ "a" }, { "b" }, { "c" }};
	auto join = torquis::join(vec, std::string_view("-"));
	CHECK(join == "a-b-c");
}
