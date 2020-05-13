#include "RepositoryFileCSV.h"
#include <fstream>
#include "ResurseFinanciare.h"
#include "ResurseMateriale.h"

RepoFileCSV::RepoFileCSV(ValidatorResurse* v) : RepoFile(v)
{
}

RepoFileCSV::RepoFileCSV(string filename, ValidatorResurse* v) : RepoFile(filename, v)
{
}

RepoFileCSV::~RepoFileCSV()
{
}

void RepoFileCSV::loadFromFile()
{
	ifstream f(this->filename);
	if (f.is_open())
	{
		this->emptyRepo();
		string linie;
		string delim = ",";
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

				ResurseFinanciare* rf = new ResurseFinanciare(nume, data, valoare, moneda);
				if (this->validator->validare(rf) == 0)
					this->elemente.push_back(rf);
				else throw ValidatorExceptii(validator->toString().c_str());
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
				
			}
		}
		f.close();
	}
}

void RepoFileCSV::saveToFile()
{
	ofstream f(this->filename);
	if (f.is_open())
	{
		for (Resurse* elem : this->elemente)
		{
			f << elem->toStringDelimiter(",") << endl;
		}
	}
	f.close();
}
