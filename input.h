#ifndef INPUT_H
#define INPUT_H
#include<iostream>
using namespace std;

class Input{
public:
	void ChooseChoice(int &choice);
	void ElectorInfo(string &id, string &name, string &password);
	void SignInInfo(string &id, string &password);
	void ChooseCandidate(string &candidate_id);
	void CandidateInfo(string &name);
	void CandidateName(string &name);
	void BallotId(string &id);
	void BallotNewPassword(string &password);
private:
};
#endif
