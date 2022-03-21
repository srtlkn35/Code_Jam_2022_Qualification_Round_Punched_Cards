//============================================================================
// Name        : Hash_Code_2022_Practice_Round_2.cpp
// Author      : Serhat Alkan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <iomanip>
#include<dirent.h>
#include <FileIO.h>
#include <Parse.h>
#include <Solution.h>

using namespace std;

int main(int argc, char** argv) {

	clock_t start, end;
	double time_taken;

	start = clock();

    DIR *dir; struct dirent *diread;
    if ((dir = opendir("input/")) != nullptr) {
        while ((diread = readdir(dir)) != nullptr) {
			if (string(diread->d_name).substr(string(diread->d_name).find_last_of(".") + 1) != "txt") {
				continue;
			}
    		string sInputFilename = "input/" + string(diread->d_name);
    		string sOutputFilename = "output/" + string(diread->d_name);
    		sOutputFilename.replace(sOutputFilename.find(".txt"), string(".txt").size(), "_report.txt");
    		FileIO *fileio = new FileIO(sInputFilename, sOutputFilename);
    		fileio->readFile();
    		Parse::exec(fileio->getVInputFileLines());
    		fileio->setVOutputFileLines(Solution::exec());
    		fileio->writeFile();
        }
        closedir(dir);
    }

	end = clock();
    time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Exec Time (sec): " << fixed << time_taken << setprecision(5) << endl;

	return 0;
}
