#include"control.h"

void Control::ConnectDatabase()
{
	mysql = mysql_init(NULL);
	if(mysql_real_connect(mysql, "localhost", "root", "8023xue0526", "vote_system", 0, NULL, 0) == NULL)
		out.DatabaseError(mysql);
}
void Control::EnterVoteSystem()
{
	while(1){
	out.MainMenu();
	int choice;
	in.ChooseChoice(choice);

		switch(choice){
			case 1:
				ElectorSignIntoSystem();
				break;
			case 2:
				RegisterElector();
				break;
			case 3:
				ManageCandidate();
				break;
			case 4:
				return;
			default:
				out.WrongChoiceError();
		}
	}
}

void Control::RegisterElector()
{
	out.RegisterElectorMenu();
	string id, name, password;
	in.ElectorInfo(id, name, password);
	
	Elector new_elector(id, password, name, mysql);
}
void Control::ElectorSignIntoSystem()
{
	out.SignInMenu();
	string id, password;
	in.SignInInfo(id, password);
	Elector elector(id, password, mysql);
//	if(elector.id == "NULL")
//		return;
	ElectorOperation(elector);
}

void Control::ManageCandidate()
{
	while(1){
		out.ManagementMenu();
		int choice;
		in.ChooseChoice(choice);
		switch(choice){
			case 1:
				{
					string candidate_name;
					out.AddCandidateMenu();
					in.CandidateInfo(candidate_name);
					Candidate candidate(candidate_name, mysql);
					break;
				}
			case 2:
				{
					string candidate_id;
					out.ModifyCandidateMenu();
					in.CandidateId(candidate_id);
					Candidate can(candidate_id, 1, mysql);
					string candidate_name;
					in.CandidateName(candidate_name);
					can.ModifyInfo(candidate_name, mysql);
					break;
				}
			case 3:
				{
					string candidate_id;
					out.DeleteCandidateMenu();
					in.CandidateId(candidate_id);
					Candidate can(candidate_id, 1, mysql);
					can.Delete(mysql);
				}
				break;
			case 4:
				break;
			case 5:
				return;
			default:
				break;
		}
	}
}
void Control::ElectorOperation(Elector &elector)
{
	string candidate_id;
	string candidate_name;
	while(1){
		out.ElectorOperationMenu();
		int choice;
		in.ChooseChoice(choice);
		switch(choice){
			case 1:
				out.VoteMenu();
				in.ChooseCandidate(candidate_id);
				elector.VoteBallot(candidate_id, mysql);
				break;
			case 2:
				out.ModifyBallotMenu();
				in.CandidateName(candidate_name);
				break;
		}
	}
}
