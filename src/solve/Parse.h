/*
 * Parse.h
 *
 *  Created on: Mar 19, 2022
 *      Author: Serhat
 */

#ifndef PARSE_H_
#define PARSE_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Parse {

public:

	static void exec(const vector<string> &vInputFileLines);
	static vector<string> split(string const &str, char delim);
};

#endif /* PARSE_H_ */
