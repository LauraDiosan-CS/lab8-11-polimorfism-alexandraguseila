#include "Service.h"
#include "ResurseFinanciare.h"
#include "ResurseMateriale.h"

Service::Service()
{

}

Service::Service(RepoFile& rf, RepoFile& rm, RepoUser& u)
{
	this->resurseFin = &rf;
	this->resurseMat = &rm;
	this->users = &u;
}

void Service::addResurseFinanciare(string nume, string data, double valoare, string moneda)
{
	Resurse* r = new ResurseFinanciare(nume, data, valoare, moneda);
	try
	{
		resurseFin->add(r);
	}
	catch (ValidatorExceptii ex)
	{
		throw ex;
	}
}

void Service::addResurseMateriale(string nume, string data, double valoare, string durata, int numar)
{
	Resurse* r = new ResurseMateriale(nume, data, valoare, durata, numar);
	try
	{
		resurseMat->add(r);
	}
	catch (ValidatorExceptii ex)
	{
		throw ex;
	}
}

void Service::updateResurseFinanciare(string nume1, string data1, double valoare1, string moneda1,
	string nume2, string data2, double valoare2, string moneda2)
{
	Resurse* rVechi = new ResurseFinanciare(nume1, data1, valoare1, moneda1);
	Resurse* rNou = new ResurseFinanciare(nume2, data2, valoare2, moneda2);
	try
	{
		resurseFin->update(rVechi, rNou);
	}
	catch (ValidatorExceptii ex)
	{
		throw ex;
	}
}

void Service::updateResurseMateriale(string nume1, string data1, double valoare1, string durata1, int numar1,
	string nume2, string data2, double valoare2, string durata2, int numar2)
{
	Resurse* rVechi = new ResurseMateriale(nume1, data1, valoare1, durata1, numar1);
	Resurse* rNou = new ResurseMateriale(nume2, data2, valoare2, durata2, numar2);
	try
	{
		resurseMat->update(rVechi, rNou);
	}
	catch (ValidatorExceptii ex)
	{
		throw ex;
	}
}

vector<Resurse*> Service::getAllResurseFin()
{
	return resurseFin->getAll();
}

vector<Resurse*> Service::getAllResurseMat()
{
	return resurseMat->getAll();
}

vector<Resurse*> Service::getAllResurse()
{
	vector<Resurse*> rf = resurseFin->getAll();
	vector<Resurse*> rm = resurseMat->getAll();
	rf.insert(rf.end(), rm.begin(), rm.end());
	return rf;
}

vector<Resurse*> Service::findByName(string name)
{
	vector<Resurse*> rf = resurseFin->getAll();
	vector<Resurse*> rez;
	for (Resurse* crt : rf)
	{
		if (crt->getNume()== name)
			rez.push_back(crt);
	}

	vector<Resurse*> rm = resurseMat->getAll();
	for (Resurse* crt : rm)
	{
		if (crt->getNume() == name)
			rez.push_back(crt);
	}
	return rez;

}

vector<Resurse*> Service::findByDate(string date)
{
	vector<Resurse*> rf = resurseFin->getAll();
	vector<Resurse*> rez;
	for (Resurse* crt : rf)
	{
		if (crt->getData() == date)
			rez.push_back(crt);
	}

	vector<Resurse*> rm = resurseMat->getAll();
	for (Resurse* crt : rm)
	{
		if (crt->getData() == date)
			rez.push_back(crt);
	}
	return rez;

}


void Service::addUser(string userName, string password)
{
	User* u = new User(userName, password);
	try
	{
		users->add(u);
	}
	catch (ValidatorExceptii ex)
	{
		throw ex;
	}
}

void Service::delUser(string userName, string password, bool agree)
{
	User* u = new User(userName, password);
	if (agree == true)
	{
		try
		{
			users->del(u);
		}
		catch (ValidatorExceptii ex)
		{
			throw ex;
		}
	}

}

void Service::updateUser(string oldUserName, string oldPassword, string newUserName, string newPassword)
{
	User* u1 = new User(oldUserName, oldPassword);
	User* u2 = new User(newUserName, newPassword);
	try
	{
		users->update(u1, u2);
	}
	catch (ValidatorExceptii ex)
	{
		throw ex;
	}
}

vector<User*> Service::getAllUsers()
{
	return users->getAll();
}

int Service::getSizeUsers()
{
	return users->getSize();
}

int Service::findUser(string userName, string password)
{
	User* u = new User(userName, password);
	return users->findUser(u);
}


int Service::login(string username, string password, int opt)
{
	if (opt == 1)
	{
		if (this->findUser(username, password) == 1)
		{
			return 1;
		}
		else
		{
			{
				throw ValidatorExceptii("Utilizator inexistent!"); 
			}
		}
	}
	else
		if (opt == 2)
		{
			try
			{
				this->addUser(username, password);
				return 2;
			}
			catch (ValidatorExceptii ex)
			{
				cout << ex.what() << endl;
			}
		}


}

void Service::logout(string name, string pass)
{
	try
	{
		User* u = new User(name, pass);
		users->del(u);
	}
	catch (ValidatorExceptii ex)
	{
		throw ex;
	}
}

Service::~Service()
{

}