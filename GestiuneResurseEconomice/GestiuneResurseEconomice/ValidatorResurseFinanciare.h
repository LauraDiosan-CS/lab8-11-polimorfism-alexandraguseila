#pragma once
#include "ResurseFinanciare.h"
#include "ValidatorResurse.h"

class ValidatorResurseFinanciare :public ValidatorResurse
{
public:
	ValidatorResurseFinanciare();
	int validare(Resurse*);
	~ValidatorResurseFinanciare();

};