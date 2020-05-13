#pragma once
#include <string>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include "Util.h"

using namespace std;

class Resurse
{
protected:
	string nume;
	string data;
	double valoare;
public:
	Resurse();
	Resurse(string, string, double);
	Resurse(const Resurse&);
	Resurse(string, char);
	~Resurse();
	virtual Resurse* clone();
	string getNume();
	string getData();
	double getValoare();
	void setNume(string nume);
	void setData(string data);
	void setValoare(double valoare);
	bool operator==(const Resurse&);
	Resurse& operator=(const Resurse&);
	//string toString();
	virtual string toStringDelimiter(string);
};