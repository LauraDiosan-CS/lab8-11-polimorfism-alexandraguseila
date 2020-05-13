#pragma once
#include "ResurseMateriale.h"
#include "ValidatorResurse.h"

class ValidatorResurseMateriale :public ValidatorResurse
{
public:
	ValidatorResurseMateriale();
	int validare(Resurse*);
	~ValidatorResurseMateriale();
};