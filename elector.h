#ifndef ELECTOR_H
#define ELECTOR_H
#include<iostream>
#include<string>
//#include<mysql.h>
//#include<cstring>
//#include<cstdlib>
#include<vector>
#include"ballot.h"
#include"output.h"
using namespace std;

class Elector{
public:
	Elector(){};
	Elector(string elector_id, string elector_password, string elector_name, MYSQL *mysql);
	Elector(string elector_id, string elector_password, MYSQL *mysql);
	void VoteBallot(string candidate_name, MYSQL *mysql);
	void ModifyBallot(string ballot_id, string new_candidate_name, MYSQL *mysql);
	void ModifyPassword(string new_password, MYSQL *mysql);
	void DeleteBallot(string ballot_id, MYSQL *mysql);
	void DisplayAllBallots(MYSQL *mysql);
private:
	string id;
	string password;
	string name;
};
#endif
