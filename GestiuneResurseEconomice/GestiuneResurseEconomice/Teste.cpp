#include "Teste.h"
#include <string>
#include <cassert>

void Test::runTests()
{
	testResurse();
	testResurseFinanciare();
	testResurseMateriale();
	testUtilizator();
	testRepository();
	testService();
	testRepoUser();
	testExceptii();
}

void Test::testResurse()
{
	testResurseGetter();
	testResurseSetter();
}

void Test::testResurseGetter()
{
	Resurse r("gaz", "01.10.2019", 100.0);
	assert(r.getNume() == "gaz");
	assert(r.getData() == "01.10.2019");
	assert(r.getValoare() == 100.0);
}

void Test::testResurseSetter()
{
	Resurse r("gaz", "01.10.2019", 100.0);
	Resurse r2;
	assert(r2.getNume() == "");
	assert(r2.getValoare() == 0);
	r2.setNume("gaz");
	r2.setData("01.10.2019");
	r2.setValoare(100.0);
	assert(r == r2);
}

void Test::testResurseFinanciare()
{
	testResurseFinanciareGetter();
	testResurseFinanciareSetter();
}

void Test::testResurseFinanciareGetter()
{
	ResurseFinanciare r;
	ResurseFinanciare r2("gaz", "01.05.2018", 1500.0, "euro");
	ResurseFinanciare r3(r2);
	assert(r.getData() == "");
	assert(r.getMoneda() == "");
	assert(r2.getNume() == "gaz");
	assert(r2.getData() == "01.05.2018");
	assert(r2.getValoare() == 1500.0);
	assert(r2.getMoneda() == "euro");
	assert(r3 == r2);

}

void Test::testResurseFinanciareSetter()
{
	ResurseFinanciare r;
	r.setNume("gaz");
	r.setData("01.05.2018");
	r.setValoare(1500.0);
	r.setMoneda("euro");
	assert(r.getNume() == "gaz");
	assert(r.getData() == "01.05.2018");
	assert(r.getValoare() == 1500.0);
	assert(r.getMoneda() == "euro");
	assert(r == ResurseFinanciare("gaz", "01.05.2018", 1500.0, "euro"));

}

void Test::testResurseMateriale()
{
	testResurseMaterialeGetter();
	testResurseMaterialeSetter();
}

void Test::testResurseMaterialeGetter()
{
	ResurseMateriale r;
	ResurseMateriale r2("lapte", "01.05.2018", 1500.0, "1saptamana", 25);
	ResurseMateriale r3(r2);
	assert(r.getData() == "");
	assert(r.getDurata() == "");
	assert(r.getNumar() == 0);
	assert(r2.getNume() == "lapte");
	assert(r2.getData() == "01.05.2018");
	assert(r2.getValoare() == 1500.0);
	assert(r2.getDurata() == "1saptamana");
	assert(r2.getNumar() == 25);
	assert(r3 == r2);
}

void Test::testResurseMaterialeSetter()
{
	ResurseMateriale r;
	r.setNume("portocale");
	r.setData("01.05.2018");
	r.setValoare(1500.0);
	r.setDurata("2saptamani");
	r.setNumar(1500);
	assert(r.getNume() == "portocale");
	assert(r.getData() == "01.05.2018");
	assert(r.getDurata() == "2saptamani");
	assert(r.getNumar() == 1500);
	assert(r == ResurseMateriale("portocale", "01.05.2018", 1500.0, "2saptamani", 1500));

}

void Test::testUtilizator()
{
	User u1, u4;
	User u2("player1", "parola0");
	User u3(u2);
	u4.setUserName("player2");
	u4.setPassword("parola0");
	assert(u1.getUserName() == "");
	assert(u1.getPassword() == "");
	assert(u2 == u3);
	assert(u4 == User("player2", "parola0"));
}

void Test::testRepository()
{
	testRepoFileTXTAdd();
	testRepoFileTXTGetAll();
	testRepoFileTXTGetElement();
	testRepoFileTXTDel();
	testRepoFileTXTUpdate();
	testRepoFileTXTSaveToFile();
	testRepoFileTXTLoadFromFile();
	testRepoFileCSV();
	
}

void Test::testRepoFileTXTAdd()
{
	ValidatorResurse* v = new ValidatorResurseFinanciare();
	RepoFile* repo = new RepoFileTXT(v);
	try 
	{
		Resurse* rf = new ResurseFinanciare("gaz", "10.02.2012", 4, "euro");
		repo->add(rf);
		assert(repo->getSize() == 1);
	}
	catch (ValidatorExceptii ex)
	{
		cout << ex.what() << endl;
		//throw ex;
	}
}

