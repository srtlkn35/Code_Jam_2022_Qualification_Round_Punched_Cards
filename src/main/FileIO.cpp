/*
 * FileIO.cpp
 *
 *  Created on: Mar 14, 2022
 *      Author: Serhat
 */

#include <FileIO.h>
#include <filesystem>

using namespace std;

const string& FileIO::getSInputFilename() const {
	return sInputFilename;
}

void FileIO::setSInputFilename(const string &sInputFilename) {
	this->sInputFilename = sInputFilename;
}

const string& FileIO::getSOutputFilename() const {
	return sOutputFilename;
}

void FileIO::setSOutputFilename(const string &sOutputFilename) {
	this->sOutputFilename = sOutputFilename;
}

const vector<string>& FileIO::getVInputFileLines() const {
	return vInputFileLines;
}

void FileIO::setVInputFileLines(const vector<string> &vInputFileLines) {
	this->vInputFileLines = vInputFileLines;
}

const vector<string>& FileIO::getVOutputFileLines() const {
	return vOutputFileLines;
}

void FileIO::setVOutputFileLines(const vector<string> &vOutputFileLines) {
	this->vOutputFileLines = vOutputFileLines;
}

FileIO::FileIO(const string &sInputFilename, const string &sOutputFilename) {

	this->sInputFilename = sInputFilename;
	this->sOutputFilename = sOutputFilename;
}

string FileIO::getCurrentDirectory() {

    //string working_directory(std::filesystem::current_path());
	
    char* cwd = _getcwd( 0, 0 );
    std::string working_directory(cwd) ;
    std::free(cwd) ;

    return working_directory;
}

void FileIO::readFile() {

	ifstream file;
	string line;

	file.open(this->sInputFilename.c_str());

	while(getline(file, line)){
		this->vInputFileLines.push_back(line);
	}

	file.close();

	if (FILEIO_PRINT_INPUT_FILELINES == true) {
		cout << "****** File: '" + this->sInputFilename + "' (CurrDir:'" << getCurrentDirectory() << "')" << endl;
		for(vector<string>::iterator it = this->vInputFileLines.begin(); it != this->vInputFileLines.end(); it++) {
			cout << *it << endl;
		}
    	cout << "******" << endl;
    	cout << endl;
	}
}

void FileIO::writeFile() {

	ofstream file;

	file.open(this->sOutputFilename.c_str());

	for(unsigned int i=0;i<this->vOutputFileLines.size();++i){
		file << this->vOutputFileLines[i] << endl;
	}

	file.close();

	if (FILEIO_PRINT_OUTPUT_FILELINES == true) {
		cout << "****** File: '" + this->sOutputFilename + "' (CurrDir:'" << getCurrentDirectory() << "')" << endl;
		for(vector<string>::iterator it = this->vOutputFileLines.begin(); it != this->vOutputFileLines.end(); it++) {
			cout << *it << endl;
		}
    	cout << "******" << endl;
    	cout << endl;
	}
}
