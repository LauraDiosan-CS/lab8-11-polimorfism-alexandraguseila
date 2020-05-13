#include "ValidatorResurse.h"

ValidatorResurse::ValidatorResurse()
{
	this->nrErori = 0;
}

int ValidatorResurse::validare(Resurse* r)
{
	this->nrErori = 0;
	if (r->getNume() == "")
	{
		this->nrErori++;
		this->mesaj += "Numele trebuie sa existe!; ";
	}

	int nrCifre = 0;
	for(unsigned int i=0; i<r->getNume().size();i++)
		if (isdigit(r->getNume()[i]))
		{
			nrCifre++;
		}
	if (nrCifre == r->getNume().size())
	{
		this->nrErori++;
		this->mesaj += "Numele trebuie sa contina si litere!; ";
	}

	if (r->getData() == "")
	{
		this->nrErori++;
		this->mesaj += "Data trebuie sa existe!; ";
	}
	if (r->getData().size() != 10)
	{
		this->nrErori++;
		this->mesaj += "Data trebuie sa fie de forma DD.MM.YYYY!; ";
	}

	if (r->getValoare() < 0)
	{
		this->nrErori++;
		this->mesaj += "Valoarea trebuie sa fie pozitiva!; ";
	}
	/*if (isalpha(r->getValoare()))
	{
		this->nrErori++;
		this->mesaj += "Valoarea trebuie sa fie numar real!; ";
	}*/
	return nrErori;
}

string ValidatorResurse::toString()
{
	return this->mesaj;
}

ValidatorResurse::~ValidatorResurse()
{

}