/*#pragma once
#include "IRepository.h"
template <class T> class RepositoryFile : public IRepository<T>
{

protected:
	const char* fileName;

public:
	RepositoryFile();
	RepositoryFile(const char*);
	virtual void saveToFile();
	virtual void loadFromFile();
	~RepositoryFile();
};


template<class T>
RepositoryFile<T>::RepositoryFile() :IRepository<T>()
{
}

template<class T>
RepositoryFile<T>::RepositoryFile(const char* name)
{
	fileName = name;
}

template<class T>
RepositoryFile<T>::~RepositoryFile()
{
}

template<class T>
void RepositoryFile<T>::saveToFile()
{
}

template<class T>
void RepositoryFile<T>::loadFromFile()
{
}*/

#pragma once
#include "Resurse.h"
#include "ValidatorResurse.h"
#include "ValidatorExceptii.h"
#include <vector>

using namespace std;

class RepoFile
{
protected:
	vector<Resurse*> elemente;
	string filename;
	ValidatorResurse* validator;
public:
	RepoFile(ValidatorResurse*);
	RepoFile(string filename, ValidatorResurse*);
	~RepoFile();
	void setFileName(string filename);

	vector<Resurse*> getAll();
	int getSize();
	Resurse* getElement(int);
	void add(Resurse*);
	void update(Resurse* vechi, Resurse* Nou);
	void del(Resurse*);
	void emptyRepo();
	virtual void loadFromFile() = 0;
	virtual void saveToFile() = 0;
};