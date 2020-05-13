// GestiuneResurseEconomice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Teste.h"
#include"UI.h"

int main()
{
    Test t;
    t.runTests();
    std::cout << "Testele au trecut!\n";

    int opt;
    std::cout << "1.CSV" << endl;
    std::cout << "2.TXT" << endl;
    std::cout << "Optiunea dvs este:";
    std::cin >> opt;

    ValidatorResurse* v = new ValidatorResurse();
    ValidatorUtilizator* u = new ValidatorUtilizator();

    if (opt == 2)
    {
        RepoFile* repoResurseFinanciare = new RepoFileTXT("ResurseFinanciare.txt", v);
        RepoFile* repoResurseMateriale = new RepoFileTXT("ResurseMateriale.txt", v);
        RepoUser* repoUsers = new RepoUser(u, "Utilizatori.txt");
        Service* serviceResurse = new Service(*repoResurseFinanciare, *repoResurseMateriale, *repoUsers);
        UI* ui = new UI(*serviceResurse);
        ui->showMenuLogin();
    }
    else
    {
        RepoFile* repoResurseFinanciare = new RepoFileTXT("ResurseFinanciare.csv", v);
        RepoFile* repoResurseMateriale = new RepoFileTXT("ResurseMateriale.csv", v);
        RepoUser* repoUsers = new RepoUser(u, "Utilizatori.csv");
        Service* serviceResurse = new Service(*repoResurseFinanciare, *repoResurseMateriale, *repoUsers);
        UI* ui = new UI(*serviceResurse);
        ui->showMenuLogin();
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
