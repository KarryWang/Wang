#include"elector.h"
#include<cstdlib>
#include<vector>



Elector::Elector(string elector_id, string elector_password, string elector_name, MYSQL *mysql)
{
	id = elector_id;
	name = elector_name;

	char char_id[kCharArrayLength];
	memset(char_id, 0, sizeof(char_id));
	int i = 0;
	for(string::iterator it = id.begin(); it != id.end(); it++)
		char_id[i++] = *it;
	char char_name[kCharArrayLength];
	memset(char_name, 0, sizeof(char_name));
	i = 0;
	for(string::iterator it = name.begin(); it != name.end(); it++)
		char_name[i++] = *it;
	char sql[kSqlStatementLength];
	memset(sql, 0, sizeof(sql));
	sprintf(sql, "insert into elector values('%s', '%s')", id, name);
	if(mysql_query(mysql, sql)){
		cout << "ERROR: " << mysql_errno(mysql) << mysql_error(mysql) << endl;
		exit(false);
	}
}
Elector::Elector(string elector_id, MYSQL *mysql)
{
	char sql[kSqlStatementLength];
	memset(sql, 0, sizeof(sql));
	sprintf(sql, "select * from elector where id = '%s'", elector_id);

	if(mysql_query(mysql, sql)){
		cout << "ERROR: " << mysql_errno(mysql) << mysql_error(mysql) << endl;
		exit(false);
	}
	MYSQL_RES *result = msyql_store_result(mysql);
	if(result == NULL){
		cout << "ERROR: " << mysql_errno(mysql) << mysql_error(mysql) << endl;
		exit(false);
	}
	if(mysql_field_count(result) == 0){
		cout << "There is no this elector!" << endl;
		exit(0);
	}

	MYSQL_ROW row = mysql_fetch_row(result);
	if(row == NULL){
		cout << "Error: " << mysql_errno(mysql) << mysql_error(mysql) << endl;
		exit(false);
	}
	id = row[0];
	name = row[1];
	password = row[2];
}
void Elector::VoteBallot(string candidate_name, MYSQL *mysql)
{
	Ballot new_ballot(name, candidate_name, mysql);
	new_ballot.DisplayInfo();
}
void Elector::ModifyBallot(string ballot_id, string new_candidate_name, MYSQL *mysql)
{
	Ballot ballot(ballot_id, mysql);
	ballot.ModifyInfo(new_candidat_name, mysql);
}

void Elector::ModifyPassword(string new_password, MYSQL *mysql)
{
	char sql[kSqlStatementLength];
	memset(sql, 0, sizeof(sql));
	sprintf(sql, "update elector set password = '%s' where id = '%s'", new_password, id);
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

	char sql[kSqlStatementLength];
	memset(sql, 0, sizeof(sql));
	sprintf(sql, "select * from ballot where elector_name = '%s'", name);
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
   for(vector::iterator it = ballots.begin(); it != ballots.end(); it++)
	   *it.DisplayInfo();
}
