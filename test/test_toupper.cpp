//
// Created by core on 10/02/2021.
//

#include <cstring>
#include <catch2/catch_test_macros.hpp>
#include <torquis.hpp>


/*
 * tests for character type: char
 */

TEST_CASE("toupper/char/by-cstring/0")
{
	std::string str;
	torquis::toupper(str); // call string type: string
	CHECK(str.empty());
}

TEST_CASE("toupper/char/by-cstring/1")
{
	std::string str("aöB?Äk#+ßl");
	torquis::toupper(str); // call string type: string
	CHECK(std::string("AöB?ÄK#+ßL") == str);
}

TEST_CASE("toupper/char/by-cstring/2")
{
	std::string str("aöB?Äk#+ßl");
	torquis::toupper(&str[0], str.length()); // call string type: c-string
	CHECK(std::string("AöB?ÄK#+ßL") == str);
}

TEST_CASE("toupper/char/by-cstring/3")
{
	std::string_view str("aöB?Äk#+ßl");
	auto lower = torquis::toupperc(str); // call string type: string_view
	CHECK(lower == "AöB?ÄK#+ßL");
}

TEST_CASE("toupper/char/by-cstring/4")
{
	std::string str("aöB?Äk#+ßl");
	auto lower = torquis::toupperc(str); // call string type: string
	CHECK(lower == "AöB?ÄK#+ßL");
}

TEST_CASE("toupper/char/by-cstring/5")
{
	const char* str = "aöB?Äk#+ßl";
	auto lower = torquis::toupperc(str); // call string type: c-string
	CHECK(lower == "AöB?ÄK#+ßL");
}



/*
 * tests for character type: char
 */

TEST_CASE("toupper/wchar_t/by-cstring/0")
{
	std::wstring str;
	torquis::toupper(str); // call string type: string
	CHECK(str.empty());
}

TEST_CASE("toupper/wchar_t/by-cstring/1")
{
	std::wstring str(L"aöB?Äk#+ßl");
	torquis::toupper(str); // call string type: string
	CHECK(std::wstring(L"AöB?ÄK#+ßL") == str);
}

TEST_CASE("toupper/wchar_t/by-cstring/2")
{
	std::wstring str(L"aöB?Äk#+ßl");
	torquis::toupper(&str[0], str.length()); // call string type: c-string
	CHECK(std::wstring(L"AöB?ÄK#+ßL") == str);
}

TEST_CASE("toupper/wchar_t/by-cstring/3")
{
	std::wstring_view str(L"aöB?Äk#+ßl");
	auto lower = torquis::toupperc(str); // call string type: string_view
	CHECK(lower == L"AöB?ÄK#+ßL");
}

TEST_CASE("toupper/wchar_t/by-cstring/4")
{
	std::wstring str(L"aöB?Äk#+ßl");
	auto lower = torquis::toupperc(str); // call string type: string
	CHECK(lower == L"AöB?ÄK#+ßL");
}

TEST_CASE("toupper/wchar_t/by-cstring/5")
{
	const wchar_t* str = L"aöB?Äk#+ßl";
	auto lower = torquis::toupperc(str); // call string type: c-string
	CHECK(lower == L"AöB?ÄK#+ßL");
}
