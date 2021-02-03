//
// Created by core on 04/02/2021.
//

#include <catch2/catch.hpp>
#include <torquis.hpp>

TEST_CASE("inter - split & join - 0")
{
	const std::string_view str("abc#def#ghi");
	auto joined = torquis::join(torquis::split(str, '#'), "#");
	CHECK(joined == str);
}

TEST_CASE("inter - split & join - 1")
{
	const std::string_view str("abc#def#ghi");
	auto joined = torquis::join(torquis::split(str, "#"), "#");
	CHECK(joined == str);
}

TEST_CASE("inter - split & join - 2")
{
	const std::string_view str("#abc#def#ghi#");
	auto joined = torquis::join(torquis::split(str, "#"), "#");
	CHECK(joined == str);
}

TEST_CASE("inter - split & join - 3")
{
	const std::string_view str("##abc#def#####ghi####");
	auto joined = torquis::join(torquis::split(str, "##"), "##");
	CHECK(joined == str);
}

TEST_CASE("inter - split & join - 4")
{
	const std::string_view str("+-aa-++-++--bb+-");
	auto joined = torquis::join(torquis::split(str, "+-"), "+-");
	CHECK(joined == str);
}
