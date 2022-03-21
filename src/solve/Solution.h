/*
 * Solution.h
 *
 *  Created on: Mar 19, 2022
 *      Author: Serhat
 */

#ifndef SOLUTION_H_
#define SOLUTION_H_

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <Client.h>

using namespace std;

class Solution {

public:
	static vector<Client> vClients;
	static set<string> sIngredients;
	static set<string> sLikedIngredients;
	static set<string> sDislikedIngredients;

	static vector<string> exec();
	static void initialize();
	static bool addClientChoice(Client c);
};

#endif /* SOLUTION_H_ */
