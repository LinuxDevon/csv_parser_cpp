/*
	This is the header source file for the csv reader / dictionary classes.

	MIT License

	Copyright (c) 2020 LinuxDevon

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.
 */

// -- INCLUDES -- //
#include <string>
#include <exception>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>

#include <iostream>

// -- DEFUALTS -- //
#define DEFAULT_HEADER_ROW 0
#define DEFAULT_LINE_DELIMITER ','
#define DEFAULT_LINE_ENDING '\r\n'

namespace String {

template <class Container>
void Split(const std::string& str, Container& cont, char delim = ' ')
{
	std::stringstream ss(str);
	std::string token;
	while (std::getline(ss, token, delim)) {
		cont.push_back(token);
	}
}

}


namespace CSV {

class Dialect {
public:

protected:
	const char delimiter;
	const bool doublequote;
	const char escapechar;
	const char lineending;
	const char quotechar;
	// const char quoting;
	const bool skipinitialspace;
	// const bool strict;
private:

};

class Sniffer {
public:
	Dialect Sniff(const std::string filename, const char delimiters);
	Dialect Sniff(const std::string filename);
	bool	HasHeader(const std::string filename);
protected:

private:

};

class Parser {
public:
	// TODO: Make this pass in if it should throw
	Parser(const std::string filename) noexcept(false) : FileName(filename) {
		// Open the given file into a stream
		InFile.open(FileName, std::ifstream::in);

		// Check file and throw if file is bad
		if(InFile.bad()){
			throw std::invalid_argument("Error reading the given input file. Reading and writing operation fail.");
		} else if(InFile.fail()) {
			throw std::invalid_argument("Error reading the given input file. Malformatted file or non exsistent file.");
		} else if(InFile.eof()) {
			throw std::invalid_argument("Error reading the given input file. End of file reached which means it was empty.");
		}

		HeaderRowNumber = FindHeaderRow();
	}

	~Parser() {}

	const std::vector<std::string> & HeaderColumnName() {
		return HeaderNames;
	}

protected:
	// -- CONST VARIABLES -- //
	const std::string FileName; ///< Name of the file to try and parse. This is given by the user

	// -- VARIABLES -- //
	std::ifstream InFile;       ///< The read only file of the input file name
	unsigned HeaderRowNumber;   ///< The row number of the header in the file
	std::vector<std::string> HeaderNames; ///< list of the header string names
	bool HasRowHeader;			///< Indicates if a header row exsists

private:

	unsigned FindHeaderRow() {
		std::string temp_line;
		// TODO: Assumed that the header was first. Need to add a finder to try and detect
		// TODO: Add in a BOM Detection
		// TODO: Check line ending to parse with. i.e. (CRLF, LF)(Unix, Dos, MacOS)
		std::getline(InFile, temp_line);

		String::Split<std::vector<std::string>>(temp_line, HeaderNames, ',');

		return 0;
	}

};

class Reader : public Parser {
public:
	Reader(const std::string filename) noexcept(false) : Parser(filename) {

	}

	bool NextLine();

protected:

private:

};

/*class dict {
public:
	dict( void ) {}

protected:

private:

};*/

}

