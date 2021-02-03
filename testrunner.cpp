//
// Created by core on 03/02/2021.
//

#define CATCH_CONFIG_EXTERNAL_INTERFACES
#define CATCH_CONFIG_RUNNER
#include <catch2/catch.hpp>
#include <torquis.hpp>

int main(int argc, char* argv[])
{
	return Catch::Session().run(argc, argv);
}

TEST_CASE("split - by character - 0")
{
	const auto str1 = "";
	const auto split1 = torquis::split({ str1 }, '#');
	REQUIRE(split1.size() == 1);
	CHECK(split1[0] == "");
}

TEST_CASE("split - by character - 1")
{
	const auto str1 = "abc#def#ghi";
	const auto split1 = torquis::split({ str1 }, '#');
	REQUIRE(split1.size() == 3);
	CHECK(split1[0] == "abc");
	CHECK(split1[1] == "def");
	CHECK(split1[2] == "ghi");
}

TEST_CASE("split - by character - 2")
{
	const auto str1 = "#abc#def#ghi##";
	const auto split1 = torquis::split({ str1 }, '#');
	REQUIRE(split1.size() == 6);
	CHECK(split1[0] == "");
	CHECK(split1[1] == "abc");
	CHECK(split1[2] == "def");
	CHECK(split1[3] == "ghi");
	CHECK(split1[4] == "");
	CHECK(split1[5] == "");
}

TEST_CASE("split - by character - 3")
{
	const auto str1 = "###";
	const auto split1 = torquis::split({ str1 }, '#');
	REQUIRE(split1.size() == 4);
	CHECK(split1[0] == "");
	CHECK(split1[1] == "");
	CHECK(split1[2] == "");
	CHECK(split1[3] == "");
}

TEST_CASE("split - by string - 0")
{
	const auto str1 = "";
	const auto delim = "-#";
	const auto split1 = torquis::split({ str1 }, std::string_view(delim));
	REQUIRE(split1.size() == 1);
	CHECK(split1[0] == "");
}

TEST_CASE("split - by string - 1")
{
	const auto str1 = "abc";
	const auto delim = "";
	const auto split1 = torquis::split({ str1 }, std::string_view(delim));
	REQUIRE(split1.size() == 3);
	CHECK(split1[0] == "a");
	CHECK(split1[1] == "b");
	CHECK(split1[2] == "c");
}

TEST_CASE("split - by string - 2")
{
	const auto str1 = "a-bc-#de#f-#g-h#i";
	const auto delim = "-#";
	const auto split1 = torquis::split({ str1 }, std::string_view(delim));
	REQUIRE(split1.size() == 3);
	CHECK(split1[0] == "a-bc");
	CHECK(split1[1] == "de#f");
	CHECK(split1[2] == "g-h#i");
}

TEST_CASE("split - by string - 3")
{
	const auto str1 = "-#abc--##def--##ghi-#-#";
	const auto delim = "-#";
	const auto split1 = torquis::split({ str1 }, std::string_view(delim));
	REQUIRE(split1.size() == 6);
	CHECK(split1[0] == "");
	CHECK(split1[1] == "abc-");
	CHECK(split1[2] == "#def-");
	CHECK(split1[3] == "#ghi");
	CHECK(split1[4] == "");
	CHECK(split1[5] == "");
}

TEST_CASE("split - by string - 4")
{
	const auto str1 = "-#-#-#";
	const auto delim = "-#";
	const auto split1 = torquis::split({ str1 }, std::string_view(delim));
	REQUIRE(split1.size() == 4);
	CHECK(split1[0] == "");
	CHECK(split1[1] == "");
	CHECK(split1[2] == "");
	CHECK(split1[3] == "");
}