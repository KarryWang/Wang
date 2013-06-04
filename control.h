#ifndef CONTROL_H
#define CONTROL_H
#include<mysql.h>
#include<cstdlib>
#include<iostream>
#include"candidate.h"

using namespace std;


class Control{
public:
	Control()
	{
		conn = mysql_init(NULL);
		if(mysql_real_connect(conn, "localhost", "root", "8023xue0526", "vote_system", 0, NULL, 0) == NULL){
			cout << "ERROR: " << mysql_errno(conn) << mysql_error(conn) << endl;
			exit(false);
		}
		cout << "JJJJ" << endl;
	}
	void input_candidate_info()
	{
		cout << "input candidate info:" << endl;
		cin >> candidate_id >> candidate_name;
	}
	void create_candidate()
	{
		input_candidate_info();
		Candidate can(candidate_id, candidate_name, conn);
	}
	void input_candidate_id()
	{
		cout << "input candidate id: " << endl;
		cin >> candidate_id;
	}
	void restore_candidate()
	{
		input_candidate_id();
		Candidate can(candidate_id, conn);
	}
	~Control()
	{
		mysql_close(conn);
	}
private:
	MYSQL *conn;
	string candidate_id;
	string candidate_name;

};
#endif
