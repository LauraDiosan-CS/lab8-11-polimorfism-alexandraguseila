#include "ResurseFinanciare.h"

ResurseFinanciare::ResurseFinanciare() :Resurse()
{

}


ResurseFinanciare::ResurseFinanciare(string nume, string data, double valoare, string moneda) :Resurse(nume, data, valoare)
{
	this->moneda = moneda;
}


ResurseFinanciare::ResurseFinanciare(const ResurseFinanciare& r) :Resurse(r)
{
	this->moneda = r.moneda;
}


ResurseFinanciare::~ResurseFinanciare()
{

}

Resurse* ResurseFinanciare::clone()
{
	return new ResurseFinanciare(nume, data, valoare, moneda);
}

string ResurseFinanciare::getMoneda()
{
	return this->moneda;
}

void ResurseFinanciare::setMoneda(string m)
{
	this->moneda = m;
}

bool ResurseFinanciare::operator==(const ResurseFinanciare& r)
{
	return (Resurse::operator==(r) && this->moneda == r.moneda);
}

ResurseFinanciare& ResurseFinanciare::operator=(const ResurseFinanciare& r)
{
	Resurse::operator=(r);
	this->moneda = r.moneda;
	return *this;
}


string ResurseFinanciare::toStringDelimiter(string delim)
{
	return "ResurseFin:" + delim + Resurse::toStringDelimiter(delim) + delim + this->moneda + delim;
}