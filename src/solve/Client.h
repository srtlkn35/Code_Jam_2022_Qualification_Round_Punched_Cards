/*
 * Client.h
 *
 *  Created on: Mar 19, 2022
 *      Author: Serhat
 */

#ifndef CLIENT_H_
#define CLIENT_H_

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

class Client {

private:

	static int iTotalLikes;
	static int iTotalDislikes;

	vector<string> vLikes;
	vector<string> vDislikes;
	float iRank;

public:

	float getIRank() const;
	void setIRank(float iRank);
	const vector<string>& getVDislikes() const;
	void setVDislikes(const vector<string> &vDislikes);
	const vector<string>& getVLikes() const;
	void setVLikes(const vector<string> &vLikes);

	Client(vector<string> vLikes, vector<string> vDislikes);

	bool operator<(const Client &other) const;
	void calculateRank();
	static void initialize();
};

#endif /* CLIENT_H_ */
