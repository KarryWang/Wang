#ifndef BALLOT_H
#define BALLOT_H
#include<string>

class Ballot{
public:
	Ballot(string elector_name_, string candidate_name_, MYSQL *mysql);
	Ballot(string ballot_id, MYSQL *mysql);
	void ModifyInfo(string candidate_name_, MYSQL *mysql);
	void Delete(MYSQL *mysql);
	void DisplayInfo();
private:
	string id;
	string elector_name;
	string candidate_name;
};

const int kSqlStatementLength = 1000;
const int kCharArrayLength = 100;
#endif