void Test::testRepoFileTXTGetAll()
{
	ValidatorResurse* v = new ValidatorResurse();
	RepoFile* repo = new RepoFileTXT(v);
	try
	{
		ResurseFinanciare* rf = new ResurseFinanciare("cont", "01.01.2020", 500, "euro");
		ResurseMateriale* rm = new ResurseMateriale("ciment", "05.05.2014", 200, "5ani", 500);
		repo->add(rf);
		repo->add(rm);
		vector<Resurse*> elem = repo->getAll();
		assert(elem.size() == 2);
		assert(*elem[0] == *rf);
		assert(*elem[1] == *rm);
	}
	catch (ValidatorExceptii ex)
	{
		cout << ex.what() << endl;
		//throw ex;
	}

}

void Test::testRepoFileTXTGetElement()
{
	ValidatorResurse* v = new ValidatorResurse();
	RepoFile* repoFile = new RepoFileTXT(v);
	try
	{
		ResurseMateriale* rm = new ResurseMateriale("ciment", "05.05.2014", 200.0, "5ani", 500);
		repoFile->add(rm);
		assert(*repoFile->getElement(0) == *rm->clone());
		assert(*repoFile->getElement(-1) == *(new Resurse()));
		assert(*repoFile->getElement(1) == *(new Resurse()));
	}
	catch (ValidatorExceptii ex)
	{
		cout << ex.what() << endl;
		//throw ex;
	}
}

void Test::testRepoFileTXTDel()
{
	ValidatorResurse* v = new ValidatorResurse();
	RepoFile* repoFile = new RepoFileTXT(v);
	try
	{
		ResurseFinanciare* rf = new ResurseFinanciare("cont", "01.01.2020", 500.0, "euro");
		ResurseFinanciare* rf2 = new ResurseFinanciare("aur", "01.01.2020", 5000.0, "euro");
		repoFile->add(rf);
		repoFile->add(rf2);
		repoFile->del(rf2);
		assert(repoFile->getSize() == 1);
		assert(*repoFile->getElement(0) == *rf);
		repoFile->del(rf);
		assert(repoFile->getSize() == 0);
	}
	catch (ValidatorExceptii ex)
	{
		cout << ex.what() << endl;
		//throw ex;
	}
}

void Test::testRepoFileTXTUpdate()
{
	ValidatorResurse* v = new ValidatorResurseFinanciare();
	RepoFile* repoFile = new RepoFileTXT(v);
	try
	{
		ResurseFinanciare* rf =  new ResurseFinanciare("cont", "01.01.2020", 500.0, "euro");
		ResurseFinanciare* rf2 = new ResurseFinanciare("aur", "01.01.2020", 5000.0, "euro");
		ResurseFinanciare* rf3 = new ResurseFinanciare("argint", "01.04.2020", 2000.0, "euro");
		repoFile->add(rf);
		repoFile->add(rf3);
		repoFile->update(rf, rf2);
		repoFile->update(rf3, rf2);
		assert(*repoFile->getElement(0) == *rf2);
		assert(*repoFile->getElement(1) == *rf2);
	}
	catch (ValidatorExceptii ex)
	{
		cout << ex.what() << endl;
		//throw ex;
	}
}

void Test::testRepoFileTXTSaveToFile()
{
	ValidatorResurse* v = new ValidatorResurse();
	RepoFile* repoFile = new RepoFileTXT("TestResurse.txt", v);
	repoFile->emptyRepo();
	repoFile->saveToFile();
	try
	{
		ResurseFinanciare* rf = new ResurseFinanciare("cont", "02.04.2020", 500, "euro");
		ResurseFinanciare* rf2 = new ResurseFinanciare("aur", "01.01.2020", 5000, "lei");
		ResurseMateriale* rm = new ResurseMateriale("lemn", "08.10.2019", 400, "10ani", 4);
		ResurseMateriale* rm2 = new ResurseMateriale("petrol", "09.11.2014", 900, "100ani", 5000);
		repoFile->add(rf);
		repoFile->add(rf2);
		repoFile->add(rm);
		repoFile->add(rm2);
		repoFile->saveToFile();
	}
	catch (ValidatorExceptii ex)
	{
		cout << ex.what() << endl;
		//throw ex;
	}
}


void Test::testRepoFileTXTLoadFromFile()
{
	ValidatorResurse* v = new ValidatorResurse();
	ResurseFinanciare* rf = new ResurseFinanciare("cont", "02.04.2020", 500, "euro");
	RepoFile* repoFile = new RepoFileTXT("TestResurse.txt", v);
	try
	{
		repoFile->loadFromFile();
		assert(repoFile->getSize() == 4);
		assert(*repoFile->getElement(0) == *rf);
	}
	catch (ValidatorExceptii ex)
	{
		cout << ex.what() << endl;
		//throw ex;
	}

}



