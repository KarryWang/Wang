#ifndef CANDIDATE_H
#define CANDIDATE_H
#include<iostream>
#include<string>
using namespace std;
class Candidate{
public:
	Candidate(string candidate_id, string candidate_name);
	Candidate();
private: 
	string id;
	string name;
};
#endif
