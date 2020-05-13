#pragma once
#include "Service.h"

class UI
{
private:
	Service* service;
	User u;
	bool loggedin;

	int login();
	void logout();
	void updateUser();
	void deleteUser();
	void confidentialitate();

	void veziConturi();
	void veziResurseFinanciare();
	void veziResurseMateriale();
	void veziResurse();

	void adaugaResurseFinanciare();
	void adaugaResurseMateriale();
	void modificaResurseFinanciare();
	void modificaResurseMateriale();
	void search();
	
public:
	UI();
	UI(Service&);
	~UI();
	void showMenuLogin();
	void showSecondMenu();
	void showMenuOperare();

	

};