#pragma once
#include "Resurse.h"
#include <exception>
#include <string>
using namespace std;

class ValidatorResurse
{
protected:
	int nrErori;
	string mesaj;
public:
	ValidatorResurse();
	virtual int validare(Resurse*);
	string toString();
	~ValidatorResurse();
};
