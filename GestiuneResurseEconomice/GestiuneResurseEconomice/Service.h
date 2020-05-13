#pragma once
#include "RepositoryFile.h"
#include "IRepository.h"

class Service
{
protected:
	RepoFile* resurseFin;
	RepoFile* resurseMat;
	RepoUser* users;
public:
	Service();
	Service(RepoFile&, RepoFile&, RepoUser&);

	void addResurseFinanciare(string nume, string data, double valoare, string moneda);
	void addResurseMateriale(string nume, string data, double valoare, string durata, int numar);
	void updateResurseFinanciare(string nume1, string data1, double valoare1, string moneda1, 
		string nume2, string data2, double valoare2, string moneda2);
	void updateResurseMateriale(string nume1, string data1, double valoare1, string durata1, int numar1,
		string nume2, string data2, double valoare2, string durata2, int numar2);
	void addUser(string userName, string parola);
	void updateUser(string oldUserName, string oldPassword, string newUserName, string newPassword);
	void delUser(string userName, string password, bool agree);

	vector<Resurse*> getAllResurseFin();
	vector<Resurse*> getAllResurseMat();
	vector<Resurse*> getAllResurse();
	vector<Resurse*> findByName(string name);
	vector<Resurse*> findByDate(string date);
	vector<User*> getAllUsers();

	int getSizeUsers();
	int findUser(string userName, string password);

	int login(string, string, int);
	void logout(string, string);

	~Service();


};