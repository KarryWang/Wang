#include"candidate.h"
#include<ctime>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<mysql.h>
const int kSqlStatementLength = 1000;
extern MYSQL *conn;

Candidate::Candidate(string candidate_id, string candidate_name)
{
	id = candidate_id;
	name = candidate_name;

	char sql[kSqlStatementLength];
	char char_name[kSqlStatementLength];
	char char_id[kSqlStatementLength];
	int i = 0;
	memset(sql, 0, sizeof(sql));
	memset(char_name, 0, sizeof(char_name));
	memset(char_id, 0, sizeof(char_id));

	for(string::iterator it = name.begin(); it != name.end(); it++){
		char_name[i++] = *it;
	}
	i = 0;
	for(string::iterator it = id.begin(); it != id.end(); it++){
		char_id[i++] = *it;
	}
	sprintf(sql, "insert into candidate values('%s', '%s')", char_id, char_name);
	cout << sql << endl;

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
	cout << "sql" << sql << endl;
}
