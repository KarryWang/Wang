#ifndef ELECTOR_H
#define ELECTOR_H
#include<string>
#include<mysql.h>

class Elector{
public:
	Elector(string id, string name, MYSQL *conn);
	Elector(string id, MYSQL *conn);
private:
	string id;
	string name;
};
#endif
