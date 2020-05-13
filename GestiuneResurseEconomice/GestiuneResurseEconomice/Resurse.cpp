#include "Resurse.h"

Resurse::Resurse()
{
	nume = "";
	data = "";
	valoare = 0;
}

Resurse::Resurse(string nume, string data, double valoare)
{
	this->nume = nume;
	this->data = data;
	this->valoare = valoare;
}

Resurse::Resurse(string linie, char delim)
{
	vector<string> resurse = splitLine(linie, delim);
	this->nume = resurse[0];
	this->data = resurse[1];
	this->valoare = stod(resurse[2]);
}

Resurse::Resurse(const Resurse& r)
{
	this->nume = r.nume;
	this->data = r.data;
	this->valoare = r.valoare;
}


Resurse::~Resurse() {}

Resurse* Resurse::clone()
{
	return new Resurse(this->nume, this->data, this->valoare);
}


string Resurse::getNume()
{
	return this->nume;
}


string Resurse::getData()
{
	return this->data;
}


double Resurse::getValoare()
{
	return this->valoare;
}


void Resurse::setNume(string nume)
{
	this->nume = nume;
}


void Resurse::setData(string data)
{
	this->data = data;
}


void Resurse::setValoare(double valoare)
{
	this->valoare = valoare;
}

bool Resurse::operator==(const Resurse& r)
{
	return ((this->nume == r.nume) && (this->data == r.data) && (this->valoare == r.valoare));
}

Resurse& Resurse::operator=(const Resurse& r)
{
	this->nume = r.nume;
	this->data = r.data;
	this->valoare = r.valoare;
	return *this;
}


/*string Resurse::toString()
{
	return nume + ' ' + data + ' ' + to_string(valoare);
}*/

string Resurse::toStringDelimiter(string d)
{
	return nume + d + data + d + to_string(valoare);
}