void Test::testRepoFileCSV()
{
	testRepoFileCSVSaveToFile();
	testRepoFileCSVLoadFromFile();
}


void Test::testRepoFileCSVSaveToFile()
{
	ValidatorResurse* v = new ValidatorResurse();
	RepoFile* repoFile = new RepoFileCSV("TestResurse.csv", v);
	repoFile->emptyRepo();
	repoFile->saveToFile();
	try
	{
		ResurseFinanciare* rf = new ResurseFinanciare("cont", "02.04.2020", 500, "euro");
		ResurseFinanciare* rf2 = new ResurseFinanciare("aur", "01.01.2020", 5000, "lei");
		ResurseMateriale* rm = new ResurseMateriale("lemn", "08.10.2019", 400, "10ani", 4);
		ResurseMateriale* rm2 = new ResurseMateriale("petrol", "09.11.2014", 900, "100ani", 5000);
		repoFile->add(rf);
		repoFile->add(rf2);
		repoFile->add(rm);
		repoFile->add(rm2);
		repoFile->saveToFile();
	}
	catch (ValidatorExceptii ex)
	{
		cout << ex.what() << endl;
		//throw ex;
	}
}

void Test::testRepoFileCSVLoadFromFile()
{
	ValidatorResurse* v = new ValidatorResurse();
	ResurseFinanciare* rf = new ResurseFinanciare("cont", "02.04.2020", 500, "euro");
	RepoFile* repoFile = new RepoFileCSV("TestResurse.csv", v);
	try
	{
		repoFile->loadFromFile();
		assert(repoFile->getSize() == 4);
		assert(*repoFile->getElement(0) == *rf);
	}
	catch (ValidatorExceptii ex)
	{
		cout << ex.what() << endl;
		//throw ex;
	}
}

void Test::testService()
{
	testServiceAdd();
	testServiceUpdate();
	testServiceLogin();
	testServiceFind();
}

void Test::testServiceAdd()
{
	ValidatorResurse* validator = new ValidatorResurse();
	ValidatorUtilizator* v = new ValidatorUtilizator();
	RepoFile* resurseFin = new RepoFileCSV("TestResurseFinanciare.csv", validator);
	RepoFile* resurseMat = new RepoFileCSV("TestResurseMateriale.csv", validator);
	RepoUser* repoUsers = new RepoUser(v, "TestUser.txt");
	Service* service = new Service(*resurseFin, *resurseMat, *repoUsers);
	User* u = new User("ServiceUser", "test");

	try
	{
		service->addResurseFinanciare("bronz", "10.02.2000", 50.000, "dolari");
		service->addResurseMateriale("oja", "19.04.2020", 5, "3luni", 2);
		service->addUser("ServiceUser", "test");

		assert(service->getSizeUsers() == 1);
		assert(*service->getAllUsers()[0] == *u);
		assert(service->getAllResurseFin().size() == 1);
		assert(service->getAllResurseMat().size() == 1);
		assert(service->getAllResurse().size() == 2);
	}
	catch (ValidatorExceptii ex)
	{
		cout << ex.what() << endl;
		//throw ex;
	}
}

void Test::testServiceUpdate()
{
	ValidatorResurse* validator = new ValidatorResurse();
	ValidatorUtilizator* v = new ValidatorUtilizator();
	RepoFile* resurseFin = new RepoFileCSV("TestResurseFinanciare.csv", validator);
	RepoFile* resurseMat = new RepoFileCSV("TestResurseMateriale.csv", validator);
	RepoUser* repoUsers = new RepoUser(v, "TestUser.txt");
	Service* service = new Service(*resurseFin, *resurseMat, *repoUsers);
	User* u2 = new User("newName", "parola");
	try
	
	{
		resurseFin->loadFromFile();
		resurseMat->loadFromFile();
		repoUsers->loadFromFile();
		service->updateResurseFinanciare("bronz", "10.02.2000", 50.000, "dolari",
			"bronz", "10.02.2000", 100.000, "dolari");
		service->updateResurseMateriale("oja", "19.04.2020", 5, "3luni", 2,
			"lacpentruunhii", "20.04.2020", 5, "3luni", 1);
		service->updateUser("ServiceUser", "test", "newName", "parola");
		User* u = service->getAllUsers()[0];

		assert(*u == *u2);
		assert(service->getAllResurseFin().size() == 1);
		assert(service->getAllResurseMat().size() == 1);
		assert(service->getAllResurse().size() == 2);
	}
	catch (ValidatorExceptii ex)
	{
		cout << ex.what() << endl;
		//throw ex;
	}
}

