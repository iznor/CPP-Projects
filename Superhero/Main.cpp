#include "Avengers.h"



int main() {

	
	SuperHero* superArr[6];
	superArr[0] = new SuperHero("Clark Kent", 25);
	superArr[1] = new ProfessionBasedSuperHero("IronMan",38,false,"entrepreneur",18);
	superArr[2] = new AnimalBasedSuperHero("Scott Lang", 30, false, "Ant");
	superArr[3] = new CaptainAmerica("Steve Rogers", 22, true, "soldier", 75, 89);
	superArr[4] = new Spiderman("Peter Parker", 17, true, "spider", 2.3);
	superArr[5] = new CaptainSpider("Peter Rogers", 20, true, "soldier", 3, 53, "spider", 3.4);

	
	Avengers team;
	ofstream out_file("avengers.bin", ios::binary | ios::out);
	team.setSuperHeros(superArr,6);


	team.save(out_file);

	out_file.close();
	
//	Avengers team;
//	ifstream in_file("avengers.bin", ios::binary | ios::in);

//	team.load(in_file);
	

//	in_file.close();
	
	
	return 0;
}
