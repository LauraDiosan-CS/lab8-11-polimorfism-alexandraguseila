#pragma once
#include "Utilizator.h"
#include <exception>
#include <string>
using namespace std;

class ValidatorUtilizator
{
protected:
	int nrErori;
	string mesaj;
public:
	ValidatorUtilizator();
	int validare(User* );
	string toString();
	~ValidatorUtilizator();
};
