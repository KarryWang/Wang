#include"output.h"

void Output::MainMenu()
{
	cout << "\tMain Menu" << endl;
	cout << "*******************" << endl;
	cout << "** 1.Sign in     **" << endl;
	cout << "** 2.Register    **" << endl;
	cout << "** 3.ManageCan   **" << endl;
	cout << "** 4.Exit        **" << endl;
	cout << "*******************" << endl;
	cout << "choice: ";
}

void Output::RegisterElectorMenu()
{
	cout << "\tResgister Menu" << endl;
	cout << "*******************" << endl;
	cout << "Input Your ID:" << endl;
	cout << "Input Your name:" << endl;
	cout << "Input Your Password:" << endl;
	cout << "Reinput Your Password:" << endl;
}

void Output::SignInMenu()
{
	cout << "\tSign In" << endl;
	cout << "*******************" << endl;
	cout << "Input ID:" << endl;
	cout << "Input Password:" << endl;
}

void Output::ElectorOperationMenu()
{
	cout << "\tElector Operation" << endl;
	cout << "*************************" << endl;
	cout << "** 1.Vote				**" << endl;
	cout << "** 2.ModifyBallot		**" << endl;
	cout << "** 3.DeleteBallot		**" << endl;
	cout << "** 4.DisplayAllBallots **" << endl;
	cout << "** 5.ModifyPassword    **" << endl;
	cout << "*************************" << endl;
	cout << "your choice: " << endl;
}
void Output::VoteMenu()
{
	cout << "Input Candidate Id: " << endl;
}
void Output::ModifyBallotMenu()
{
	cout << "Input Ballot Id: " << endl;
}
void Output::DeleteBallotMenu()
{
	cout << "Input Ballot Id: " << endl;
}
void Output::ModifyPasswordMenu()
{
	cout << "Input new password: " << endl;
}
void Output::ManagementMenu()
{
	cout << "\tManage Menu" << endl;
	cout << "*************************" << endl;
	cout << "** 1.Add Candidate     **" << endl;
	cout << "** 2.Modify Candidate  **" << endl;
	cout << "** 3.Delete Candidate  **" << endl;
	cout << "** 4.Display Candidates**" << endl;
	cout << "** 5.Display All Ballot**" << endl;
	cout << "*************************" << endl;
	cout << "your choice: ";
}

void Output::AddCandidateMenu()
{
	cout << "************************" << endl;
	cout << "Input Candidate name:" << endl;
}
void Output::ModifyCandidateMenu()
{
	cout << "************************" << endl;
	cout << "Input Candidate Id:" << endl;
	cout << "Input new candidate info: " << endl;
}
void Output::DeleteCandidateMenu()
{
	cout << "************************" << endl;
	cout << "Input Candidate Id:" << endl;
}
void Output::DatabaseError(MYSQL *mysql)
{
	cout << "ERROR: " << mysql_errno(mysql) << mysql_error(mysql);
}

void Output::WrongChoiceError()
{
	cout << "Your Choice is Wrong!" << endl;
	cout << "Please choose again!" << endl;
}
