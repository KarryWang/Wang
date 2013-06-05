#include<ctime>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include"candidate.h"
#include"control.h"

const int kSqlStatementLength = 1000;
const int kCharArrayLength = 100;

//ok
Candidate::Candidate(string candidate_name, MYSQL *mysql)
{
	while(1){
		srand((unsigned)time(NULL));//make a new id for candidate
		id = rand() % MAX_CANDIDATE_ID;
		cout << id << endl;

		char sql[kSqlStatementLength];
		memset(sql, 0, sizeof(sql));
		sprintf(sql, "select * from candidate where id = '%d'", id);
		if(mysql_query(mysql, sql)){
			cout << "ERROR: " << mysql_errno(mysql) << mysql_error(mysql) << endl;
			exit(false);
		}

		MYSQL_RES *result = mysql_store_result(mysql);
		if(mysql_field_count(result) == 0)
			break;
	}
	name = candidate_name;


	char char_name[kCharArrayLength];// a temp char array to save name
	int i = 0;
	memset(char_name, 0, sizeof(char_name));
	for(string::iterator it = name.begin(); it != name.end(); it++){
		char_name[i++] = *it;
	}

	char char_id[kCharArrayLength];//a temp char array to save id
	i = 0;
	memset(char_id, 0, sizeof(char_id));
	for(string::iterator it = id.begin(); it != id.end(); it++){
		char_id[i++] = *it;
	}

	char sql[kSqlStatementLength];//a temp char array of sql statement
	memset(sql, 0, sizeof(sql));
	sprintf(sql, "insert into candidate values('%s', '%s')", char_id, char_name);
	cout << sql << endl;

	if(mysql_query(mysql, sql)){
		cout << "ERROR: " << mysql_errno(mysql) << mysql_error(mysql) << endl;
		exit(false);
	}
//	srand((unsigned)time(NULL));//make a new id for candidate
//	id = rand() % MAX_CANDIDATE_ID;
//	cout << id << endl;

//	char ch;
//	char name[SQL_LENGTH];
//	char sql[SQL_LENGTH];
//	int i = 0;
//	for(string::iterator it = name.begin(); it != name.end(); it++){
//		ch = *it;
//		sql[i++] = ch;
//	}
//	sprintf(sql, "insert into candidate values ('%s', %d)", name, id);
}

//ok
Candidate::Candidate(string candidate_id, MYSQL *mysql)
{
	id = candidate_id;

	int i = 0;
	char char_id[kCharArrayLength];
	memset(char_id, 0, sizeof(char_id));
	for(string::iterator it = id.begin(); it != id.end(); it++)
		char_id[i++] = *it;

	char sql[kSqlStatementLength];
	memset(sql, 0, sizeof(sql));
	sprintf(sql, "select * from candidate where id = '%s'", char_id);

	if(mysql_query(mysql, sql)){
		cout << "ERROR: " << mysql_errno(mysql) << mysql_error(mysql) << endl;
		exit(false);
	}
	MYSQL_RES *result;
	result = mysql_store_result(mysql);
	if(result == NULL){//
		cout << "ERROR: " << mysql_errno(mysql) << mysql_error(mysql) << endl;
		exit(false);
	}
	int field_num;
	field_num = mysql_num_fields(result);
	if(field_num == 0){
	}
	MYSQL_ROW row;
	row = mysql_fetch_row(result);
	id = row[0];
	name = row[1];
	cout << "id: " << id << "name: " << name << endl;
}

void Candidate::ModifyInfo(string candidate_name, MYSQL *mysql)
{
	DisplayInfo();
	name = candidate_name;

	char sql[kSqlStatementLength];
	memset(sql, 0, sizeof(sql));
	sprintf(sql, "update candidate set name = '%s' where id = '%s'", name, id);
	if(mysql_query(mysql, sql)){
		cout << "ERROR: " << mysql_errno(mysql) << mysql_error(mysql) << endl;
		exit(false);
	}

	DisplayInfo();
}

void Candidate::Delete(MYSQL *mysql)
{
	DisplayInfo();

	char sql[kSqlStatementLength];
	memset(sql, 0, sizeof(sql));
	sprintf(sql, "delete from candidate where id = '%s'", id);
	if(mysql_query(mysql, sql)){
		cout << "ERROR: " << mysql_errno(mysql) << mysql_error(mysql) << endl;
		exit(false);
	}
}

void Candidate::DisplayInfo()
{
	cout << "Id: " << id << " " << name << endl;
}

void Candidate::DisplayAllVotes(MYSQL *mysql)
{
	char sql[kSqlStatementLength];
	memset(sql, 0, sizeof(sql));
	sprintf(sql, "select distinct name as elector_name, sum(distinct vote.id) as vote_num from vote where candidate_name = '%s'", name);
	if(mysql_query(mysql, sql)){
		cout << "ERROR: " << mysql_errno(mysql) << mysql_error(mysql) << endl;
		exit(false);
	}
}
