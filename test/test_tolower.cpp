//
// Created by core on 10/02/2021.
//

#include <cstring>
#include <catch2/catch_test_macros.hpp>
#include <torquis.hpp>


/*
 * tests for character type: char
 */

TEST_CASE("tolower/char/by-cstring/0")
{
	std::string str;
	torquis::tolower(str); // call string type: string
	CHECK(str.empty());
}

TEST_CASE("tolower/char/by-cstring/1")
{
	std::string str("aöB?Ä#+ßQ");
	torquis::tolower(str); // call string type: string
	CHECK(std::string("aöb?Ä#+ßq") == str);
}

TEST_CASE("tolower/char/by-cstring/2")
{
	std::string str("aöB?Ä#+ßQ");
	torquis::tolower(&str[0], str.length()); // call string type: c-string
	CHECK(std::string("aöb?Ä#+ßq") == str);
}

TEST_CASE("tolower/char/by-cstring/3")
{
	std::string_view str("aöB?Ä#+ßQ");
	auto lower = torquis::tolowerc(str); // call string type: string_view
	CHECK(lower == "aöb?Ä#+ßq");
}

TEST_CASE("tolower/char/by-cstring/4")
{
	std::string str("aöB?Ä#+ßQ");
	auto lower = torquis::tolowerc(str); // call string type: string
	CHECK(lower == "aöb?Ä#+ßq");
}

TEST_CASE("tolower/char/by-cstring/5")
{
	const char* str = "aöB?Ä#+ßQ";
	auto lower = torquis::tolowerc(str); // call string type: c-string
	CHECK(lower == "aöb?Ä#+ßq");
}



/*
 * tests for character type: wchar_t
 */

TEST_CASE("tolower/wchar_t/by-cstring/0")
{
	std::wstring str;
	torquis::tolower(str); // call string type: string
	CHECK(str.empty());
}

TEST_CASE("tolower/wchar_t/by-cstring/1")
{
	std::wstring str(L"aöB?Ä#+ßQ");
	torquis::tolower(str); // call string type: string
	CHECK(std::wstring(L"aöb?Ä#+ßq") == str);
}

TEST_CASE("tolower/wchar_t/by-cstring/2")
{
	std::wstring str(L"aöB?Ä#+ßQ");
	torquis::tolower(&str[0], str.length()); // call string type: c-string
	CHECK(std::wstring(L"aöb?Ä#+ßq") == str);
}

TEST_CASE("tolower/wchar_t/by-cstring/3")
{
	std::wstring_view str(L"aöB?Ä#+ßQ");
	auto lower = torquis::tolowerc(str); // call string type: string_view
	CHECK(lower == L"aöb?Ä#+ßq");
}

TEST_CASE("tolower/wchar_t/by-cstring/4")
{
	std::wstring str(L"aöB?Ä#+ßQ");
	auto lower = torquis::tolowerc(str); // call string type: string
	CHECK(lower == L"aöb?Ä#+ßq");
}

TEST_CASE("tolower/wchar_t/by-cstring/5")
{
	const wchar_t* str = L"aöB?Ä#+ßQ";
	auto lower = torquis::tolowerc(str); // call string type: c-string
	CHECK(lower == L"aöb?Ä#+ßq");
}
