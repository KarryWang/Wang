#ifndef CONTROL_H
#define CONTROL_H
#include<iostream>
#include<mysql.h>
#include<string>
#include"candidate.h"
#include"elector.h"
#include"input.h"
#include"output.h"


class Control{
public:
	void ConnectDatabase();
	void EnterVoteSystem();
	void RegisterElector();
	void ElectorSignIntoSystem();
	void ManageCandidate();
	void ElectorOperation(Elector &elector);
private:
	MYSQL *mysql;
	Output out;
	Input in;
	Candidate candidate;
	Elector elector;
};
#endif
