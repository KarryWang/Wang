#ifndef OUTPUT_H
#define OUTPUT_H
#include<iostream>
#include<mysql.h>
using namespace std;

class Output{
public:
	void MainMenu();
	void RegisterElectorMenu();

	void SignInMenu();
	void ElectorOperationMenu();
	void VoteMenu();
	void ModifyBallotMenu();
	void DeleteBallotMenu();
	void ModifyPasswordMenu();
	
	void ManagementMenu();
	void AddCandidateMenu();
	void DatabaseError(MYSQL *mysql);
	void WrongChoiceError();
};
#endif
