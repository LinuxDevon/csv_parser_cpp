#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "csv.hpp"

// -- CONSTS -- //
const std::string FOO_FILE_NAME = "foo";		// Non exsistent file

const std::string EMPTY_FILE = "../csv_files/empty.csv";

// Unix encoded files
const std::string SQUARE_TEST_1_UNIX_FILE = "../csv_files/SquareTest1Unix.csv";
const std::string SQUARE_TEST_2_UNIX_FILE = "../csv_files/SquareTest1Unix.csv";


// -- PARSER -- //
TEST_CASE("Base 'PARSER' being tested for construction input", "[parser][fileio]") {
	SECTION("Check for correct file exsistence behavior" "[fileio][throws]") {
		REQUIRE_THROWS_AS(CSV::Parser(FOO_FILE_NAME), std::invalid_argument);

		CHECK_NOTHROW(CSV::Parser(SQUARE_TEST_1_UNIX_FILE));
		CHECK_NOTHROW(CSV::Parser(EMPTY_FILE));
	}
}

TEST_CASE("Base 'PARSER' testing the header row matches.", "[parser]") {
	CSV::Parser parser1(SQUARE_TEST_1_UNIX_FILE);
	CSV::Parser parser2(SQUARE_TEST_2_UNIX_FILE);

	SECTION("Easy header rows with good input files.") {
		CHECK_THAT(parser1.HeaderColumnName(), Catch::Matchers::Equals(std::vector<std::string>{"Foo","Bar","BarFoo","MyFoo","MyBar"}));
		CHECK_THAT(parser2.HeaderColumnName(), Catch::Matchers::Equals(std::vector<std::string>{"test","test1"}));
	}

	// Make sure that different file endings don't break finding the header
	SECTION("Different line endings such as Windows (CRLF), Unix (LF), and MacOS (CR)") {

	}

	// Some files that get output from Excel in UTF-8 have a BOM for some reason
	SECTION("Verify that files with Byte Order Mark (BOM)") {

	}

	SECTION("Verify that files of different Encodings") {

	}
}


// -- READER -- //
TEST_CASE("READER being tested for construction input", "[reader][fileio]") {

}
