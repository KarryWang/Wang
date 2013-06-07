#ifndef CANDIDATE_H
#define CANDIDATE_H
#include<iostream>
#include<string>
#include<mysql.h>

using namespace std;

class Candidate{
public:
	Candidate(){};//
	Candidate(string candidate_name, MYSQL *mysql);
	Candidate(string candidate_id, int flag, MYSQL *mysql);
	void ModifyInfo(string new_candidate_name, MYSQL *mysql);
	void Delete(MYSQL *mysql);
	void DisplayInfo();
	void DisplayAllVotes(MYSQL *mysql);
private: 
	string id;
	string name;
	int vote_num;
};

#endif
