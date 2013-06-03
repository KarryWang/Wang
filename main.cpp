#include"candidate.h"
#include<mysql.h>

int main()
{
	MYSQL *conn;
	conn = mysql_init(NULL);
	if(mysql_real_connect(conn, "localhost", "root", "8023xue0526", "vote_system", 0, NULL, 0) == NULL){
		cout << "ERROR: " << mysql_errno(conn) << ":" << mysql_error(conn) << endl;
	}
	Candidate a("1001", "nihaoma");
	return 0;
}