void Test::testServiceLogin()
{
	ValidatorResurse* validator = new ValidatorResurse();
	ValidatorUtilizator* v = new ValidatorUtilizator();
	RepoFile* resurseFin = new RepoFileCSV("TestResurseFinanciare.csv", validator);
	RepoFile* resurseMat = new RepoFileCSV("TestResurseMateriale.csv", validator);
	RepoUser* repoUsers = new RepoUser(v, "TestUser.txt");
	Service* service = new Service(*resurseFin, *resurseMat, *repoUsers);
	try
	{
		assert(service->login("newName", "parola", 1) == 1);
		assert(service->login("cont", "parolasecreta", 2) == 2);
	}
	catch (ValidatorExceptii ex)
	{
		cout << ex.what() << endl;
		//throw ex;
	}
}

void Test::testServiceFind()
{
	ValidatorResurse* validator = new ValidatorResurse();
	ValidatorUtilizator* v = new ValidatorUtilizator();
	RepoFile* resurseFin = new RepoFileCSV("TestResurseFinanciare.csv", validator);
	RepoFile* resurseMat = new RepoFileCSV("TestResurseMateriale.csv", validator);
	RepoUser* repoUsers = new RepoUser(v, "TestUser.txt");
	Service* service = new Service(*resurseFin, *resurseMat, *repoUsers);
	//resurseFin->loadFromFile();
	//resurseMat->loadFromFile();
	Resurse* rf = new ResurseFinanciare("bronz", "10.02.2000", 100.000, "dolari");
	assert(*service->findByDate("10.02.2000")[0] == *rf);
}

void Test::testRepoUser()
{
	testRepoUserAdd();
	testRepoUserUpdate();
	testRepoUserDelete();
	testRepoUserFind();
}

void Test::testRepoUserAdd()
{
	ValidatorUtilizator* v = new ValidatorUtilizator();
	RepoUser* repo = new RepoUser(v, "TestUser.txt");
	User* u = new User("user", "parolameasecreta");
	try
	{
		repo->add(u);
		assert(repo->getSize() == 1);
	}
	catch (ValidatorExceptii ex)
	{
		cout << ex.what() << endl;
		//throe ex;
	}
}

void Test::testRepoUserUpdate()
{
	ValidatorUtilizator* v = new ValidatorUtilizator();
	RepoUser* repo = new RepoUser(v, "TestUser.txt");
	repo->loadFromFile();
	assert(repo->getSize() == 1);
	User* uVechi = new User("user", "parolameasecreta");
	User* uNou = new User("florinaa", "parolameasecreta");
	try
	{
		repo->update(uVechi, uNou);
		assert(*repo->getAll()[0] == *uNou);
		//cout << repo->getAll()[0]->getUserName();
	
	}
	catch (ValidatorExceptii ex)
	{
		cout << ex.what() << endl;
	}
}

void Test::testRepoUserDelete()
{
	ValidatorUtilizator* v = new ValidatorUtilizator();
	RepoUser* repo = new RepoUser(v, "TestUser.txt");
	User* u = new User("florinaa", "parolameasecreta");
	repo->loadFromFile();
	repo->del(u);
	assert(repo->getSize() == 0);
}

void Test::testRepoUserFind()
{
	ValidatorUtilizator* v = new ValidatorUtilizator();
	RepoUser* repo = new RepoUser(v);
	User* u = new User("florinaa", "parolameasecreta");
	repo->add(u);
	assert(repo->findUser(u) == 1);

}

void Test::testExceptii()
{
	ValidatorResurse* validator = new ValidatorResurse();
	ValidatorUtilizator* v = new ValidatorUtilizator();
	RepoFile* resurseFin = new RepoFileCSV("TestResurseFinanciare.csv", validator);
	RepoFile* resurseMat = new RepoFileCSV("TestResurseMateriale.csv", validator);
	RepoUser* repoUsers = new RepoUser(v, "TestUser.txt");
	Service* service = new Service(*resurseFin, *resurseMat, *repoUsers);
	string mesaj;
	int ok=0;
	try
	{
		int rez = service->login("inexistentuser", "parola", 1);
	}
	catch (ValidatorExceptii ex)
	{
		
		mesaj =  ex.what();
		ok = 1;
	}
	assert(ok == 1);
	assert(mesaj == "Utilizator inexistent!");
}

