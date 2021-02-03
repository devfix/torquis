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
