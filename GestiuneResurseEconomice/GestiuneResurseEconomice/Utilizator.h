#pragma once
#include <string>
using namespace std;

class User
{
private:
	string userName;
	string password;
public:
	User();
	User(const User&);
	User(string, string);
	User* clone();
	string getUserName();
	string getPassword();
	void setUserName(string);
	void setPassword(string);
	bool operator==(const User& u);
	string toString();
	string toStringDelimiter(string delimiter);
	~User();
};
