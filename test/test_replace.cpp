//
// Created by core on 05/03/2021.
//

#include <catch2/catch.hpp>
#include <cstring>

#define TORQUIS_INCLUDE_GUARD
#include <include/torquis/replace.hpp>
#undef TORQUIS_INCLUDE_GUARD


TEST_CASE("replace/char/0")
{
	{
		const char* str("one one was a race horse, two two was one too.");
		auto repl = torquis::replace(str, "one", "three");
		CHECK(repl == "three three was a race horse, two two was three too.");
	}
	{
		const char* str("aaa");
		auto repl = torquis::replace(str, "a", "b");
		CHECK(repl == "bbb");
	}
	{
		const char* str("ababab");
		auto repl = torquis::replace(str, "ab", "b");
		CHECK(repl == "bbb");
	}
	{
		const char* str("aaa");
		auto repl = torquis::replace(str, "aa", "b");
		CHECK(repl == "ba");
	}
	{
		const char* str("abbbb");
		auto repl = torquis::replace(str, "abb", "a");
		CHECK(repl == "abb");
		auto repl2 = torquis::replace(repl, "abb", "a");
		CHECK(repl2 == "a");
	}
}

TEST_CASE("replace/wchar_t/0")
{
	{
		const wchar_t* str(L"one one was a race horse, two two was one too.");
		auto repl = torquis::replace(str, L"one", L"three");
		CHECK(repl == L"three three was a race horse, two two was three too.");
	}
	{
		const wchar_t* str(L"aaa");
		auto repl = torquis::replace(str, L"a", L"b");
		CHECK(repl == L"bbb");
	}
	{
		const wchar_t* str(L"ababab");
		auto repl = torquis::replace(str, L"ab", L"b");
		CHECK(repl == L"bbb");
	}
	{
		const wchar_t* str(L"aaa");
		auto repl = torquis::replace(str, L"aa", L"b");
		CHECK(repl == L"ba");
	}
	{
		const wchar_t* str(L"abbbb");
		auto repl = torquis::replace(str, L"abb", L"a");
		CHECK(repl == L"abb");
		auto repl2 = torquis::replace(repl, L"abb", L"a");
		CHECK(repl2 == L"a");
	}
}
