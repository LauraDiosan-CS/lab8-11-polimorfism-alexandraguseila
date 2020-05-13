#pragma once
#include "Resurse.h"

class ResurseFinanciare: public Resurse
{
private:
	string moneda;
public:
	ResurseFinanciare();
	ResurseFinanciare(string nume, string data, double valoare, string moneda);
	ResurseFinanciare(const ResurseFinanciare&);
	~ResurseFinanciare();
	Resurse* clone();
	string getMoneda();
	void setMoneda(string);
	bool operator==(const ResurseFinanciare&);
	ResurseFinanciare& operator=(const ResurseFinanciare&);
	string toStringDelimiter(string delim);



};
