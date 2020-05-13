#include "ValidatorResurseMateriale.h"

ValidatorResurseMateriale::ValidatorResurseMateriale() :ValidatorResurse()
{

}

int ValidatorResurseMateriale::validare(Resurse* rm)
{
	ResurseMateriale* r = (ResurseMateriale*)rm;
	//nrErori = ValidatorResurse::validare(r);
	ValidatorResurse::validare(r);
	if (r->getDurata() == "")
	{
		nrErori++;
		mesaj += "Durata trebuie sa existe!; ";
	}
	if (r->getNumar() < 0)
	{
		nrErori++;
		mesaj += "Numarul de exemplare trebuie sa fie pozitiv!; ";
	}
	return nrErori;
}

ValidatorResurseMateriale::~ValidatorResurseMateriale()
{

}