#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "csv.hpp"

// -- CONSTS -- //
const std::string FOO_FILE_NAME = "foo";
const std::string SQUARE_TEST_1_FILE = "../csv_files/square_test_1.csv";
const std::string EMPTY_FILE = "../csv_files/empty.csv";
const std::string EASY_1_FILE = "../csv_files/easy_1.csv";

TEST_CASE("Base 'Parser' being tested for construction input", "[parser][fileio]") {
	SECTION("Check for correct file exsistence behavior" "[fileio][throws]") {
		REQUIRE_THROWS_AS(CSV::Parser(FOO_FILE_NAME), std::invalid_argument);

		CHECK_NOTHROW(CSV::Parser(SQUARE_TEST_1_FILE));
		CHECK_NOTHROW(CSV::Parser(EMPTY_FILE));
	}
}

TEST_CASE("Base 'Parser' testing the header row matches.") {
	CSV::Parser parser1(SQUARE_TEST_1_FILE);
	CSV::Parser parser2(EASY_1_FILE);

	SECTION("Test easy header rows with good input files.") {
		CHECK_THAT(parser1.HeaderColumnName(), Catch::Matchers::Equals(std::vector<std::string>{"Foo","Bar","BarFoo","MyFoo","MyBar"}));
		CHECK_THAT(parser2.HeaderColumnName(), Catch::Matchers::Equals(std::vector<std::string>{"test","test1"}));
	}

	SECTION("Test malformed or non square files.") {

	}
}
