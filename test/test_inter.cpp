//
// Created by core on 04/02/2021.
//

#include <catch2/catch.hpp>
#include <include/torquis.hpp>

/*
 * tests for character type: char
 */

TEST_CASE("inter/char/split-join/0")
{
	const std::string_view str("abc#def#ghi");
	auto joined = torquis::join(torquis::split(str, '#'), "#");
	CHECK(joined == str);
}

TEST_CASE("inter/char/split-join/1")
{
	const std::string_view str("abc#def#ghi");
	auto joined = torquis::join(torquis::split(str, "#"), "#");
	CHECK(joined == str);
}

TEST_CASE("inter/char/split-join/2")
{
	const std::string_view str("#abc#def#ghi#");
	auto joined = torquis::join(torquis::split(str, "#"), "#");
	CHECK(joined == str);
}

TEST_CASE("inter/char/split-join/3")
{
	const std::string_view str("##abc#def#####ghi####");
	auto joined = torquis::join(torquis::split(str, "##"), "##");
	CHECK(joined == str);
}

TEST_CASE("inter/char/split-join/4")
{
	const std::string_view str("+-aa-++-++--bb+-");
	auto joined = torquis::join(torquis::split(str, "+-"), "+-");
	CHECK(joined == str);
}



/*
 * tests for character type: wchar_t
 */

TEST_CASE("inter/wchar_t/split-join/0")
{
	const std::wstring_view str(L"abc#def#ghi");
	auto joined = torquis::join(torquis::split(str, L'#'), L"#");
	CHECK(joined == str);
}

TEST_CASE("inter/wchar_t/split-join/1")
{
	const std::wstring_view str(L"abc#def#ghi");
	auto joined = torquis::join(torquis::split(str, L"#"), L"#");
	CHECK(joined == str);
}

TEST_CASE("inter/wchar_t/split-join/2")
{
	const std::wstring_view str(L"#abc#def#ghi#");
	auto joined = torquis::join(torquis::split(str, L"#"), L"#");
	CHECK(joined == str);
}

TEST_CASE("inter/wchar_t/split-join/3")
{
	const std::wstring_view str(L"##abc#def#####ghi####");
	auto joined = torquis::join(torquis::split(str, L"##"), L"##");
	CHECK(joined == str);
}

TEST_CASE("inter/wchar_t/split-join/4")
{
	const std::wstring_view str(L"+-aa-++-++--bb+-");
	auto joined = torquis::join(torquis::split(str, L"+-"), L"+-");
	CHECK(joined == str);
}
