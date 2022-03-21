/*
 * Client.cpp
 *
 *  Created on: Mar 19, 2022
 *      Author: Serhat
 */

#include <Client.h>

int Client::iTotalLikes = 0;
int Client::iTotalDislikes = 0;

float Client::getIRank() const {
	return iRank;
}

void Client::setIRank(float iRank) {
	this->iRank = iRank;
}

const vector<string>& Client::getVDislikes() const {
	return vDislikes;
}

void Client::setVDislikes(const vector<string> &vDislikes) {
	this->vDislikes = vDislikes;
}

const vector<string>& Client::getVLikes() const {
	return vLikes;
}

void Client::setVLikes(const vector<string> &vLikes) {
	this->vLikes = vLikes;
}

Client::Client(vector<string> vLikes, vector<string> vDislikes) {

	this->vLikes = vLikes;
	this->vDislikes = vDislikes;
	this->iRank = 0;
	iTotalLikes += vLikes.size();
	iTotalDislikes += vDislikes.size();
}

void Client::calculateRank() {

	float iLikeRank = (float) this->vLikes.size() / iTotalLikes;
	float iDislikeRank = 1 - ((float) this->vDislikes.size() / iTotalDislikes);
	this->iRank = iLikeRank + iDislikeRank;
}

bool Client::operator<(const Client &other) const {
    return getIRank() > other.getIRank();
}

void Client::initialize() {
	iTotalLikes = 0;
	iTotalDislikes = 0;
}
