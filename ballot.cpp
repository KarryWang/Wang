#include"ballot.h"

Ballot::Ballot(string temp_elector_name, string temp_candidate_name, MYSQL *mysql)
{
	int num;
	while(1){
		srand((unsigned)time(NULL));//make a new id for candidate
		num = rand() % kMaxCandidateId;
		cout << num << endl;

		char sql[kSqlStatementLength];
		memset(sql, 0, sizeof(sql));
		sprintf(sql, "select * from ballot where id = '%d'", num);
		if(mysql_query(mysql, sql)){
			cout << "ERROR: " << mysql_errno(mysql) << mysql_error(mysql) << endl;
			exit(false);
		}

		MYSQL_RES *result = mysql_store_result(mysql);
		if(mysql_field_count(mysql) == 0)
			break;
	}

	char temp[kCharArrayLength];
	memset(temp, 0, sizeof(temp));
	sprintf(temp, "%d", num);
	id = temp;
	elector_name = temp_elector_name;
	candidate_name = temp_candidate_name;

	char char_id[kCharArrayLength];
	int i = 0;
	memset(char_id, 0, sizeof(char_id));
	for(string::iterator it = id.begin(); it != id.end(); it++)
		char_id[i++] = *it;
	
	char char_elector_name[kCharArrayLength];
	memset(char_elector_name, 0, sizeof(char_elector_name));
	i = 0;
	for(string::iterator it = elector_name.begin(); it != elector_name.end(); it++)
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
	char char_id[kCharArrayLength];
	memset(char_id, 0, sizeof(char_id));
	int i = 0;
	for(string::iterator it = ballot_id.begin(); it != ballot_id.end(); it++)
		char_id[i++] = *it;
	char sql[kSqlStatementLength];
	memset(sql, 0, sizeof(sql));
	sprintf(sql, "select * from ballot where id = '%s'", char_id);

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
		cout << "There is no this ballot!" << endl;
		exit(false);
	}

	MYSQL_ROW row = mysql_fetch_row(result);
	id = row[0];
	elector_name = row[1];
	candidate_name = row[2];
	cout << "ballot_id: " << id << " " << elector_name << " " << candidate_name << endl;
}

void Ballot::ModifyInfo(string new_candidate_name, MYSQL *mysql)
{
	DisplayInfo();
	candidate_name = new_candidate_name;

	char char_name[kCharArrayLength];
	memset(char_name, 0, sizeof(char_name));
	int i = 0;
	for(string::iterator it = new_candidate_name.begin(); it != new_candidate_name.end(); it++)
		char_name[i++] = *it;
	char char_id[kCharArrayLength];
	memset(char_id, 0, sizeof(char_id));
	i = 0;
	for(string::iterator it = id.begin(); it != id.end(); it++)
		char_id[i++] = *it;

	char sql[kSqlStatementLength];
	memset(sql, 0, sizeof(sql));
	sprintf(sql, "update ballot set candidate_name = '%s' where id = '%s'", char_name, char_id);

	if(mysql_query(mysql, sql)){
		cout << "ERROR: " << mysql_errno(mysql) << mysql_error(mysql) << endl;
		exit(false);
	}

	DisplayInfo();
}

void Ballot::Delete(MYSQL *mysql)
{
	DisplayInfo();

	char char_id[kCharArrayLength];
	memset(char_id, 0, sizeof(char_id));
	int i = 0;
	for(string::iterator it = id.begin(); it != id.end(); it++)
		char_id[i++] = *it;

	char sql[kSqlStatementLength];
	memset(sql, 0, sizeof(sql));
	sprintf(sql, "delete from ballot where id = '%s'", char_id);

	if(mysql_query(mysql, sql)){
		cout << "ERROR: " << mysql_errno(mysql) << mysql_error(mysql) << endl;
		exit(false);
	}
}

void Ballot::DisplayInfo()
{
	cout << "Id: " << id << "elector name: " << elector_name << "candidate name: " << candidate_name << endl;
}
