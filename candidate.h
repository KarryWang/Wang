#ifndef CANDIDATE_H
#define CANDIDATE_H
#include<iostream>
#include<string>
using namespace std;
class Candidate{
public:
	Candidate(string name);
	Candidate();
private: 
	int id;
	string name;
};
#endif
