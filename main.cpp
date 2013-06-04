#include"candidate.h"
#include"control.h"
#include<mysql.h>
#include<iostream>
#include<string>

int main()
{
	//MYSQL *conn;
	Control con;

	char a[10] = "nihao";
	string b = a;
	cout << "string:" << b;
	cout << " nakjf " << endl;
//;	con.create_candidate();
	con.restore_candidate();
	//conn = mysql_init(NULL);
//	if(mysql_real_connect(conn, "localhost", "root", "8023xue0526", "vote_system", 0, NULL, 0) == NULL){
//		cout << "ERROR: " << mysql_errno(conn) << ":" << mysql_error(conn) << endl;
//	}
	return 0;
}
