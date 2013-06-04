#include<ctime>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include"candidate.h"
#include"control.h"

const int kSqlStatementLength = 1000;
const int kCharArrayLength = 100;

Candidate::Candidate(string candidate_id, string candidate_name, MYSQL *conn)
{
	id = candidate_id;
	name = candidate_name;

	char sql[kSqlStatementLength];//a temp char array of sql statement
	char char_name[kCharArrayLength];// a temp char array to save name
	char char_id[kCharArrayLength];//a temp char array to save id
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

	if(mysql_query(conn, sql)){
		cout << "ERROR: " << mysql_errno(conn) << mysql_error(conn) << endl;
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

Candidate::Candidate(string candidate_id, MYSQL *conn)
{
	id = candidate_id;

	char sql[kSqlStatementLength];
	char char_id[kCharArrayLength];
	int i = 0;
	memset(char_id, 0, sizeof(char_id));
	for(string::iterator it = id.begin(); it != id.end(); it++)
		char_id[i++] = *it;
	sprintf(sql, "select * from candidate where id = '%s'", char_id);

	MYSQL_RES *result;
	if(mysql_query(conn, sql)){
		cout << "ERROR: " << mysql_errno(conn) << mysql_error(conn) << endl;
		exit(false);
	}
	result = mysql_store_result(conn);
	if(result == NULL){//
		cout << "ERROR: " << mysql_errno(conn) << mysql_error(conn) << endl;
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
