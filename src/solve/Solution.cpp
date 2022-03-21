/*
 * Solution.cpp
 *
 *  Created on: Mar 19, 2022
 *      Author: Serhat
 */

#include <Solution.h>

vector<Client> Solution::vClients;
set<string> Solution::sIngredients;
set<string> Solution::sLikedIngredients;
set<string> Solution::sDislikedIngredients;

vector<string> Solution::exec() {

	vector<string> output;
	string tmpStr = "";

	/********************************************************/
	/********************************************************/
	/********************************************************/

	for(vector<Client>::iterator it = vClients.begin(); it != vClients.end(); it++) {
		(*it).calculateRank();
	}

	sort(vClients.begin(), vClients.end());

	for(vector<Client>::iterator it = vClients.begin(); it != vClients.end(); it++) {
		Client c = *it;
		addClientChoice(c);
	}

	tmpStr += to_string(sLikedIngredients.size());
	for(set<string>::iterator it = sLikedIngredients.begin(); it != sLikedIngredients.end(); it++) {
		tmpStr += " " + *it;
	}

	/********************************************************/
	/********************************************************/
	/********************************************************/

	output.push_back(tmpStr);
	return output;
}

void Solution::initialize() {

	vClients.clear();
	sIngredients.clear();
	sLikedIngredients.clear();
	sDislikedIngredients.clear();
}

bool Solution::addClientChoice(Client c) {

	for(auto it = c.getVLikes().begin(); it != c.getVLikes().end(); it++) {
		string s = *it;
		if (sDislikedIngredients.count(s)) {
			return false;
		}
	}
	sLikedIngredients.insert(c.getVLikes().begin(), c.getVLikes().end());
	sDislikedIngredients.insert(c.getVDislikes().begin(), c.getVDislikes().end());
	return true;
}
