#include "UI.h"
#include "ValidatorExceptii.h"
#include "Utilizator.h"
#include <Windows.h>
#include "ResurseMateriale.h"
using namespace std;

HANDLE hCon;

enum Color {
	DARKBLUE = 1, DARKGREEN, DARKTEAL, DARKRED, DARKPINK, DARKYELLOW,
	GRAY, DARKGRAY, BLUE, GREEN, TEAL, RED, PINK, YELLOW, WHITE
};

void SetColor(Color c)
{
	if (hCon == NULL)
		hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon, c);
}


UI::UI()
{

}

UI::UI(Service& r)
{
	this->service = &r;
}

UI::~UI(){}

void UI::showMenuLogin()
{
	bool gata = false;
	while (!gata) 
	{
		cout << endl << "----------->  MENIU PRINICPAL <-----------------" << endl;
		cout << "1. Login " << endl;
		cout << "0.Exit" << endl;
		int opt;
		cout << "Optiunea dvs este:";
		cin >> opt;
		switch (opt)
		{
			case 1:
			{
				if (this->login() == 1)
					this->showSecondMenu();

				break; 
			}
			case 0: {gata = true; }
		}
			
	}
}


void UI::showSecondMenu()
{
	bool gata = false;
	while (!gata && loggedin == true)
	{
		cout << "1.Confidetialitate" << endl;
		cout << "2.Operare"<<endl;
		cout << "0.Logout" << endl;

		int opt;
		cout << "Optiunea dvs este:";
		cin >> opt;
		switch (opt)
		{
			case 1: {confidentialitate(); break; }
			case 2: {showMenuOperare(); break; }
			case 0: {logout(); gata = true; break; }
		}
	}
}

void UI::showMenuOperare()
{
	bool gata = false;
	while (!gata) 
	{
		cout << endl << "----------->  MENIU OPERARE <-----------------" << endl;
		cout << "1. Adauga resurse materiale" << endl;
		cout << "2. Adauga resurse financiare" << endl;
		cout << "3. Cauta resurse" << endl;
		cout << "4. Afiseaza toate resursele" << endl;
		cout << "5. Afiseaza toate resursele materiale" << endl;
		cout << "6. Afiseaza toate resursele financiare" << endl;
		cout << "7. Modifica resurse materiale" << endl;
		cout << "8. Modifica resurse fianciare" << endl;
		cout << "0. Inapoi" << endl;


		int opt;
		cout << "Dati optiunea:";
		cin >> opt;
		switch (opt) 
		{
			case 1: {adaugaResurseMateriale(); break; }
			case 2: {adaugaResurseFinanciare(); break; }
			case 3: {search(); break; }
			case 4: {veziResurse(); break; }
			case 5: {veziResurseMateriale(); break; }
			case 6: {veziResurseFinanciare(); break; }
			case 7: {modificaResurseMateriale(); break; }
			case 8: {modificaResurseFinanciare(); break; }
			case 0: {gata = true; }
		}
	}
}


int UI::login()
{
	cout << "1.Autentificare" << endl;
	cout << "2.Inregistrare" << endl;
	int opt;
	string username, password;
	cout << "Optiunea dvs este: ";
	cin >> opt;
	cout << "Introduceti numele de utilizator:"<<endl;
	cin >> username;
	cout << "Introduceti parola:" << endl;
	cin >> password;
	try
	{
		int rez = service->login(username, password, opt);
		if (rez == 2)
			cout << "Utilizator adaugat! " << endl;
		u.setUserName(username);
		u.setPassword(password);
		loggedin = true;
		return 1;
	}
	catch (ValidatorExceptii ex)
	{
		cout << ex.what() << endl;
	}
}

void UI::logout()
{
	try
	{
		service->logout(u.getUserName(), u.getPassword());
		loggedin = false;
	}
	catch (ValidatorExceptii ex)
	{
		cout << ex.what() << endl;
	}
}

void UI::confidentialitate()
{
	cout << "1.Schimba detaliile contului" << endl;
	cout << "2.Sterge contul" << endl;
	cout << "3.Vezi toate conturile" << endl;
	cout << "Optiunea dvs este: ";
	int opt;
	cin >> opt;
	if (opt == 1)
	{
		updateUser();
	}
	else
		if (opt == 2)
		{
			deleteUser();
		}
		else
			if (opt == 3)
			{
				veziConturi();
			}
}

void UI::updateUser()
{
	string oldUsername, oldPassword, newUserName, newPassword;
	oldUsername = u.getUserName();
	oldPassword = u.getPassword();
	cout << "Introduceti noile date" << endl;
	/*cout << "Numele de utilizator: " ;
	cin >> oldUsername;
	cout << "Parola: ";
	cin >> oldPassword;*/
	cout << "Dati noul nume: ";
	cin >> newUserName;
	cout << "Dati noua parola: ";
	cin >> newPassword;
	try
	{
		service->updateUser(oldUsername, oldPassword, newUserName, newPassword);
		cout << "Modificari relizate cu succes!" << endl;
	}
	catch (ValidatorExceptii ex)
	{
		cout << ex.what() << endl;
	}
}

void UI::deleteUser()
{
	string username, password, agreee, password0;
	username = u.getUserName();
	password = u.getPassword();
	bool agree = false;
	cout << "Sigur doriti sa stergeti acest cont? (da/nu): ";
	cin >> agreee;
	if (agreee == "da")
	{
		agree = true;
	}
	else
	{
		agree = false;
	}
	try
	{
		service->delUser(username, password, agree);
		if (agree == true)
		{
			cout << "Contul a fost sters!" << endl;
			loggedin = false;
		}
		else
			cout << "Contul nu a fost sters!" << endl;
	}
	catch (ValidatorExceptii exc)
	{
		cout << exc.what() << endl;
	}

}

