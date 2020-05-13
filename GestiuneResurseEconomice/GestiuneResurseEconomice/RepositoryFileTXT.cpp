#include "RepositoryFileTXT.h"
#include <fstream>
#include "ResurseFinanciare.h"
#include "ResurseMateriale.h"

RepoFileTXT::RepoFileTXT(ValidatorResurse* v) : RepoFile(v)
{
}

RepoFileTXT::RepoFileTXT(string fileName, ValidatorResurse* v) : RepoFile(fileName, v)
{
}

RepoFileTXT::~RepoFileTXT()
{
}

void RepoFileTXT::loadFromFile()
{
	ifstream f(this->filename);
	if (f.is_open())
	{
		this->emptyRepo();
		string linie;
		string delim = " ";
		while (getline(f, linie))
		{
			if (linie.substr(0, 11) == "ResurseFin:")
			{
				linie = linie.erase(0, 12);

				int pos = linie.find(delim);
				string nume = linie.substr(0, pos);
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				string data = linie.substr(0, pos);
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				double valoare = stod(linie.substr(0, pos));
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				string moneda = linie.substr(0, pos);
				linie = linie.erase(0, pos + 1);

				ResurseFinanciare* rf = new ResurseFinanciare(nume, data, valoare, moneda);
				/*if (this->validator->validare(rf) == 0)
					this->elemente.push_back(rf);
				else throw ValidatorExceptii(validator->toString().c_str());*/
				try
				{
					this->add(rf);
				}
				catch (ValidatorExceptii ex)
				{
					throw ex;
				}
			}
			else if (linie.substr(0, 11) == "ResurseMat:")
			{
				linie = linie.erase(0, 12);

				int pos = linie.find(delim);
				string nume = linie.substr(0, pos);
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				string data = linie.substr(0, pos);
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				double valoare = stod(linie.substr(0, pos));
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				string durata = linie.substr(0, pos);
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				int numar = stoi(linie.substr(0, pos));

				ResurseMateriale* rm = new ResurseMateriale(nume, data, valoare, durata, numar);
				if (this->validator->validare(rm) == 0)
					this->elemente.push_back(rm);
				else throw ValidatorExceptii(validator->toString().c_str());
				/*try
				{
					this->add(rm);
				}
				catch (ValidatorExceptii ex)
				{
					throw ex;
				}*/
				//std::cout << nume << " " << data << " " << valoare << " " << durata << " " << numar;
			}
		}
		f.close();
	}
}
void RepoFileTXT::saveToFile()
{
	ofstream f(this->filename);
	if (f.is_open())
	{
		for (Resurse* elem : this->elemente)
		{
			f << elem->toStringDelimiter(" ") << endl;
		}
	}
}
