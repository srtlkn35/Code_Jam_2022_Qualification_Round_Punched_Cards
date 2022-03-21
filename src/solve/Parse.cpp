/*
 * Parse.cpp
 *
 *  Created on: Mar 19, 2022
 *      Author: Serhat
 */

#include <Parse.h>
#include <Solution.h>
#include <Client.h>

void Parse::exec(const vector<string> &vInputFileLines) {

	vector<string> likes;
	vector<string> dislikes;
	int numOfClient = stoi(vInputFileLines.front());

	Solution::initialize();
	Client::initialize();

	for (int i = 0; i < numOfClient; i++) {

		likes = split(vInputFileLines.at((2 * i) + 1), ' ');
		likes.erase(likes.begin());

		dislikes = split(vInputFileLines.at((2 * i) + 2), ' ');
		dislikes.erase(dislikes.begin());

		Client *c = new Client(likes, dislikes);
		Solution::vClients.push_back(*c);
		Solution::sIngredients.insert(likes.begin(), likes.end());
		Solution::sIngredients.insert(dislikes.begin(), dislikes.end());
	}
}

vector<string> Parse::split(string const &str, char delim) {

    vector<string> tokens;
    size_t start;
    size_t end = 0;

    while ((start = str.find_first_not_of(delim, end)) != string::npos) {
        end = str.find(delim, start);
        tokens.push_back(str.substr(start, end - start));
    }

    return tokens;
}
