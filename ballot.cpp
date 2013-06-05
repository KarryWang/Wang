#include"ballot.h"
#include<ctime>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<iostream>
using namespace std;

Ballot::Ballot(string elector_name_, string candidate_name_, MYSQL *mysql)
{
	while(1){
		srand((unsigned)time(NULL));//make a new id for candidate
		id = rand() % MAX_CANDIDATE_ID;
		cout << id << endl;

		char sql[kSqlStatementLength];
		memset(sql, 0, sizeof(sql));
		sprintf(sql, "select * from ballot where id = '%d'", id);
		if(mysql_query(mysql, sql)){
			cout << "ERROR: " << mysql_errno(mysql) << mysql_error(mysql) << endl;
			exit(false);
		}

		MYSQL_RES *result = mysql_store_result(mysql);
		if(mysql_field_count(result) == 0)
			break;
	}

	elector_name = elector_name_;
	candidate_name = candidate_name_;

	char char_id[kCharArrayLength];
	int i = 0;
	memset(char_id, 0, sizeof(char_id));
	for(string::iterator it = id.begin(); it != id.end(); it++)
		char_id[i++] = *it;
	
	char char_elector_name[kCharArrayLength];
	memset(char_elector_name, 0, sizeof(char_elector_name));
	i = 0;
	for(string::iterator it = elector_name.begin(); it != elector.end(); it++)
		char_elector_name[i++] = *it;

	char char_candidate_name[kCharArrayLength];
	memset(char_candidate_name, 0, sizeof(char_candidate_name));
	i = 0;
	for(string::iterator it = candidate_name.begin(); it != candidate_name.end(); it++)
		char_candidate_name[i++] = *it;

	char sql[kSqlStatementLength];
	memset(sql, 0, sizeof(sql));
	sprintf(sql, "insert into ballot values('%s', '%s', '%s')", char_id, char_elector_name, char_candidate_name);
	cout << " sql: " << sql << endl;
	if(mysql_query(mysql, sql)){
		cout << "ERROR: " << mysql_errno(mysql) << mysql_error(mysql) << endl;
		exit(false);
	}

}

Ballot::Ballot(string ballot_id, MYSQL *mysql)
{
	char sql[kSqlStatementLength];
	memset(sql, 0, sizeof(sql));
	sprintf(sql, "select * from ballot where id = '%s'", ballot_id);

	if(mysql_query(mysql, sql)){
		cout << "ERROR: " << mysql_errno(mysql) << mysql_error(mysql) << endl;
		exit(false);
	}
	MYSQL_RES *result = mysql_store_result(mysql);
	if(result == NULL){
		cout << "ERROR: " << mysql_errno(mysql) << mysql_error(mysql) << endl;
		exit(false);
	}
	if(mysql_field_count(result) == 0){
		cout << "There is no this ballot!" << endl;
		exit(false);
	}

	MYSQL_ROW row = mysql_fetch_row(result);
	id = row[0];
	elector_name = row[1];
	candidate_name = row[2];
	cout << "ballot_id: " << id << " " << elector_name << " " << candidate_name << endl;
}

void Ballot::ModifyInfo(string candidate_name_, MYSQL *mysql)
{
	DisplayInfo();
	candidate_name = candidate_name_;

	char sql[kSqlStatementLength];
	memset(sql, 0, sizeof(sql));
	sprintf(sql, "update ballot set candidate_name = '%s' where id = '%s'", candidate_name_, id);

	if(mysql_query(mysql, sql)){
		cout << "ERROR: " << mysql_errno(mysql) << mysql_error(mysql) << endl;
		exit(false);
	}

	DisplayInfo();
}

void Ballot::Delete(MYSQL *mysql)
{
	DisplayInfo();

	char sql[kSqlStatementLength];
	memset(sql, 0, sizeof(sql));
	sprintf(sql, "delete from ballot where id = '%s'", id);

	if(mysql_query(mysql, sql)){
		cout << "ERROR: " << mysql_errno(mysql) << mysql_error(mysql) << endl;
		exit(false);
	}
}

void Ballot::DisplayInfo()
{
	cout << "Id: " << id << "elector name: " << elector_name << "candidate name: " << candidate_name << endl;
}
