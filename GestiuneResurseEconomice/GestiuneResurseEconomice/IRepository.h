/*#pragma once
#include <vector>
#include <algorithm>
using namespace std;

template <class T> class IRepository {
protected:
	vector<T> elem;
public:
	IRepository();
	void add(T&);
	int find(T&);
	void update(T&, T&);
	int remove(T&);
	int size();
	vector<T> getAll();
};

template<class T>
inline IRepository<T>::IRepository()
{
}

template<class T>
inline void IRepository<T>::add(T& e)
{
	elem.push_back(e);
}

template<class T>
inline int IRepository<T>::find(T& e)
{
	auto it = std::find(elem.begin(), elem.end(), e);
	if (it != elem.end()) return distance(elem.begin(), it);
	return -1;
}

template<class T>
inline void IRepository<T>::update(T& vechi, T& nou)
{
	std::replace(elem.begin(), elem.end(), vechi, nou);
}

template<class T>
inline int IRepository<T>::remove(T& e)
{
	auto last = std::remove(elem.begin(), elem.end(), e);
	if (last != elem.end()) {
		elem.erase(last, elem.end());
		return 0;
	}
	return -1;
}

template<class T>
inline int IRepository<T>::size()
{
	return elem.size();
}

template<class T>
inline vector<T> IRepository<T>::getAll()
{
	return elem;
}*/

#ifndef IRepository_HEADER
#define IRepository_HEADER

#include "Utilizator.h"
#include "ValidatorUtilizator.h"
#include "ValidatorExceptii.h"
#include <vector>
#include <algorithm>
#include <fstream>

class RepoUser
{
private:
	ValidatorUtilizator* validator;
	vector<User*> users;
	string filename;
public:
	RepoUser(ValidatorUtilizator* v)
	{
		validator = v;
	};
	RepoUser(ValidatorUtilizator* v, string fileName)
	{
		validator = v;
		filename = fileName;
	};
	~RepoUser()
	{
		for (unsigned int i = 0; i < users.size(); i++)
			delete[] users[i];
	};

	int getSize()
	{
		//loadFromFile();
		return users.size();
	};

	vector<User*> getAll()
	{
		loadFromFile();
		return users;
	};

	void add(User* u)
	{
		if (validator->validare(u) == 0)
		{
			users.push_back(u);
			saveToFile();
		}
		else
			throw ValidatorExceptii(validator->toString().c_str());
	};

	void update(User* oldUser, User* newUser)
	{
		//loadFromFile();
		bool gasit = false;
		if (this->validator->validare(newUser) == 0)
		{
			for (unsigned int i = 0; i < this->users.size(); i++)
			{
				if (*(this->users[i]) == *oldUser)
				{
					gasit = true;
					delete this->users[i];
					this->users[i] = newUser->clone();
					this->saveToFile();
					return;
				}
			}
		}
		else throw ValidatorExceptii(validator->toString().c_str());
		if (gasit == false)
		{
			throw ValidatorExceptii("User inexistent!");
		}
	};

	void del(User* u)
	{
		//loadFromFile();
		bool gasit = false;
		{
			for (unsigned int i = 0; i < this->users.size(); i++)
			{
				if (**(this->users.begin() + i) == *u)
				{
					gasit = true;
					delete this->users[i];
					this->users.erase(this->users.begin() + i);
					this->saveToFile();
					return;
				}
			}
		}
		if (gasit == false)
		{
			throw ValidatorExceptii("Utilizator inexistent! ");
		}
	}

	void emptyRepo()
	{
		for (int i = 0; i < this->getSize(); i++)
		{
			delete this->users[i];
		}
		this->users.clear();
	};

	void saveToFile()
	{
		ofstream f(this->filename);
		if (f.is_open())
		{
			for (User* u : this->users)
			{
				f << u->toStringDelimiter(" ") << endl;
			}
		}
	};

	void loadFromFile()
	{
		ifstream f(this->filename);
		if (f.is_open())
		{
			this->emptyRepo();
			string linie;
			string delim = " ";
			while (getline(f, linie))
			{
				int pos = linie.find(delim);
				string username = linie.substr(0, pos);
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				string pasword = linie.substr(0, pos);
				linie = linie.erase(0, pos + 1);
				User* u = new User(username, pasword);
				try
				{
					this->add(u);
				}
				catch (ValidatorExceptii ex)
				{
					throw ex;
				}


			}
		}
	}

	int findUser(User* u)
	{
		this->loadFromFile();
		for (User* crt : users)
			if (*crt == *u)
				return 1;
		return -1;
	}
};
#endif