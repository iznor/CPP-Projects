#include "Avengers.h"

int main() {

	SuperHero* superArr[5];
	superArr[0] = new SuperHero("Clark Kent", 25, true, false);
	superArr[1] = new ProfessionBasedSuperHero("IronMan",38,false,"entrepreneur",18, false);
	superArr[2] = new AnimalBasedSuperHero("Scott Lang", 30, false, "Ant", false);
	superArr[3] = new CaptainAmerica("Steve Rogers", 22, true, "soldier", 75,false , 89);
	superArr[4] = new Spiderman("Peter Parker", 17, true, "spider", 2.3, false);
	
	Avengers team("Avengers");														
	team.setSuperHeros(superArr, 5);													
	cout << team << endl;															
	team.addSuperHero(new AnimalBasedSuperHero("Batman", 35, false, "Bat", false));	
	team.initiateTeamAttack(true);
	team.printAvengersTeam();
	cout << team << endl;
	
	//===================================================================================//	
	//	Besides the classes, 															 //
	//	'int main()' also allocates new memory, so it must be responisble for freeing it //
	//===================================================================================//
	/**/	for (int i = 0; i < 5; i++)													 //
	/**/	{																			 //
	/**/		delete superArr[i];														 //
	/**/	}																			 //
	/*===================================================================================*/
	
	return 0;
}
