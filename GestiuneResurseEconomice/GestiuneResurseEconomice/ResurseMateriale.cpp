#include "ResurseMateriale.h"

ResurseMateriale::ResurseMateriale() :Resurse()
{
	this->numar = 0;
}


ResurseMateriale::ResurseMateriale(string nume, string data, double valoare, string durata, int numar) :Resurse(nume, data, valoare)
{
	this->durata = durata;
	this->numar = numar;
}


ResurseMateriale::ResurseMateriale(const ResurseMateriale& r) :Resurse(r)
{
	this->durata = r.durata;
	this->numar = r.numar;
}


ResurseMateriale::~ResurseMateriale()
{

}

Resurse* ResurseMateriale::clone()
{
	return new ResurseMateriale(nume, data, valoare, durata, numar);
}

string ResurseMateriale::getDurata()
{
	return this->durata;
}

int ResurseMateriale::getNumar()
{
	return this->numar;
}

void ResurseMateriale::setDurata(string d)
{
	this->durata = d;
}

void ResurseMateriale::setNumar(int numar)
{
	this->numar = numar;
}

bool ResurseMateriale::operator==(const ResurseMateriale& r)
{
	return (Resurse::operator==(r) && this->durata == r.durata && this->numar == r.numar);
}

ResurseMateriale& ResurseMateriale::operator=(const ResurseMateriale& r)
{
	Resurse::operator=(r);
	this->durata = r.durata;
	this->numar = r.numar;
	return *this;
}


string ResurseMateriale::toStringDelimiter(string delim)
{
	string text = "ResurseMat:" + delim + Resurse::toStringDelimiter(delim) + delim + this->durata + delim + to_string(this->numar) + delim;
	return text;
}