#pragma once
#include "Resurse.h"
#include "ResurseFinanciare.h"
#include "ResurseMateriale.h"
#include "Utilizator.h"
#include "RepositoryFile.h"
#include "RepositoryFileCSV.h"
#include "RepositoryFileTXT.h"
#include "IRepository.h"
#include "ValidatorResurse.h"
#include "ValidatorResurseFinanciare.h"
#include "ValidatorResurseMateriale.h"
#include "ValidatorUtilizator.h"
#include "ValidatorExceptii.h"
#include "Service.h"



class Test
{
private:
	void testResurse();
	void testResurseGetter();
	void testResurseSetter();
	void testResurseFinanciare();
	void testResurseFinanciareGetter();
	void testResurseFinanciareSetter();
	void testResurseMateriale();
	void testResurseMaterialeGetter();
	void testResurseMaterialeSetter();

	void testRepository();
	void testRepoFileTXT();
	void testRepoFileTXTAdd();
	void testRepoFileTXTDel();
	void testRepoFileTXTGetAll();
	void testRepoFileTXTGetElement();
	void testRepoFileTXTUpdate();
	void testRepoFileTXTLoadFromFile();
	void testRepoFileTXTSaveToFile();
	void testRepoFileCSV();
	void testRepoFileCSVSaveToFile();
	void testRepoFileCSVLoadFromFile();

	void testService();
	void testServiceAdd();
	void testServiceUpdate();
	void testServiceLogin();
	void testServiceFind();

	void testUtilizator();
	void testRepoUser();
	void testRepoUserAdd();
	void testRepoUserUpdate();
	void testRepoUserDelete();
	void testRepoUserFind();

	void testExceptii();

public:
	void runTests();

};