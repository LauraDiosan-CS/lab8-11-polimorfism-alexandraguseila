#pragma once
#include "Resurse.h"

class ResurseMateriale : public Resurse
{
private:
	string durata;
	int numar;
public:
	ResurseMateriale();
	ResurseMateriale(string nume, string data, double valoare, string durata, int numar);
	ResurseMateriale(const ResurseMateriale&);
	~ResurseMateriale();
	Resurse* clone();
	string getDurata();
	int getNumar();
	void setDurata(string);
	void setNumar(int nr);
	bool operator==(const ResurseMateriale&);
	ResurseMateriale& operator=(const ResurseMateriale&);
	string toStringDelimiter(string delim);



};
