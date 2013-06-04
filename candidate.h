#ifndef CANDIDATE_H
#define CANDIDATE_H
#include<iostream>
#include<string>
#include<mysql.h>

using namespace std;

class Candidate{
public:
	Candidate(string candidate_id, string candidate_name, MYSQL *conn);
	Candidate(string candidate_id, MYSQL *conn);
private: 
	string id;
	string name;
};

#endif
