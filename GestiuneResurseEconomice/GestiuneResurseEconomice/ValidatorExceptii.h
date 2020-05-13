#pragma once
#include <exception>
#include <string>
using namespace std;

class ValidatorExceptii : public exception {
private:
	char* mesaj;
public:
	ValidatorExceptii(const char* m) {
		mesaj = new char[strlen(m)] + 1;
		strcpy_s(mesaj, strlen(m) + 1, m);
	}

	virtual const char* what() const throw()
	{
		return mesaj;
	}
	ValidatorExceptii() 
	{ 
		if (mesaj)
			delete[] mesaj;
	}
};
