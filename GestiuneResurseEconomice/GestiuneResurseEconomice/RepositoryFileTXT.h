/*#pragma once
#include "RepositoryFile.h"
#include <fstream>
template <class T> class RepositoryFileTXT :public RepositoryFile<T>
{
public:
	RepositoryFileTXT();
	RepositoryFileTXT(const char*);
	void loadFromFile();
	void saveToFile();
	~RepositoryFileTXT();
};

template<class T>
inline RepositoryFileTXT<T>::RepositoryFileTXT()
{
}

template<class T>
inline RepositoryFileTXT<T>::RepositoryFileTXT(const char* fName) :RepositoryFile<T>(fName)
{
}

template<class T>
inline void RepositoryFileTXT<T>::loadFromFile()
{
	string line;
	ifstream f(RepositoryFile<T>::fileName);
	while (getline(f, line)) {
		T ob(line, ' ');
		IRepository<T>::elem.push_back(ob);
	}
}

template<class T>
inline void RepositoryFileTXT<T>::saveToFile()
{
	ofstream f(RepositoryFile<T>::fileName);
	for (T crt : IRepository<T>::elem) {
		f << crt.toStringDelimiter(' ') << endl;
	}
}

template<class T>
inline RepositoryFileTXT<T>::~RepositoryFileTXT()
{
}*/

#pragma once
#include "RepositoryFile.h"

class RepoFileTXT : public RepoFile {
public:
	RepoFileTXT(ValidatorResurse*);
	RepoFileTXT(string filename, ValidatorResurse*);
	~RepoFileTXT();
	void loadFromFile();
	void saveToFile();
};