#include"candidate.h"
#include"control.h"
#include<mysql.h>

int main()
{
	//MYSQL *conn;
	Control con;

	cout << " nakjf " << endl;
	con.create_candidate();
	//conn = mysql_init(NULL);
//	if(mysql_real_connect(conn, "localhost", "root", "8023xue0526", "vote_system", 0, NULL, 0) == NULL){
//		cout << "ERROR: " << mysql_errno(conn) << ":" << mysql_error(conn) << endl;
//	}
	return 0;
}
