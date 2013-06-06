#ifndef ELECTOR_H
#define ELECTOR_H
#include<string>
#include<mysql.h>
#include<iostream>
#include"ballot.h"
using namespace std;

class Elector{
public:
	Elector(string elector_id, string elector_password, string elector_name, MYSQL *mysql);
	Elector(string elector_id, MYSQL *mysql);
private:
	string id;
	string password;
	string name;
};
#endif
