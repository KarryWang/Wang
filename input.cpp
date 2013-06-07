#include"input.h"

void Input::ChooseChoice(int &choice)
{
	cin >> choice;
}

void Input::ElectorInfo(string &id, string &name, string &password)
{
	cin >> id >> name >> password;
}

void Input::SignInInfo(string &id, string &password)
{
	cin >> id >> password;
}

void Input::ChooseCandidate(string &candidate_id)
{
	cin >> candidate_id;
}
void Input::CandidateInfo(string &name)
{
	char temp[100];
	cin >> temp;
	name = temp;
}
//ballot
void Input::CandidateName(string &name)
{
	char temp[100];
	cin >> temp;
	name = temp;
}
void Input::BallotId(string &id)
{
	cin >> id;
}
void Input::BallotNewPassword(string &password)
{
	cin >> password;
}
