#include "RepositoryFile.h"
#include <algorithm>

RepoFile::RepoFile(ValidatorResurse* v)
{
	validator = v;
}

RepoFile::RepoFile(string filename, ValidatorResurse* v)
{
	this->filename = filename;
	validator = v;
}

RepoFile::~RepoFile()
{
}

void RepoFile::setFileName(string filename)
{
	this->filename = filename;
}

vector<Resurse*> RepoFile::getAll()
{
	this->loadFromFile();
	return this->elemente;
}

int RepoFile::getSize()
{
	return elemente.size();
}

Resurse* RepoFile::getElement(int poz)
{
	if (poz >= 0 && poz < this->getSize())
	{
		return this->elemente[poz]->clone();
	}
	return new Resurse();
}

void RepoFile::add(Resurse* r)
{
	int var = validator->validare(r);
	if (var == 0)
	{
		this->elemente.push_back(r->clone());
		this->saveToFile();
	}
	else
	{
		throw ValidatorExceptii(validator->toString().c_str());
	}
}

void RepoFile::update(Resurse* vechi, Resurse* nou)
{
	bool gasit = false;
	if (this->validator->validare(nou) == 0)
	{
		for (int i = 0; i < this->elemente.size(); i++)
		{
			if (*(this->getElement(i)) == *vechi)
			{
				gasit = true;
				delete this->elemente[i];
				this->elemente[i] = nou->clone();
				this->saveToFile();
				return;
			}
		}
	}
	else throw ValidatorExceptii(validator->toString().c_str());
	if(gasit == false)
		throw ValidatorExceptii("User inexistent!");
}

void RepoFile::del(Resurse* r)
{
	bool gasit = false;
	for (int i = 0; i < this->elemente.size(); i++)
	{
		// this->produse.begin() + i <=> un iterator care pointeaza spre pozitia i din vector
		if (**(this->elemente.begin() + i) == *r)
		{
			gasit = true;
			delete this->elemente[i];
			//este necesar un iterator pt. metoda erase
			this->elemente.erase(this->elemente.begin() + i);
			this->saveToFile();
			return;
		}
	}
	if (gasit == false)
	{
		throw ValidatorExceptii("Utilizator inexistent! ");
	}
}

void RepoFile::emptyRepo()
{
	for (int i = 0; i < this->getSize(); i++)
	{
		delete this->elemente[i];
	}
	this->elemente.clear();
}




