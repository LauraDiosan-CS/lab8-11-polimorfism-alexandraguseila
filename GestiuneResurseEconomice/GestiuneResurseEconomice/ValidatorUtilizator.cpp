#include "ValidatorUtilizator.h"

ValidatorUtilizator::ValidatorUtilizator()
{
	nrErori = 0;
}

int ValidatorUtilizator::validare(User* u)
{
	nrErori = 0;
	if (u->getUserName() == "")
	{
		nrErori++;
		mesaj += "Username nul! ";
	}
	if (u->getPassword() == "")
	{
		nrErori++;
		mesaj += "Introduceti parola! ";
	}
	return nrErori;
}

string ValidatorUtilizator::toString()
{
	return mesaj;
}

ValidatorUtilizator::~ValidatorUtilizator()
{

}