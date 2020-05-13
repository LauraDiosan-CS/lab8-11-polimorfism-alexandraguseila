#include "ValidatorResurseFinanciare.h"

ValidatorResurseFinanciare::ValidatorResurseFinanciare() :ValidatorResurse()
{

}

int ValidatorResurseFinanciare::validare(Resurse* rf)
{
	ResurseFinanciare* r = (ResurseFinanciare*)rf;
	//this->nrErori = ValidatorResurse::validare(r);
	ValidatorResurse::validare(r);
	for(int i=0; i<r->getMoneda().size(); i++)
		if (isdigit(r->getMoneda()[i]))
		{
			this->nrErori++;
			this->mesaj += "Moneda trebuie sa fie scrisa cu litere!; ";
			break;
		}
	return nrErori;
}

ValidatorResurseFinanciare::~ValidatorResurseFinanciare()
{

}


