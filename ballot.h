#ifndef BALLOT_H
#define BALLOT_H
#include<iostream>
#include<ctime>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<mysql.h>
using namespace std;

class Ballot{
public:
	Ballot(string temp_elector_name, string temp_candidate_id, MYSQL *mysql);
	Ballot(string ballot_id, MYSQL *mysql);
	void ModifyInfo(string new_candidate_name, MYSQL *mysql);
	void Delete(MYSQL *mysql);
	void DisplayInfo();
private:
	string id;
	string elector_name;
	string candidate_id;
};

const int kMaxCandidateId = 100000000;
const int kSqlStatementLength = 1000;
const int kCharArrayLength = 100;
#endif
