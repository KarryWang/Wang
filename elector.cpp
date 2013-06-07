#include"elector.h"


Elector::Elector(string elector_id, string elector_password, string elector_name, MYSQL *mysql)
{
	Output out;
	id = elector_id;
	name = elector_name;
	password = elector_password;

	char char_id[kCharArrayLength];
	memset(char_id, 0, sizeof(char_id));
	int i = 0;
	for(string::iterator it = id.begin(); it != id.end(); it++)
		char_id[i++] = *it;
	char char_password[kCharArrayLength];
	memset(char_password, 0, sizeof(char_password));
	i = 0;
	for(string::iterator it = password.begin(); it != password.end(); it++)
		char_password[i++] = *it;
	char char_name[kCharArrayLength];
	memset(char_name, 0, sizeof(char_name));
	i = 0;
	for(string::iterator it = name.begin(); it != name.end(); it++)
		char_name[i++] = *it;
	char sql[kSqlStatementLength];
	memset(sql, 0, sizeof(sql));
	sprintf(sql, "insert into elector values('%s', '%s', '%s')", char_id, char_name, char_password);
	cout << "sql: " << sql << endl;
	if(mysql_query(mysql, sql)){
//		cout << "ERROR: " << mysql_errno(mysql) << mysql_error(mysql) << endl;
		out.DatabaseError(mysql);
		exit(false);
	}
}
Elector::Elector(string elector_id, string elector_password, MYSQL *mysql)
{
	char char_elector_id[kCharArrayLength];
	memset(char_elector_id, 0, sizeof(char_elector_id));
	int i = 0;
	for(string::iterator it = elector_id.begin(); it != elector_id.end(); it++)
		char_elector_id[i++] = *it;
	char char_elector_password[kCharArrayLength];
	memset(char_elector_password, 0, sizeof(char_elector_password));
	i = 0;
	for(string::iterator it = elector_password.begin(); it != elector_password.end(); it++)
		char_elector_password[i++] = *it;
	char sql[kSqlStatementLength];
	memset(sql, 0, sizeof(sql));
	sprintf(sql, "select * from elector where id = '%s' and password = '%s'", char_elector_id, char_elector_password);

	if(mysql_query(mysql, sql)){
		cout << "ERROR: " << mysql_errno(mysql) << mysql_error(mysql) << endl;
		exit(false);
	}
	MYSQL_RES *result = mysql_store_result(mysql);
	if(result == NULL){
		cout << "ERROR: " << mysql_errno(mysql) << mysql_error(mysql) << endl;
		exit(false);
	}
	if(mysql_field_count(mysql) == 0){
		cout << "There is no this elector!" << endl;
		id = "NULL";
		name = "NULL";
		password = "NULL";
	}
	else{

	MYSQL_ROW row = mysql_fetch_row(result);
	if(row == NULL){
		cout << "Error: " << mysql_errno(mysql) << mysql_error(mysql) << endl;
		exit(false);
	}
	id = row[0];
	name = row[1];
	password = row[2];
	}
}
void Elector::VoteBallot(string candidate_name, MYSQL *mysql)
{
	Ballot new_ballot(name, candidate_name, mysql);
	new_ballot.DisplayInfo();
}
void Elector::ModifyBallot(string ballot_id, string new_candidate_name, MYSQL *mysql)
{
	Ballot ballot(ballot_id, mysql);
	ballot.ModifyInfo(new_candidate_name, mysql);
}

void Elector::ModifyPassword(string new_password, MYSQL *mysql)
{
	char char_id[kCharArrayLength];
	memset(char_id, 0, sizeof(char_id));
	int i = 0;
	for(string::iterator it = id.begin(); it != id.end(); it++)
		char_id[i++] = *it;
	char char_new_password[kCharArrayLength];
	memset(char_new_password, 0, sizeof(char_new_password));
	i = 0;
	for(string::iterator it = new_password.begin(); it != new_password.end(); it++)
		char_new_password[i++] = *it;
	char sql[kSqlStatementLength];
	memset(sql, 0, sizeof(sql));
	sprintf(sql, "update elector set password = '%s' where id = '%s'", char_new_password, char_id);
	if(mysql_query(mysql, sql)){
		cout << "ERROR: " << mysql_errno(mysql) << mysql_error(mysql) << endl;
		exit(false);
	}
}

void Elector::DeleteBallot(string ballot_id, MYSQL *mysql)
{
	Ballot ballot(ballot_id, mysql);
	ballot.Delete(mysql);
}

void Elector::DisplayAllBallots(MYSQL *mysql)
{
	vector<Ballot> ballots;

	char char_name[kCharArrayLength];
	memset(char_name, 0, sizeof(char_name));
	int i = 0;
	for(string::iterator it = name.begin(); it != name.end(); it++)
		char_name[i++] = *it;
	char sql[kSqlStatementLength];
	memset(sql, 0, sizeof(sql));
	sprintf(sql, "select * from ballot where elector_name = '%s'", char_name);
	if(mysql_query(mysql, sql)){
		cout << "ERROR: " << mysql_errno(mysql) << mysql_error(mysql) << endl;
		exit(false);
	}
	MYSQL_RES *result = mysql_store_result(mysql);
   if(result == NULL){
		cout << "ERROR: " << mysql_errno(mysql) << mysql_error(mysql) << endl;
		exit(false);
   }

   MYSQL_ROW row;
   while((row = mysql_fetch_row(result))){
	   Ballot temp(row[0], mysql);
	   ballots.push_back(temp);
   }
 //  for(vector::iterator it = ballots.begin(); it != ballots.end(); it++)
//	   *it.DisplayInfo();
}