void UI::veziConturi()
{
	vector<User*> u = service->getAllUsers();
	for (User* crt : u)
	{
		cout << crt->toStringDelimiter(" ");
		cout << endl;
	}
}

void UI::veziResurse()
{
	vector<Resurse*> r = service->getAllResurse();
	for (Resurse* crt : r)
	{
		if (crt->getValoare() == 0)
		{
			SetColor(YELLOW);
			cout << crt->toStringDelimiter(" ")<<endl;
			SetColor(GRAY);
		}
		cout << crt->toStringDelimiter(" ");
		cout << endl;
	}
}

void UI::veziResurseMateriale()
{
	vector<Resurse*> r = service->getAllResurseMat();
	for (Resurse* crt : r)
	{
		if (crt->getValoare() == 0)
		{
			SetColor(PINK);
			cout << crt->toStringDelimiter(" ") << endl;
			SetColor(GRAY);
		}
		cout << crt->toStringDelimiter(" ");
		cout << endl;
	}
}

void UI::veziResurseFinanciare()
{
	vector<Resurse*> r = service->getAllResurseFin();
	for (Resurse* crt : r)
	{
		if (crt->getValoare() == 0)
		{
			SetColor(PINK);
			cout << crt->toStringDelimiter(" ") << endl;
			SetColor(WHITE);
		}
		cout << crt->toStringDelimiter(" ");
		cout << endl;
	}
}

void UI::adaugaResurseFinanciare()
{
	string nume, data, moneda;
	double val;
	cout << "Introduceti datele resursei de adaugat: " << endl;
	cout << "Nume: " ;
	cin >>nume;
	cout << "Data: " ;
	cin >>data ;
	cout << "Valoarea: " ;
	cin >> val;
	cout << "Moneda" ;
	cin >> moneda;
	try
	{
		service->addResurseFinanciare(nume, data, val, moneda);
		cout << "Resursa adaugata!" << endl;
	}
	catch (ValidatorExceptii ex)
	{
		cout << ex.what() << endl;
		cout << "Incearca din nou!" << endl;
	}
}

void UI::adaugaResurseMateriale()
{
	string nume, data, durata;
	double val;
	int numar;
	cout << "Introduceti datele resursei de adaugat: " << endl;
	cout << "Nume: ";
	cin >> nume;
	cout << "Data: ";
	cin >> data;
	cout << "Valoarea: ";
	cin >> val;
	cout << "Durata: ";
	cin >> durata;
	cout << "Numar exemplare :";
	cin >> numar;
	try
	{
		service->addResurseMateriale(nume, data, val, durata, numar);
		cout << "Resursa adaugata!" << endl;
	}
	catch (ValidatorExceptii ex)
	{
		cout << ex.what() << endl;
		cout << "Incearca din nou!" << endl;
	}
}

void UI::modificaResurseFinanciare()
{
	string nume, nume2, data, data2,  moneda, moneda2;
	double val, val2;
	cout << "Introduceti datele resursei de modificat: " << endl;
	cout << "Nume: ";
	cin >> nume;
	cout << "Data: ";
	cin >> data;
	cout << "Valoarea: ";
	cin >> val;
	cout << "Moneda";
	cin >> moneda;
	cout << "Introduceti datele resursei noi: " << endl;
	cout << "Nume: ";
	cin >> nume2;
	cout << "Data: ";
	cin >> data2;
	cout << "Valoarea: ";
	cin >> val2;
	cout << "Moneda";
	cin >> moneda2;
	try
	{
		service->updateResurseFinanciare(nume, data, val, moneda, nume2, data2, val2, moneda2);
		cout << "Resursa modificata!" << endl;
	}
	catch (ValidatorExceptii ex)
	{
		cout << ex.what() << endl;
		cout << "Incearca din nou!" << endl;
	}
	
}

void UI::modificaResurseMateriale()
{
	string nume, nume2, data, data2, durata, durata2;
	double val, val2;
	int nr, nr2;
	cout << "Introduceti datele resursei de modificat: " << endl;
	cout << "Nume: ";
	cin >> nume;
	cout << "Data: ";
	cin >> data;
	cout << "Valoarea: ";
	cin >> val;
	cout << "Durata";
	cin >> durata;
	cout << "Nr exemplare: ";
	cin >> nr;
	cout << "Introduceti datele resursei noi: " << endl;
	cout << "Nume: ";
	cin >> nume2;
	cout << "Data: ";
	cin >> data2;
	cout << "Valoarea: ";
	cin >> val2;
	cout << "Durata";
	cin >> durata2;
	cout << "Nr exemplare: ";
	cin >> nr2;
	try
	{
		service->updateResurseMateriale(nume, data, val, durata, nr, nume2, data2, val2, durata2, nr2);
		cout << "Resursa modificata!" << endl;
	}
	catch (ValidatorExceptii ex)
	{
		cout << ex.what() << endl;
		cout << "Incearca din nou!" << endl;
	}

}

void UI::search()
{
	cout << "1.Cauta dupa nume" << endl;
	cout << "2.Cauta dupa data" << endl;
	int opt;
	cout << "Optiunea dvs este:";
	cin >> opt;
	if (opt == 1)
	{
		string name;
		cout << "Dati numele: ";
		cin >> name;
		vector<Resurse*> r = service->findByName(name);
		for (Resurse* crt : r)
		{
			cout << crt->toStringDelimiter(" ") << endl;
		}
	}
	else
		if (opt == 2)
		{
			string date;
			cout << "Dati data: ";
			cin >> date;
			vector<Resurse*> r = service->findByDate(date);
			for (Resurse* crt : r)
			{
				cout << crt->toStringDelimiter(" ") << endl;
			}
		}

}