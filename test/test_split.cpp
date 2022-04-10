//
// Created by core on 03/02/2021.
//

#include <catch2/catch.hpp>
#include <torquis.hpp>


/*
 * tests for character type: char
 */

TEST_CASE("split/char/by-character/0")
{
	const auto str = "";
	const auto split = torquis::split({ str }, '#');
	REQUIRE(split.size() == 1);
	CHECK(split[0] == "");
}

TEST_CASE("split/char/by-character/1")
{
	const auto str = "abc#def#ghi";
	const auto split = torquis::split({ str }, '#');
	REQUIRE(split.size() == 3);
	CHECK(split[0] == "abc");
	CHECK(split[1] == "def");
	CHECK(split[2] == "ghi");
}

TEST_CASE("split/char/by-character/2")
{
	const auto str = "#abc#def#ghi##";
	const auto split = torquis::split({ str }, '#');
	REQUIRE(split.size() == 6);
	CHECK(split[0] == "");
	CHECK(split[1] == "abc");
	CHECK(split[2] == "def");
	CHECK(split[3] == "ghi");
	CHECK(split[4] == "");
	CHECK(split[5] == "");
}

TEST_CASE("split/char/by-character/3")
{
	const auto str = "###";
	const auto split = torquis::split({ str }, '#');
	REQUIRE(split.size() == 4);
	CHECK(split[0] == "");
	CHECK(split[1] == "");
	CHECK(split[2] == "");
	CHECK(split[3] == "");
}

TEST_CASE("split/char/by-string/0")
{
	const std::string_view str = "";
	const auto split = torquis::split(str, "-#");
	REQUIRE(split.size() == 1);
	CHECK(split[0] == "");
}

TEST_CASE("split/char/by-string/1")
{
	const std::string str = "abc";
	const auto split = torquis::split(str, "");
	REQUIRE(split.size() == 3);
	CHECK(split[0] == "a");
	CHECK(split[1] == "b");
	CHECK(split[2] == "c");
}

TEST_CASE("split/char/by-string/2")
{
	const auto str = "a-bc-#de#f-#g-h#i";
	const auto split = torquis::split(str, std::string("-#"));
	REQUIRE(split.size() == 3);
	CHECK(split[0] == "a-bc");
	CHECK(split[1] == "de#f");
	CHECK(split[2] == "g-h#i");
}

TEST_CASE("split/char/by-string/3")
{
	const auto str = "-#abc--##def--##ghi-#-#";
	const auto split = torquis::split( str , std::string_view("-#"));
	REQUIRE(split.size() == 6);
	CHECK(split[0] == "");
	CHECK(split[1] == "abc-");
	CHECK(split[2] == "#def-");
	CHECK(split[3] == "#ghi");
	CHECK(split[4] == "");
	CHECK(split[5] == "");
}

TEST_CASE("split/char/by-string/4")
{
	const auto str = "-#-#-#";
	const auto split = torquis::split( str , std::string_view("-#"));
	REQUIRE(split.size() == 4);
	CHECK(split[0] == "");
	CHECK(split[1] == "");
	CHECK(split[2] == "");
	CHECK(split[3] == "");
}



/*
 * tests for character type: wchar_t
 */

TEST_CASE("split/wchar_t/by-character/0")
{
	const auto str = L"";
	const auto split = torquis::split({ str }, L'#');
	REQUIRE(split.size() == 1);
	CHECK(split[0] == L"");
}

TEST_CASE("split/wchar_t/by-character/1")
{
	const auto str = L"abc#def#ghi";
	const auto split = torquis::split({ str }, L'#');
	REQUIRE(split.size() == 3);
	CHECK(split[0] == L"abc");
	CHECK(split[1] == L"def");
	CHECK(split[2] == L"ghi");
}

TEST_CASE("split/wchar_t/by-character/2")
{
	const auto str = L"#abc#def#ghi##";
	const auto split = torquis::split({ str }, L'#');
	REQUIRE(split.size() == 6);
	CHECK(split[0] == L"");
	CHECK(split[1] == L"abc");
	CHECK(split[2] == L"def");
	CHECK(split[3] == L"ghi");
	CHECK(split[4] == L"");
	CHECK(split[5] == L"");
}

TEST_CASE("split/wchar_t/by-character/3")
{
	const auto str = L"###";
	const auto split = torquis::split({ str }, L'#');
	REQUIRE(split.size() == 4);
	CHECK(split[0] == L"");
	CHECK(split[1] == L"");
	CHECK(split[2] == L"");
	CHECK(split[3] == L"");
}

TEST_CASE("split/wchar_t/by-string/0")
{
	const std::wstring_view str = L"";
	const auto split = torquis::split(str, L"-#");
	REQUIRE(split.size() == 1);
	CHECK(split[0] == L"");
}

TEST_CASE("split/wchar_t/by-string/1")
{
	const std::wstring str = L"abc";
	const auto split = torquis::split(str, L"");
	REQUIRE(split.size() == 3);
	CHECK(split[0] == L"a");
	CHECK(split[1] == L"b");
	CHECK(split[2] == L"c");
}

TEST_CASE("split/wchar_t/by-string/2")
{
	const auto str = L"a-bc-#de#f-#g-h#i";
	const auto split = torquis::split(str, std::wstring(L"-#"));
	REQUIRE(split.size() == 3);
	CHECK(split[0] == L"a-bc");
	CHECK(split[1] == L"de#f");
	CHECK(split[2] == L"g-h#i");
}

TEST_CASE("split/wchar_t/by-string/3")
{
	const auto str = L"-#abc--##def--##ghi-#-#";
	const auto split = torquis::split(str, std::wstring_view(L"-#"));
	REQUIRE(split.size() == 6);
	CHECK(split[0] == L"");
	CHECK(split[1] == L"abc-");
	CHECK(split[2] == L"#def-");
	CHECK(split[3] == L"#ghi");
	CHECK(split[4] == L"");
	CHECK(split[5] == L"");
}

TEST_CASE("split/wchar_t/by-string/4")
{
	const auto str = L"-#-#-#";
	const auto split = torquis::split( str , std::wstring_view(L"-#"));
	REQUIRE(split.size() == 4);
	CHECK(split[0] == L"");
	CHECK(split[1] == L"");
	CHECK(split[2] == L"");
	CHECK(split[3] == L"");
}

