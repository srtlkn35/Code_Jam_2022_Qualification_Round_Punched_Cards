/*
 * FileIO.h
 *
 *  Created on: Mar 19, 2022
 *      Author: Serhat
 */

#ifndef FILEIO_H_
#define FILEIO_H_

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <dirent.h>
#include <filesystem>

using namespace std;

class FileIO {

private:

	const static bool FILEIO_PRINT_INPUT_FILELINES = false;
	const static bool FILEIO_PRINT_OUTPUT_FILELINES = false;

	string sInputFilename;
	string sOutputFilename;
	vector<string> vInputFileLines;
	vector<string> vOutputFileLines;

public:

	const string& getSInputFilename() const;
	void setSInputFilename(const string &sInputFilename);
	const string& getSOutputFilename() const;
	void setSOutputFilename(const string &sOutputFilename);
	const vector<string>& getVInputFileLines() const;
	void setVInputFileLines(const vector<string> &vInputFileLines);
	const vector<string>& getVOutputFileLines() const;
	void setVOutputFileLines(const vector<string> &vOutputFileLines);

	FileIO(const string &sInputFilename, const string &sOutputFilename);

	string getCurrentDirectory();
	void readFile();
	void writeFile();
};

#endif /* FILEIO_H_ */
