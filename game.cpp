#include "game.h"

//constructor
game::game() {

	this->choice = 0;
	this->playing = true;
	this->pasirinkimasMenu = 0;
	this->pasirinkParduot=0;
	this->pasirinkPirkt=0;
	this->pasirinkParduotuve = 0;
}

//destructor
game::~game() {

}

//funkcijos
void game::initializeGame() {

	std::string name;
	std::cout << "Iveskite veikejo varda: " << std::endl;
	getline(std::cin, name);
	karvedys.initialize(name);
}


void game::MainMenu() {
	std::cout << std::endl;
	karvedys.printInfo();
	std::cout << "Main Menu\n";
	std::cout << "1. Keliauti \n";
	std::cout << "2. Inventorius \n";
	std::cout << "3. Lygis \n";
	std::cout << "0. Iseiti \n";

	std::cout << std::endl << "Pasirinkimas: ";
	std::cin >> choice;
	std::cout << std::endl;
	system("cls");
	switch (choice) {
	case 0: //quit
		playing = false;
		break;
	case 1: //travel
		travel();
		break;
	case 2://inventory
		kuprine.printInv();
		break;
	case 3://levelup
		karvedys.levelUp();
		break;
	default:
		break;

	}
}

void game::ejimas() {

	karvedys.ejimas();

	Truviskes.kaimasEjimas();
	Barteliskes.kaimasEjimas();
	Teviskes.kaimasEjimas();
	Triogalai.kaimasEjimas();
	Turipai.kaimasEjimas();
	Karoliskes.kaimasEjimas();
	Pakalniskes.kaimasEjimas();
	Genininkai.kaimasEjimas();
	Ariogala.kaimasEjimas();
	Zemzeniai.kaimasEjimas();
	Dumbirdai.kaimasEjimas();
	Likoniai.kaimasEjimas();
	Ceckes.kaimasEjimas();
	Grazdionys.kaimasEjimas();
	Programintai.kaimasEjimas();

	Frankite.pilisEjimas();
	Germanite.pilisEjimas();
	Svedite.pilisEjimas();
	Italiano.pilisEjimas();
	Galiano.pilisEjimas();
	Vikingaites.pilisEjimas();
	Lituanica.pilisEjimas();
	Zemaiteskai.pilisEjimas();
	Ruskiai.pilisEjimas();
	Otomanijai.pilisEjimas();

	Vandalai.banditaiEjimas();
	Daktarai.banditaiEjimas();
	Tulpiniai.banditaiEjimas();
	Princai.banditaiEjimas();
	Daskiniai.banditaiEjimas();
	Caponiai.banditaiEjimas();
	Vutangai.banditaiEjimas();
	Kursiai.banditaiEjimas();
	Garbetroskos.banditaiEjimas();
	Kobros.banditaiEjimas();
}

int game::battle(int priesai, int ginklai, double multiplier) {

	srand(time(NULL));
	int playerRoll{ 0 }, enemyRoll{ 0 };
	int dmgPlayer{ 0 }, dmgEnemy{ 0 };
	int karvedzioGinklai{ karvedys.getGinklai() };
	if (ginklai > priesai) {
		ginklai = priesai;
	}
	if (karvedys.getGinklai() > karvedys.getKariai()) {
		karvedzioGinklai = karvedys.getKariai();
	}
	while (karvedys.getKariai() > 0 && priesai > 0) {

		playerRoll = rand() % 10 + 1;
		enemyRoll = rand() % 10 + 1;
		dmgPlayer = static_cast<int> ((playerRoll * ((karvedys.getLevel()) + ((karvedzioGinklai / 2) + (karvedys.getKariai() / 2)) / 3) / 10));
		dmgEnemy = static_cast<int> ((enemyRoll * multiplier * ((ginklai / 2) + (priesai / 2)) / 3) / 10);
		if (dmgEnemy > karvedys.getKariai()) // bounds check
			dmgEnemy = karvedys.getKariai();; 
		if (dmgPlayer > priesai)// bounds check
			dmgPlayer = priesai;
		karvedys.setKariai(-dmgEnemy);
		priesai = priesai - dmgPlayer;
		std::cout << std::endl;
		if (karvedys.getKariai() < 0)
			karvedys.setKariai(0);
		if (priesai < 0)
			priesai = 0;
		std::cout << "Patyrete: " << dmgEnemy << " nuostoliu" << std::endl;
		std::cout << "Priesai patyre " << dmgPlayer << " nuostoliu" << std::endl;
		std::cout << "------------------------\n";
		std::cout << "Jum liko: " << karvedys.getKariai() << " kariu" << std::endl;
		std::cout << "Priesam liko " << priesai << " kariu" << std::endl;
		std::cout << "------------------------\n";
		Sleep(2000);
	}
	return priesai;
}

void game::banditMenu(int location) {

	int pasirinkimasMenu = 0;
	int isgyvenePriesuKariai{ 0 };
	while (pasirinkimasMenu != 4) {
		system("cls");
		karvedys.printInfo();
		std::cout << std::endl;
		std::cout << "Atvykote i banditu stovykla\n";
		std::cout << "-----------------\n";
		if (location == 40) {
			Vandalai.printInfo();
		}
		if (location == 41) {
			Daktarai.printInfo();
		}
		if (location == 42) {
			Tulpiniai.printInfo();
		}
		if (location == 43) {
			Princai.printInfo();
		}
		if (location == 44) {
			Daskiniai.printInfo();
		}
		if (location == 45) {
			Caponiai.printInfo();
		}
		if (location == 46) {
			Vutangai.printInfo();
		}
		if (location == 47) {
			Kursiai.printInfo();
		}
		if (location == 48) {
			Garbetroskos.printInfo();
		}
		if (location == 49) {
			Kobros.printInfo();
		}
		std::cout << "-----------------\n";
		std::cout << "Bandytu stovyklos Meniu\n";
		std::cout << "1. Reiduoti \n";
		std::cout << "0. Keliauti toliau \n";
		std::cout << "-----------------\n";
		std::cout << std::endl << "Pasirinkimas: ";
		std::cin >> pasirinkimasMenu;
		std::cout << std::endl;

		switch (pasirinkimasMenu) {
		case 0: //eiti toliau
			pasirinkimasMenu = 4;
			break;
		case 1: //reiduoti
			if (location == 40) {
				isgyvenePriesuKariai = battle(Vandalai.getKariai(), Vandalai.getGinklai(), 2);
				karvedys.setExp(Vandalai.getKariai() - isgyvenePriesuKariai, 2);
				Vandalai.kariaiPoMusio(isgyvenePriesuKariai);
				if (karvedys.getKariai() > 0) {
					std::cout << "Laimejote!" << std::endl;
					karvedys.setAuksiniai(Vandalai.getAuksiniai(), 1);
					Vandalai.auksasPoMusio(0);
					karvedys.setGinklai(Vandalai.getGinklai()/10);
					Vandalai.ginklaiPoMusio(0);
					karvedys.setMaistas(Vandalai.getMaistas());
					Vandalai.maistasPoMusio(0);
				}
				else if (isgyvenePriesuKariai > 0) {
					std::cout << "Keliauk is kur sugrizai!" << std::endl;
				}
				Sleep(800);
			}
			else if (location == 41) {
				isgyvenePriesuKariai = battle(Daktarai.getKariai(), Daktarai.getGinklai(), 2);
				karvedys.setExp(Daktarai.getKariai() - isgyvenePriesuKariai, 2);
				Daktarai.kariaiPoMusio(isgyvenePriesuKariai);
				if (karvedys.getKariai() > 0) {
					std::cout << "Laimejote!" << std::endl;
					karvedys.setAuksiniai(Daktarai.getAuksiniai(), 1);
					Daktarai.auksasPoMusio(0);
					karvedys.setGinklai(Daktarai.getGinklai()/10);
					Daktarai.ginklaiPoMusio(0);
					karvedys.setMaistas(Daktarai.getMaistas());
					Daktarai.maistasPoMusio(0);
				}
				else if (isgyvenePriesuKariai > 0) {
					std::cout << "Keliauk is kur sugrizai!" << std::endl;
				}
				Sleep(800);
			}
			else if (location == 42) {
				isgyvenePriesuKariai = battle(Tulpiniai.getKariai(), Tulpiniai.getGinklai(), 2);
				karvedys.setExp(Tulpiniai.getKariai() - isgyvenePriesuKariai, 2);
				Tulpiniai.kariaiPoMusio(isgyvenePriesuKariai);
				if (karvedys.getKariai() > 0) {
					std::cout << "Laimejote!" << std::endl;
					karvedys.setAuksiniai(Tulpiniai.getAuksiniai(), 1);
					Tulpiniai.auksasPoMusio(0);
					karvedys.setGinklai(Tulpiniai.getGinklai() / 10);
					Tulpiniai.ginklaiPoMusio(0);
					karvedys.setMaistas(Tulpiniai.getMaistas());
					Tulpiniai.maistasPoMusio(0);
				}
				else if (isgyvenePriesuKariai > 0) {
					std::cout << "Keliauk is kur sugrizai!" << std::endl;
				}
				Sleep(800);
			}
			else if (location == 43) {
				isgyvenePriesuKariai = battle(Princai.getKariai(), Princai.getGinklai(), 2);
				karvedys.setExp(Princai.getKariai() - isgyvenePriesuKariai, 2);
				Princai.kariaiPoMusio(isgyvenePriesuKariai);
				if (karvedys.getKariai() > 0) {
					std::cout << "Laimejote!" << std::endl;
					karvedys.setAuksiniai(Princai.getAuksiniai(), 1);
					Princai.auksasPoMusio(0);
					karvedys.setGinklai(Princai.getGinklai() / 10);
					Princai.ginklaiPoMusio(0);
					karvedys.setMaistas(Princai.getMaistas());
					Princai.maistasPoMusio(0);
				}
				else if (isgyvenePriesuKariai > 0) {
					std::cout << "Keliauk is kur sugrizai!" << std::endl;
				}
				Sleep(800);
			}
			else if (location == 44) {
				isgyvenePriesuKariai = battle(Daskiniai.getKariai(), Daskiniai.getGinklai(), 2);
				karvedys.setExp(Daskiniai.getKariai() - isgyvenePriesuKariai, 2);
				Daskiniai.kariaiPoMusio(isgyvenePriesuKariai);
				if (karvedys.getKariai() > 0) {
					std::cout << "Laimejote!" << std::endl;
					karvedys.setAuksiniai(Daskiniai.getAuksiniai(), 1);
					Daskiniai.auksasPoMusio(0);
					karvedys.setGinklai(Daskiniai.getGinklai() / 10);
					Daskiniai.ginklaiPoMusio(0);
					karvedys.setMaistas(Daskiniai.getMaistas());
					Daskiniai.maistasPoMusio(0);
				}
				else if (isgyvenePriesuKariai > 0) {
					std::cout << "Keliauk is kur sugrizai!" << std::endl;
				}
				Sleep(800);
			}
			else if (location == 45) {
				isgyvenePriesuKariai = battle(Caponiai.getKariai(), Caponiai.getGinklai(), 2);
				karvedys.setExp(Caponiai.getKariai() - isgyvenePriesuKariai, 2);
				Caponiai.kariaiPoMusio(isgyvenePriesuKariai);
				if (karvedys.getKariai() > 0) {
					std::cout << "Laimejote!" << std::endl;
					karvedys.setAuksiniai(Caponiai.getAuksiniai(), 1);
					Caponiai.auksasPoMusio(0);
					karvedys.setGinklai(Caponiai.getGinklai() / 10);
					Caponiai.ginklaiPoMusio(0);
					karvedys.setMaistas(Caponiai.getMaistas());
					Caponiai.maistasPoMusio(0);
				}
				else if (isgyvenePriesuKariai > 0) {
					std::cout << "Keliauk is kur sugrizai!" << std::endl;
				}
				Sleep(800);
			}
			else if (location == 46) {
				isgyvenePriesuKariai = battle(Vutangai.getKariai(), Vutangai.getGinklai(), 2);
				karvedys.setExp(Vutangai.getKariai() - isgyvenePriesuKariai, 2);
				Vutangai.kariaiPoMusio(isgyvenePriesuKariai);
				if (karvedys.getKariai() > 0) {
					std::cout << "Laimejote!" << std::endl;
					karvedys.setAuksiniai(Vutangai.getAuksiniai(), 1);
					Vutangai.auksasPoMusio(0);
					karvedys.setGinklai(Vutangai.getGinklai() / 10);
					Vutangai.ginklaiPoMusio(0);
					karvedys.setMaistas(Vutangai.getMaistas());
					Vutangai.maistasPoMusio(0);
				}
				else if (isgyvenePriesuKariai > 0) {
					std::cout << "Keliauk is kur sugrizai!" << std::endl;
				}
				Sleep(800);
			}
			else if (location == 47) {
				isgyvenePriesuKariai = battle(Kursiai.getKariai(), Kursiai.getGinklai(), 2);
				karvedys.setExp(Kursiai.getKariai() - isgyvenePriesuKariai, 2);
				Kursiai.kariaiPoMusio(isgyvenePriesuKariai);
				if (karvedys.getKariai() > 0) {
					std::cout << "Laimejote!" << std::endl;
					karvedys.setAuksiniai(Kursiai.getAuksiniai(), 1);
					Kursiai.auksasPoMusio(0);
					karvedys.setGinklai(Kursiai.getGinklai() / 10);
					Kursiai.ginklaiPoMusio(0);
					karvedys.setMaistas(Kursiai.getMaistas());
					Kursiai.maistasPoMusio(0);
				}
				else if (isgyvenePriesuKariai > 0) {
					std::cout << "Keliauk is kur sugrizai!" << std::endl;
				}
				Sleep(800);
			}
			else if (location == 48) {
				isgyvenePriesuKariai = battle(Garbetroskos.getKariai(), Garbetroskos.getGinklai(), 2);
				karvedys.setExp(Garbetroskos.getKariai() - isgyvenePriesuKariai, 2);
				Garbetroskos.kariaiPoMusio(isgyvenePriesuKariai);
				if (karvedys.getKariai() > 0) {
					std::cout << "Laimejote!" << std::endl;
					karvedys.setAuksiniai(Garbetroskos.getAuksiniai(), 1);
					Garbetroskos.auksasPoMusio(0);
					karvedys.setGinklai(Garbetroskos.getGinklai() / 10);
					Garbetroskos.ginklaiPoMusio(0);
					karvedys.setMaistas(Garbetroskos.getMaistas());
					Garbetroskos.maistasPoMusio(0);
				}
				else if (isgyvenePriesuKariai > 0) {
					std::cout << "Keliauk is kur sugrizai!" << std::endl;
				}
				Sleep(800);
			}
			else if (location == 49) {
				isgyvenePriesuKariai = battle(Kobros.getKariai(), Kobros.getGinklai(), 2);
				karvedys.setExp(Kobros.getKariai() - isgyvenePriesuKariai, 2);
				Kobros.kariaiPoMusio(isgyvenePriesuKariai);
				if (karvedys.getKariai() > 0) {
					std::cout << "Laimejote!" << std::endl;
					karvedys.setAuksiniai(Kobros.getAuksiniai(), 1);
					Kobros.auksasPoMusio(0);
					karvedys.setGinklai(Kobros.getGinklai() / 10);
					Kobros.ginklaiPoMusio(0);
					karvedys.setMaistas(Kobros.getMaistas());
					Kobros.maistasPoMusio(0);
				}
				else if (isgyvenePriesuKariai > 0) {
					std::cout << "Keliauk is kur sugrizai!" << std::endl;
				}
				Sleep(800);
			}
			break;
		default:
			std::cout << "Tokio pasirinkimo nera" << std::endl;
			break;
		}
	}
	system("cls");
}

void game::pilisMenu(int location) {

	int pasirinkimasMenu = 0;
	int isgyvenePriesuKariai{ 0 };
	int verbuotiKariai{ 0 };
	while (pasirinkimasMenu != 4) {
		system("cls");
		karvedys.printInfo();
		std::cout << std::endl;
		std::cout << "Atvykote i pili\n";
		std::cout << "-----------------\n";
		if (location == 30) {
			Frankite.printInfo();
		}
		if (location == 31) {
			Germanite.printInfo();
		}
		if (location == 32) {
			Svedite.printInfo();
		}
		if (location == 33) {
			Italiano.printInfo();
		}
		if (location == 34) {
			Galiano.printInfo();
		}
		if (location == 35) {
			Vikingaites.printInfo();
		}
		if (location == 36) {
			Lituanica.printInfo();
		}
		if (location == 37) {
			Zemaiteskai.printInfo();
		}
		if (location == 38) {
			Ruskiai.printInfo();
		}
		if (location == 39) {
			Otomanijai.printInfo();
		}
		std::cout << "-----------------\n";
		std::cout << "Pilies Meniu\n";
		std::cout << "1. Parduotuve \n";
		std::cout << "2. Verbuoti karius \n";
		std::cout << "3. Uzkariauti \n";
		std::cout << "0. Iseiti \n";
		std::cout << "-----------------\n";
		std::cout << std::endl << "Pasirinkimas: ";
		std::cin >> pasirinkimasMenu;
		std::cout << std::endl;
		switch (pasirinkimasMenu) {
		case 0: //quit
			pasirinkimasMenu = 4;
			break;
		case 1: // parduotuve
			parduotuveMenu(location);
			break;
		case 2: // verbuoti karius
			if (location == 30) {
				std::cout << "Kiek kariu norite verbuoti? | kario kaina: 12 auksiniai | kariu skaicius: " << Frankite.getVerbuotKariai() << std::endl;
				std::cin >> verbuotiKariai;
				if (Frankite.getVerbuotKariai() < verbuotiKariai) {
					std::cout << "Nera tiek kariu!" << std::endl;
				}
				else if (karvedys.getAuksiniai() < verbuotiKariai * 12) {
					std::cout << "Neturite tiek auksiniu!" << std::endl;
				}
				else {
					karvedys.setKariai(verbuotiKariai);
					karvedys.setAuksiniai(-verbuotiKariai, 12);
					std::cout << std::endl;
					std::cout << "Uzverbavote: " << verbuotiKariai << " karius" << std::endl;
					Frankite.setVerbuotKariai(-verbuotiKariai);
				}
				Sleep(800);
			}
			else if (location == 31) {
				std::cout << "Kiek kariu norite verbuoti? | kario kaina: 12 auksiniai | kariu skaicius: " << Germanite.getVerbuotKariai() << std::endl;
				std::cin >> verbuotiKariai;
				if (Germanite.getVerbuotKariai() < verbuotiKariai) {
					std::cout << "Nera tiek kariu!" << std::endl;
				}
				else if (karvedys.getAuksiniai() < verbuotiKariai * 12) {
					std::cout << "Neturite tiek auksiniu!" << std::endl;
				}
				else {
					karvedys.setKariai(verbuotiKariai);
					karvedys.setAuksiniai(-verbuotiKariai, 12);
					std::cout << std::endl;
					std::cout << "Uzverbavote: " << verbuotiKariai << " karius" << std::endl;
					Germanite.setVerbuotKariai(-verbuotiKariai);
				}
				Sleep(800);
			}
			else if (location == 32) {
				std::cout << "Kiek kariu norite verbuoti? | kario kaina: 12 auksiniai | kariu skaicius: " << Svedite.getVerbuotKariai() << std::endl;
				std::cin >> verbuotiKariai;
				if (Svedite.getVerbuotKariai() < verbuotiKariai) {
					std::cout << "Nera tiek kariu!" << std::endl;
				}
				else if (karvedys.getAuksiniai() < verbuotiKariai * 12) {
					std::cout << "Neturite tiek auksiniu!" << std::endl;
				}
				else {
					karvedys.setKariai(verbuotiKariai);
					karvedys.setAuksiniai(-verbuotiKariai, 12);
					std::cout << std::endl;
					std::cout << "Uzverbavote: " << verbuotiKariai << " karius" << std::endl;
					Svedite.setVerbuotKariai(-verbuotiKariai);
				}
				Sleep(800);
			}
			else if (location == 33) {
				std::cout << "Kiek kariu norite verbuoti? | kario kaina: 12 auksiniai| kariu skaicius: " << Italiano.getVerbuotKariai() << std::endl;
				std::cin >> verbuotiKariai;
				if (Italiano.getVerbuotKariai() < verbuotiKariai) {
					std::cout << "Nera tiek kariu!" << std::endl;
				}
				else if (karvedys.getAuksiniai() < verbuotiKariai * 12) {
					std::cout << "Neturite tiek auksiniu!" << std::endl;
				}
				else {
					karvedys.setKariai(verbuotiKariai);
					karvedys.setAuksiniai(-verbuotiKariai, 12);
					std::cout << std::endl;
					std::cout << "Uzverbavote: " << verbuotiKariai << " karius" << std::endl;
					Italiano.setVerbuotKariai(-verbuotiKariai);
				}
				Sleep(800);
			}
			else if (location == 34) {
				std::cout << "Kiek kariu norite verbuoti? | kario kaina: 12 auksiniai | kariu skaicius: " << Galiano.getVerbuotKariai() << std::endl;
				std::cin >> verbuotiKariai;
				if (Galiano.getVerbuotKariai() < verbuotiKariai) {
					std::cout << "Nera tiek kariu!" << std::endl;
				}
				else if (karvedys.getAuksiniai() < verbuotiKariai * 12) {
					std::cout << "Neturite tiek auksiniu!" << std::endl;
				}
				else {
					karvedys.setKariai(verbuotiKariai);
					karvedys.setAuksiniai(-verbuotiKariai, 12);
					std::cout << std::endl;
					std::cout << "Uzverbavote: " << verbuotiKariai << " karius" << std::endl;
					Galiano.setVerbuotKariai(-verbuotiKariai);
				}
				Sleep(800);
			}
			else if (location == 35) {
				std::cout << "Kiek kariu norite verbuoti? | kario kaina: 12 auksiniai | kariu skaicius: " << Vikingaites.getVerbuotKariai() << std::endl;
				std::cin >> verbuotiKariai;
				if (Vikingaites.getVerbuotKariai() < verbuotiKariai) {
					std::cout << "Nera tiek kariu!" << std::endl;
				}
				else if (karvedys.getAuksiniai() < verbuotiKariai * 12) {
					std::cout << "Neturite tiek auksiniu!" << std::endl;
				}
				else {
					karvedys.setKariai(verbuotiKariai);
					karvedys.setAuksiniai(-verbuotiKariai, 12);
					std::cout << std::endl;
					std::cout << "Uzverbavote: " << verbuotiKariai << " karius" << std::endl;
					Vikingaites.setVerbuotKariai(-verbuotiKariai);
				}
				Sleep(800);
			}
			else if (location == 36) {
				std::cout << "Kiek kariu norite verbuoti? | kario kaina: 12 auksiniai | kariu skaicius: " << Lituanica.getVerbuotKariai() << std::endl;
				std::cin >> verbuotiKariai;
				if (Lituanica.getVerbuotKariai() < verbuotiKariai) {
					std::cout << "Nera tiek kariu!" << std::endl;
				}
				else if (karvedys.getAuksiniai() < verbuotiKariai * 12) {
					std::cout << "Neturite tiek auksiniu!" << std::endl;
				}
				else {
					karvedys.setKariai(verbuotiKariai);
					karvedys.setAuksiniai(-verbuotiKariai, 12);
					std::cout << std::endl;
					std::cout << "Uzverbavote: " << verbuotiKariai << " karius" << std::endl;
					Lituanica.setVerbuotKariai(-verbuotiKariai);
				}
				Sleep(800);
			}
			else if (location == 37) {
				std::cout << "Kiek kariu norite verbuoti? | kario kaina: 12 auksiniai | kariu skaicius: " << Zemaiteskai.getVerbuotKariai() << std::endl;
				std::cin >> verbuotiKariai;
				if (Zemaiteskai.getVerbuotKariai() < verbuotiKariai) {
					std::cout << "Nera tiek kariu!" << std::endl;
				}
				else if (karvedys.getAuksiniai() < verbuotiKariai * 12) {
					std::cout << "Neturite tiek auksiniu!" << std::endl;
				}
				else {
					karvedys.setKariai(verbuotiKariai);
					karvedys.setAuksiniai(-verbuotiKariai, 12);
					std::cout << std::endl;
					std::cout << "Uzverbavote: " << verbuotiKariai << " karius" << std::endl;
					Zemaiteskai.setVerbuotKariai(-verbuotiKariai);
					Sleep(800);
				}
			}
			else if (location == 38) {
				std::cout << "Kiek kariu norite verbuoti? | kario kaina: 12 auksiniai | kariu skaicius: " << Ruskiai.getVerbuotKariai() << std::endl;
				std::cin >> verbuotiKariai;
				if (Ruskiai.getVerbuotKariai() < verbuotiKariai) {
					std::cout << "Nera tiek kariu!" << std::endl;
				}
				else if (karvedys.getAuksiniai() < verbuotiKariai * 12) {
					std::cout << "Neturite tiek auksiniu!" << std::endl;
				}
				else {
					karvedys.setKariai(verbuotiKariai);
					karvedys.setAuksiniai(-verbuotiKariai, 12);
					std::cout << std::endl;
					std::cout << "Uzverbavote: " << verbuotiKariai << " karius" << std::endl;
					Ruskiai.setVerbuotKariai(-verbuotiKariai);
					
				}
				Sleep(800);
			}
			else if (location == 39) {
				std::cout << "Kiek kariu norite verbuoti? | kario kaina: 12 auksiniai | kariu skaicius: " << Otomanijai.getVerbuotKariai() << std::endl;
				std::cin >> verbuotiKariai;
				if (Otomanijai.getVerbuotKariai() < verbuotiKariai) {
					std::cout << "Nera tiek kariu!" << std::endl;
				}
				else if (karvedys.getAuksiniai() < verbuotiKariai * 12) {
					std::cout << "Neturite tiek auksiniu!" << std::endl;
				}
				else {
					karvedys.setKariai(verbuotiKariai);
					karvedys.setAuksiniai(-verbuotiKariai, 12);
					std::cout << std::endl;
					std::cout << "Uzverbavote: " << verbuotiKariai << " karius" << std::endl;
					Otomanijai.setVerbuotKariai(-verbuotiKariai);
				}
				Sleep(800);
			}
		break;
		case 3: // uzkariauti
			if (location == 30) {
				isgyvenePriesuKariai = battle(Frankite.getKariai(), Frankite.getGinklai(), 2.5);
				karvedys.setExp(Frankite.getKariai() - isgyvenePriesuKariai, 3);
				Frankite.kariaiPoMusio(isgyvenePriesuKariai);
				if (karvedys.getKariai() > 0) {
					std::cout << "Laimejote!" << std::endl;
					karvedys.setAuksiniai(Frankite.getAuksiniai(), 1);
					Frankite.auksasPoMusio(0);
					karvedys.setGinklai(Frankite.getGinklai());
					Frankite.ginklaiPoMusio(0);
					karvedys.setMaistas(Frankite.getMaistas());
					Frankite.maistasPoMusio(0);
				}
				else if (isgyvenePriesuKariai > 0) {
					std::cout << "n00b!" << std::endl;
				}
				Sleep(800);
			}
			else if (location == 31) {
				isgyvenePriesuKariai = battle(Germanite.getKariai(), Germanite.getGinklai(), 2.5);
				karvedys.setExp(Germanite.getKariai() - isgyvenePriesuKariai, 3);
				Germanite.kariaiPoMusio(isgyvenePriesuKariai);
				if (karvedys.getKariai() > 0) {
					std::cout << "Laimejote!" << std::endl;
					karvedys.setAuksiniai(Germanite.getAuksiniai(), 1);
					Germanite.auksasPoMusio(0);
					karvedys.setGinklai(Germanite.getGinklai());
					Germanite.ginklaiPoMusio(0);
					karvedys.setMaistas(Germanite.getMaistas());
					Germanite.maistasPoMusio(0);
				}
				else if (isgyvenePriesuKariai > 0) {
					std::cout << "n00b!" << std::endl;
				}
				Sleep(800);
			}
			else if (location == 32) {
				isgyvenePriesuKariai = battle(Svedite.getKariai(), Svedite.getGinklai(), 2.5);
				karvedys.setExp(Svedite.getKariai() - isgyvenePriesuKariai, 3);
				Svedite.kariaiPoMusio(isgyvenePriesuKariai);
				if (karvedys.getKariai() > 0) {
					std::cout << "Laimejote!" << std::endl;
					karvedys.setAuksiniai(Svedite.getAuksiniai(), 1);
					Svedite.auksasPoMusio(0);
					karvedys.setGinklai(Svedite.getGinklai());
					Svedite.ginklaiPoMusio(0);
					karvedys.setMaistas(Svedite.getMaistas());
					Svedite.maistasPoMusio(0);
				}
				else if (isgyvenePriesuKariai > 0) {
					std::cout << "n00b!" << std::endl;
				}
				Sleep(800);
			}
			else if (location == 33) {
				isgyvenePriesuKariai = battle(Italiano.getKariai(), Italiano.getGinklai(), 2.5);
				karvedys.setExp(Italiano.getKariai() - isgyvenePriesuKariai, 3);
				Italiano.kariaiPoMusio(isgyvenePriesuKariai);
				if (karvedys.getKariai() > 0) {
					std::cout << "Laimejote!" << std::endl;
					karvedys.setAuksiniai(Italiano.getAuksiniai(), 1);
					Italiano.auksasPoMusio(0);
					karvedys.setGinklai(Italiano.getGinklai());
					Italiano.ginklaiPoMusio(0);
					karvedys.setMaistas(Italiano.getMaistas());
					Italiano.maistasPoMusio(0);
				}
				else if (isgyvenePriesuKariai > 0) {
					std::cout << "n00b!" << std::endl;
				}
				Sleep(800);
			}
			else if (location == 34) {
				isgyvenePriesuKariai = battle(Galiano.getKariai(), Galiano.getGinklai(), 2.5);
				karvedys.setExp(Galiano.getKariai() - isgyvenePriesuKariai, 3);
				Galiano.kariaiPoMusio(isgyvenePriesuKariai);
				if (karvedys.getKariai() > 0) {
					std::cout << "Laimejote!" << std::endl;
					karvedys.setAuksiniai(Galiano.getAuksiniai(), 1);
					Galiano.auksasPoMusio(0);
					karvedys.setGinklai(Galiano.getGinklai());
					Galiano.ginklaiPoMusio(0);
					karvedys.setMaistas(Galiano.getMaistas());
					Galiano.maistasPoMusio(0);
				}
				else if (isgyvenePriesuKariai > 0) {
					std::cout << "n00b!" << std::endl;
				}
				Sleep(800);
			}
			else if (location == 35) {
				isgyvenePriesuKariai = battle(Vikingaites.getKariai(), Vikingaites.getGinklai(), 2.5);
				karvedys.setExp(Vikingaites.getKariai() - isgyvenePriesuKariai, 3);
				Vikingaites.kariaiPoMusio(isgyvenePriesuKariai);
				if (karvedys.getKariai() > 0) {
					std::cout << "Laimejote!" << std::endl;
					karvedys.setAuksiniai(Vikingaites.getAuksiniai(), 1);
					Vikingaites.auksasPoMusio(0);
					karvedys.setGinklai(Vikingaites.getGinklai());
					Vikingaites.ginklaiPoMusio(0);
					karvedys.setMaistas(Vikingaites.getMaistas());
					Vikingaites.maistasPoMusio(0);
				}
				else if (isgyvenePriesuKariai > 0) {
					std::cout << "n00b!" << std::endl;
				}
				Sleep(800);
			}
			else if (location == 36) {
			isgyvenePriesuKariai = battle(Lituanica.getKariai(), Lituanica.getGinklai(), 2.5);
			karvedys.setExp(Lituanica.getKariai() - isgyvenePriesuKariai, 3);
			Lituanica.kariaiPoMusio(isgyvenePriesuKariai);
			if (karvedys.getKariai() > 0) {
				std::cout << "Laimejote!" << std::endl;
				karvedys.setAuksiniai(Lituanica.getAuksiniai(), 1);
				Lituanica.auksasPoMusio(0);
				karvedys.setGinklai(Lituanica.getGinklai());
				Lituanica.ginklaiPoMusio(0);
				karvedys.setMaistas(Lituanica.getMaistas());
				Lituanica.maistasPoMusio(0);
			}
			else if (isgyvenePriesuKariai > 0) {
				std::cout << "n00b!" << std::endl;
			}
			Sleep(800);
			}
			else if (location == 37) {
			isgyvenePriesuKariai = battle(Zemaiteskai.getKariai(), Zemaiteskai.getGinklai(), 2.5);
			karvedys.setExp(Zemaiteskai.getKariai() - isgyvenePriesuKariai, 3);
			Zemaiteskai.kariaiPoMusio(isgyvenePriesuKariai);
			if (karvedys.getKariai() > 0) {
				std::cout << "Laimejote!" << std::endl;
				karvedys.setAuksiniai(Zemaiteskai.getAuksiniai(), 1);
				Zemaiteskai.auksasPoMusio(0);
				karvedys.setGinklai(Zemaiteskai.getGinklai());
				Zemaiteskai.ginklaiPoMusio(0);
				karvedys.setMaistas(Zemaiteskai.getMaistas());
				Zemaiteskai.maistasPoMusio(0);
			}
			else if (isgyvenePriesuKariai > 0) {
				std::cout << "n00b!" << std::endl;
			}
			Sleep(800);
			}
			else if (location == 38) {
			isgyvenePriesuKariai = battle(Ruskiai.getKariai(), Ruskiai.getGinklai(), 2.5);
			karvedys.setExp(Ruskiai.getKariai() - isgyvenePriesuKariai, 3);
			Ruskiai.kariaiPoMusio(isgyvenePriesuKariai);
			if (karvedys.getKariai() > 0) {
				std::cout << "Laimejote!" << std::endl;
				karvedys.setAuksiniai(Ruskiai.getAuksiniai(), 1);
				Ruskiai.auksasPoMusio(0);
				karvedys.setGinklai(Ruskiai.getGinklai());
				Ruskiai.ginklaiPoMusio(0);
				karvedys.setMaistas(Ruskiai.getMaistas());
				Ruskiai.maistasPoMusio(0);
			}
			else if (isgyvenePriesuKariai > 0) {
				std::cout << "n00b!" << std::endl;
			}
			Sleep(800);
			}
			else if (location == 39) {
			isgyvenePriesuKariai = battle(Otomanijai.getKariai(), Otomanijai.getGinklai(), 2.5);
			karvedys.setExp(Otomanijai.getKariai() - isgyvenePriesuKariai, 3);
			Otomanijai.kariaiPoMusio(isgyvenePriesuKariai);
			if (karvedys.getKariai() > 0) {
				std::cout << "Laimejote!" << std::endl;
				karvedys.setAuksiniai(Otomanijai.getAuksiniai(), 1);
				Otomanijai.auksasPoMusio(0);
				karvedys.setGinklai(Otomanijai.getGinklai());
				Otomanijai.ginklaiPoMusio(0);
				karvedys.setMaistas(Otomanijai.getMaistas());
				Otomanijai.maistasPoMusio(0);
			}
			else if (isgyvenePriesuKariai > 0) {
				std::cout << "n00b!" << std::endl;
			}
			Sleep(800);
			}
			break;
		default:
			std::cout << "Tokio pasirinkimo nera" << std::endl;
		}
	}
	system("cls");
}

void game::kaimasMenu(int location) {

	int pasirinkimasMenu = 0;
	int isgyvenePriesuKariai{ 0 };
	int verbuotiKariai{ 0 };
	while (pasirinkimasMenu != 4) {
		system("cls");
		karvedys.printInfo();
		std::cout << std::endl;
		std::cout << "Atvykote i kaima\n";
		std::cout << "-----------------\n";
		Truviskes.printInfo();
		std::cout << "-----------------\n";
		std::cout << "Kaimo Meniu\n";
		std::cout << "1. Parduotuve \n";
		std::cout << "2. Verbuoti karius \n";
		std::cout << "3. Reiduoti \n";
		std::cout << "0. Iseiti \n";
		std::cout << "-----------------\n";
		std::cout << std::endl << "Pasirinkimas: ";
		std::cin >> pasirinkimasMenu;
		std::cout << std::endl;
		switch (pasirinkimasMenu) {
		case 0: //quit
			pasirinkimasMenu = 4;
			break;
		case 1: // parduotuve
			parduotuveMenu(location);
			break;
		case 2: // verbuoti karius
			if (location == 20) {
				std::cout << "Kiek kariu norite verbuoti? | kario kaina: 8 auksiniai | kariu skaicius: " << Truviskes.getVerbuotKariai() << std::endl;
				std::cin >> verbuotiKariai;
				if (Truviskes.getVerbuotKariai() < verbuotiKariai) {
					std::cout << "Nera tiek kariu!" << std::endl;
				}
				else if (karvedys.getAuksiniai() < verbuotiKariai * 8) {
					std::cout << "Neturite tiek auksiniu!" << std::endl;
				}
				else {
					karvedys.setKariai(verbuotiKariai);
					karvedys.setAuksiniai(-verbuotiKariai, 8);
					std::cout << std::endl;
					std::cout << "Uzverbavote: " << verbuotiKariai << " karius" << std::endl;
					Truviskes.setVerbuotKariai(-verbuotiKariai);
				}
				Sleep(800);
			}
			else if (location == 21) {
				std::cout << "Kiek kariu norite verbuoti? | kario kaina: 8 auksiniai | kariu skaicius: " << Barteliskes.getVerbuotKariai() << std::endl;
				std::cin >> verbuotiKariai;
				if (Barteliskes.getVerbuotKariai() < verbuotiKariai) {
					std::cout << "Nera tiek kariu!" << std::endl;
				}
				else if (karvedys.getAuksiniai() < verbuotiKariai * 8) {
					std::cout << "Neturite tiek auksiniu!" << std::endl;
				}
				else {
					karvedys.setKariai(verbuotiKariai);
					karvedys.setAuksiniai(-verbuotiKariai, 8);
					std::cout << std::endl;
					std::cout << "Uzverbavote: " << verbuotiKariai << " karius" << std::endl;
					Barteliskes.setVerbuotKariai(-verbuotiKariai);
				}
				Sleep(800);
			}
			else if (location == 22) {
				std::cout << "Kiek kariu norite verbuoti? | kario kaina: 8 auksiniai | kariu skaicius: " << Teviskes.getVerbuotKariai() << std::endl;
				std::cin >> verbuotiKariai;
				if (Teviskes.getVerbuotKariai() < verbuotiKariai) {
					std::cout << "Nera tiek kariu!" << std::endl;
				}
				else if (karvedys.getAuksiniai() < verbuotiKariai * 8) {
					std::cout << "Neturite tiek auksiniu!" << std::endl;
				}
				else {
					karvedys.setKariai(verbuotiKariai);
					karvedys.setAuksiniai(-verbuotiKariai, 8);
					std::cout << std::endl;
					std::cout << "Uzverbavote: " << verbuotiKariai << " karius" << std::endl;
					Teviskes.setVerbuotKariai(-verbuotiKariai);
				}
				Sleep(800);
			}
			else if (location == 23) {
				std::cout << "Kiek kariu norite verbuoti? | kario kaina: 8 auksiniai | kariu skaicius: " << Triogalai.getVerbuotKariai() << std::endl;
				std::cin >> verbuotiKariai;
				if (Triogalai.getVerbuotKariai() < verbuotiKariai) {
					std::cout << "Nera tiek kariu!" << std::endl;
				}
				else if (karvedys.getAuksiniai() < verbuotiKariai * 8) {
					std::cout << "Neturite tiek auksiniu!" << std::endl;
				}
				else {
					karvedys.setKariai(verbuotiKariai);
					karvedys.setAuksiniai(-verbuotiKariai, 8);
					std::cout << std::endl;
					std::cout << "Uzverbavote: " << verbuotiKariai << " karius" << std::endl;
					Triogalai.setVerbuotKariai(-verbuotiKariai);
				}
				Sleep(800);
			}
			else if (location == 24) {
				std::cout << "Kiek kariu norite verbuoti? | kario kaina: 8 auksiniai | kariu skaicius: " << Turipai.getVerbuotKariai() << std::endl;
				std::cin >> verbuotiKariai;
				if (Turipai.getVerbuotKariai() < verbuotiKariai) {
					std::cout << "Nera tiek kariu!" << std::endl;
				}
				else if (karvedys.getAuksiniai() < verbuotiKariai * 8) {
					std::cout << "Neturite tiek auksiniu!" << std::endl;
				}
				else {
					karvedys.setKariai(verbuotiKariai);
					karvedys.setAuksiniai(-verbuotiKariai, 8);
					std::cout << std::endl;
					std::cout << "Uzverbavote: " << verbuotiKariai << " karius" << std::endl;
					Turipai.setVerbuotKariai(-verbuotiKariai);
				}
				Sleep(800);
			}
			else if (location == 25) {
				std::cout << "Kiek kariu norite verbuoti? | kario kaina: 8 auksiniai | kariu skaicius: " << Karoliskes.getVerbuotKariai() << std::endl;
				std::cin >> verbuotiKariai;
				if (Karoliskes.getVerbuotKariai() < verbuotiKariai) {
					std::cout << "Nera tiek kariu!" << std::endl;
				}
				else if (karvedys.getAuksiniai() < verbuotiKariai * 8) {
					std::cout << "Neturite tiek auksiniu!" << std::endl;
				}
				else {
					karvedys.setKariai(verbuotiKariai);
					karvedys.setAuksiniai(-verbuotiKariai, 8);
					std::cout << std::endl;
					std::cout << "Uzverbavote: " << verbuotiKariai << " karius" << std::endl;
					Karoliskes.setVerbuotKariai(-verbuotiKariai);
				}
				Sleep(800);
			}
			else if (location == 26) {
				std::cout << "Kiek kariu norite verbuoti? | kario kaina: 8 auksiniai | kariu skaicius: " << Pakalniskes.getVerbuotKariai() << std::endl;
				std::cin >> verbuotiKariai;
				if (Pakalniskes.getVerbuotKariai() < verbuotiKariai) {
					std::cout << "Nera tiek kariu!" << std::endl;
				}
				else if (karvedys.getAuksiniai() < verbuotiKariai * 8) {
					std::cout << "Neturite tiek auksiniu!" << std::endl;
				}
				else {
					karvedys.setKariai(verbuotiKariai);
					karvedys.setAuksiniai(-verbuotiKariai, 8);
					std::cout << std::endl;
					std::cout << "Uzverbavote: " << verbuotiKariai << " karius" << std::endl;
					Pakalniskes.setVerbuotKariai(-verbuotiKariai);
				}
				Sleep(800);
			}
			else if (location == 27) {
				std::cout << "Kiek kariu norite verbuoti? | kario kaina: 8 auksiniai | kariu skaicius: " << Genininkai.getVerbuotKariai() << std::endl;
				std::cin >> verbuotiKariai;
				if (Genininkai.getVerbuotKariai() < verbuotiKariai) {
					std::cout << "Nera tiek kariu!" << std::endl;
				}
				else if (karvedys.getAuksiniai() < verbuotiKariai * 8) {
					std::cout << "Neturite tiek auksiniu!" << std::endl;
				}
				else {
					karvedys.setKariai(verbuotiKariai);
					karvedys.setAuksiniai(-verbuotiKariai, 8);
					std::cout << std::endl;
					std::cout << "Uzverbavote: " << verbuotiKariai << " karius" << std::endl;
					Genininkai.setVerbuotKariai(-verbuotiKariai);
				}
				Sleep(800);
			}
			else if (location == 28) {
				std::cout << "Kiek kariu norite verbuoti? | kario kaina: 8 auksiniai | kariu skaicius: " << Ariogala.getVerbuotKariai() << std::endl;
				std::cin >> verbuotiKariai;
				if (Ariogala.getVerbuotKariai() < verbuotiKariai) {
					std::cout << "Nera tiek kariu!" << std::endl;
				}
				else if (karvedys.getAuksiniai() < verbuotiKariai * 8) {
					std::cout << "Neturite tiek auksiniu!" << std::endl;
				}
				else {
					karvedys.setKariai(verbuotiKariai);
					karvedys.setAuksiniai(-verbuotiKariai, 8);
					std::cout << std::endl;
					std::cout << "Uzverbavote: " << verbuotiKariai << " karius" << std::endl;
					Ariogala.setVerbuotKariai(-verbuotiKariai);
				}
				Sleep(800);
			}
			else if (location == 29) {
				std::cout << "Kiek kariu norite verbuoti? | kario kaina: 8 auksiniai | kariu skaicius: " << Zemzeniai.getVerbuotKariai() << std::endl;
				std::cin >> verbuotiKariai;
				if (Zemzeniai.getVerbuotKariai() < verbuotiKariai) {
					std::cout << "Nera tiek kariu!" << std::endl;
				}
				else if (karvedys.getAuksiniai() < verbuotiKariai * 8) {
					std::cout << "Neturite tiek auksiniu!" << std::endl;
				}
				else {
					karvedys.setKariai(verbuotiKariai);
					karvedys.setAuksiniai(-verbuotiKariai, 8);
					std::cout << std::endl;
					std::cout << "Uzverbavote: " << verbuotiKariai << " karius" << std::endl;
					Zemzeniai.setVerbuotKariai(-verbuotiKariai);
				}
				Sleep(800);
			}
			else if (location == 210) {
				std::cout << "Kiek kariu norite verbuoti? | kario kaina: 8 auksiniai | kariu skaicius: " << Dumbirdai.getVerbuotKariai() << std::endl;
				std::cin >> verbuotiKariai;
				if (Dumbirdai.getVerbuotKariai() < verbuotiKariai) {
					std::cout << "Nera tiek kariu!" << std::endl;
				}
				else if (karvedys.getAuksiniai() < verbuotiKariai * 8) {
					std::cout << "Neturite tiek auksiniu!" << std::endl;
				}
				else {
					karvedys.setKariai(verbuotiKariai);
					karvedys.setAuksiniai(-verbuotiKariai, 8);
					std::cout << std::endl;
					std::cout << "Uzverbavote: " << verbuotiKariai << " karius" << std::endl;
					Dumbirdai.setVerbuotKariai(-verbuotiKariai);
				}
				Sleep(800);
			}
			else if (location == 211) {
				std::cout << "Kiek kariu norite verbuoti? | kario kaina: 8 auksiniai | kariu skaicius: " << Likoniai.getVerbuotKariai() << std::endl;
				std::cin >> verbuotiKariai;
				if (Likoniai.getVerbuotKariai() < verbuotiKariai) {
					std::cout << "Nera tiek kariu!" << std::endl;
				}
				else if (karvedys.getAuksiniai() < verbuotiKariai * 8) {
					std::cout << "Neturite tiek auksiniu!" << std::endl;
				}
				else {
					karvedys.setKariai(verbuotiKariai);
					karvedys.setAuksiniai(-verbuotiKariai, 8);
					std::cout << std::endl;
					std::cout << "Uzverbavote: " << verbuotiKariai << " karius" << std::endl;
					Likoniai.setVerbuotKariai(-verbuotiKariai);
				}
				Sleep(800);
			}
			else if (location == 212) {
				std::cout << "Kiek kariu norite verbuoti? | kario kaina: 8 auksiniai | kariu skaicius: " << Ceckes.getVerbuotKariai() << std::endl;
				std::cin >> verbuotiKariai;
				if (Ceckes.getVerbuotKariai() < verbuotiKariai) {
					std::cout << "Nera tiek kariu!" << std::endl;
				}
				else if (karvedys.getAuksiniai() < verbuotiKariai * 8) {
					std::cout << "Neturite tiek auksiniu!" << std::endl;
				}
				else {
					karvedys.setKariai(verbuotiKariai);
					karvedys.setAuksiniai(-verbuotiKariai, 8);
					std::cout << std::endl;
					std::cout << "Uzverbavote: " << verbuotiKariai << " karius" << std::endl;
					Ceckes.setVerbuotKariai(-verbuotiKariai);
				}
				Sleep(800);
			}
			else if (location == 213) {
				std::cout << "Kiek kariu norite verbuoti? | kario kaina: 8 auksiniai | kariu skaicius: " << Grazdionys.getVerbuotKariai() << std::endl;
				std::cin >> verbuotiKariai;
				if (Grazdionys.getVerbuotKariai() < verbuotiKariai) {
					std::cout << "Nera tiek kariu!" << std::endl;
				}
				else if (karvedys.getAuksiniai() < verbuotiKariai * 8) {
					std::cout << "Neturite tiek auksiniu!" << std::endl;
				}
				else {
					karvedys.setKariai(verbuotiKariai);
					karvedys.setAuksiniai(-verbuotiKariai, 8);
					std::cout << std::endl;
					std::cout << "Uzverbavote: " << verbuotiKariai << " karius" << std::endl;
					Grazdionys.setVerbuotKariai(-verbuotiKariai);
				}
				Sleep(800);
			}
			else if (location == 214) {
				std::cout << "Kiek kariu norite verbuoti? | kario kaina: 8 auksiniai | kariu skaicius: " << Programintai.getVerbuotKariai() << std::endl;
				std::cin >> verbuotiKariai;
				if (Programintai.getVerbuotKariai() < verbuotiKariai) {
					std::cout << "Nera tiek kariu!" << std::endl;
					Sleep(800);
				}
				else if (karvedys.getAuksiniai() < verbuotiKariai * 8) {
					std::cout << "Neturite tiek auksiniu!" << std::endl;
					Sleep(800);
				}
				else {
					karvedys.setKariai(verbuotiKariai);
					karvedys.setAuksiniai(-verbuotiKariai, 8);
					std::cout << std::endl;
					std::cout << "Uzverbavote: " << verbuotiKariai << " karius" << std::endl;
					Programintai.setVerbuotKariai(-verbuotiKariai);
				}
				Sleep(800);
			}
			break;
		case 3: // reiduoti
			if (location == 20) {
				isgyvenePriesuKariai = battle(Truviskes.getKariai(), Truviskes.getGinklai(), 2.5);
				karvedys.setExp(Truviskes.getKariai() - isgyvenePriesuKariai, 3);
				Truviskes.kariaiPoMusio(isgyvenePriesuKariai);
				if (karvedys.getKariai() > 0) {
					std::cout << "Laimejote!" << std::endl;
					karvedys.setAuksiniai(Truviskes.getAuksiniai(), 1);
					Truviskes.auksasPoMusio(0);
					karvedys.setGinklai(Truviskes.getGinklai());
					Truviskes.ginklaiPoMusio(0);
					karvedys.setMaistas(Truviskes.getMaistas());
					Truviskes.maistasPoMusio(0);
				}
				else if (isgyvenePriesuKariai > 0) {
					std::cout << "n00b!" << std::endl;
				}
				Sleep(800);
			}
			else if (location == 21) {
				isgyvenePriesuKariai = battle(Barteliskes.getKariai(), Barteliskes.getGinklai(), 2.5);
				karvedys.setExp(Barteliskes.getKariai() - isgyvenePriesuKariai, 3);
				Barteliskes.kariaiPoMusio(isgyvenePriesuKariai);
				if (karvedys.getKariai() > 0) {
					std::cout << "Laimejote!" << std::endl;
					karvedys.setAuksiniai(Barteliskes.getAuksiniai(), 1);
					Barteliskes.auksasPoMusio(0);
					karvedys.setGinklai(Barteliskes.getGinklai());
					Barteliskes.ginklaiPoMusio(0);
					karvedys.setMaistas(Barteliskes.getMaistas());
					Barteliskes.maistasPoMusio(0);
				}
				else if (isgyvenePriesuKariai > 0) {
					std::cout << "n00b!" << std::endl;
				}
				Sleep(800);
			}
			else if (location == 22) {
				isgyvenePriesuKariai = battle(Teviskes.getKariai(), Teviskes.getGinklai(), 2.5);
				karvedys.setExp(Teviskes.getKariai() - isgyvenePriesuKariai, 3);
				Teviskes.kariaiPoMusio(isgyvenePriesuKariai);
				if (karvedys.getKariai() > 0) {
					std::cout << "Laimejote!" << std::endl;
					karvedys.setAuksiniai(Teviskes.getAuksiniai(), 1);
					Teviskes.auksasPoMusio(0);
					karvedys.setGinklai(Teviskes.getGinklai());
					Teviskes.ginklaiPoMusio(0);
					karvedys.setMaistas(Teviskes.getMaistas());
					Teviskes.maistasPoMusio(0);
				}
				else if (isgyvenePriesuKariai > 0) {
					std::cout << "n00b!" << std::endl;
				}
				Sleep(800);
			}
			else if (location == 23) {
				isgyvenePriesuKariai = battle(Triogalai.getKariai(), Triogalai.getGinklai(), 2.5);
				karvedys.setExp(Triogalai.getKariai() - isgyvenePriesuKariai, 3);
				Triogalai.kariaiPoMusio(isgyvenePriesuKariai);
				if (karvedys.getKariai() > 0) {
					std::cout << "Laimejote!" << std::endl;
					karvedys.setAuksiniai(Triogalai.getAuksiniai(), 1);
					Triogalai.auksasPoMusio(0);
					karvedys.setGinklai(Triogalai.getGinklai());
					Triogalai.ginklaiPoMusio(0);
					karvedys.setMaistas(Triogalai.getMaistas());
					Triogalai.maistasPoMusio(0);
				}
				else if (isgyvenePriesuKariai > 0) {
					std::cout << "n00b!" << std::endl;
				}
				Sleep(800);
			}
			else if (location == 24) {
				isgyvenePriesuKariai = battle(Turipai.getKariai(), Turipai.getGinklai(), 2.5);
				karvedys.setExp(Turipai.getKariai() - isgyvenePriesuKariai, 3);
				Turipai.kariaiPoMusio(isgyvenePriesuKariai);
				if (karvedys.getKariai() > 0) {
					std::cout << "Laimejote!" << std::endl;
					karvedys.setAuksiniai(Turipai.getAuksiniai(), 1);
					Turipai.auksasPoMusio(0);
					karvedys.setGinklai(Turipai.getGinklai());
					Turipai.ginklaiPoMusio(0);
					karvedys.setMaistas(Turipai.getMaistas());
					Turipai.maistasPoMusio(0);
				}
				else if (isgyvenePriesuKariai > 0) {
					std::cout << "n00b!" << std::endl;
				}
				Sleep(800);
			}
			else if (location == 25) {
				isgyvenePriesuKariai = battle(Karoliskes.getKariai(), Karoliskes.getGinklai(), 2.5);
				karvedys.setExp(Karoliskes.getKariai() - isgyvenePriesuKariai, 3);
				Karoliskes.kariaiPoMusio(isgyvenePriesuKariai);
				if (karvedys.getKariai() > 0) {
					std::cout << "Laimejote!" << std::endl;
					karvedys.setAuksiniai(Karoliskes.getAuksiniai(), 1);
					Karoliskes.auksasPoMusio(0);
					karvedys.setGinklai(Karoliskes.getGinklai());
					Karoliskes.ginklaiPoMusio(0);
					karvedys.setMaistas(Karoliskes.getMaistas());
					Karoliskes.maistasPoMusio(0);
				}
				else if (isgyvenePriesuKariai > 0) {
					std::cout << "n00b!" << std::endl;
				}
				Sleep(800);
			}
			else if (location == 26) {
				isgyvenePriesuKariai = battle(Pakalniskes.getKariai(), Pakalniskes.getGinklai(), 2.5);
				karvedys.setExp(Pakalniskes.getKariai() - isgyvenePriesuKariai, 3);
				Pakalniskes.kariaiPoMusio(isgyvenePriesuKariai);
				if (karvedys.getKariai() > 0) {
					std::cout << "Laimejote!" << std::endl;
					karvedys.setAuksiniai(Pakalniskes.getAuksiniai(), 1);
					Pakalniskes.auksasPoMusio(0);
					karvedys.setGinklai(Pakalniskes.getGinklai());
					Pakalniskes.ginklaiPoMusio(0);
					karvedys.setMaistas(Pakalniskes.getMaistas());
					Pakalniskes.maistasPoMusio(0);
				}
				else if (isgyvenePriesuKariai > 0) {
					std::cout << "n00b!" << std::endl;
				}
				Sleep(800);
			}
			else if (location == 27) {
				isgyvenePriesuKariai = battle(Genininkai.getKariai(), Genininkai.getGinklai(), 2.5);
				karvedys.setExp(Genininkai.getKariai() - isgyvenePriesuKariai, 3);
				Genininkai.kariaiPoMusio(isgyvenePriesuKariai);
				if (karvedys.getKariai() > 0) {
					std::cout << "Laimejote!" << std::endl;
					karvedys.setAuksiniai(Genininkai.getAuksiniai(), 1);
					Genininkai.auksasPoMusio(0);
					karvedys.setGinklai(Genininkai.getGinklai());
					Genininkai.ginklaiPoMusio(0);
					karvedys.setMaistas(Genininkai.getMaistas());
					Genininkai.maistasPoMusio(0);
				}
				else if (isgyvenePriesuKariai > 0) {
					std::cout << "n00b!" << std::endl;
				}
				Sleep(800);
			}
			else if (location == 28) {
				isgyvenePriesuKariai = battle(Ariogala.getKariai(), Ariogala.getGinklai(), 2.5);
				karvedys.setExp(Ariogala.getKariai() - isgyvenePriesuKariai, 3);
				Ariogala.kariaiPoMusio(isgyvenePriesuKariai);
				if (karvedys.getKariai() > 0) {
					std::cout << "Laimejote!" << std::endl;
					karvedys.setAuksiniai(Ariogala.getAuksiniai(), 1);
					Ariogala.auksasPoMusio(0);
					karvedys.setGinklai(Ariogala.getGinklai());
					Ariogala.ginklaiPoMusio(0);
					karvedys.setMaistas(Ariogala.getMaistas());
					Ariogala.maistasPoMusio(0);
				}
				else if (isgyvenePriesuKariai > 0) {
					std::cout << "n00b!" << std::endl;
				}
				Sleep(800);
			}
			else if (location == 29) {
				isgyvenePriesuKariai = battle(Zemzeniai.getKariai(), Zemzeniai.getGinklai(), 2.5);
				karvedys.setExp(Zemzeniai.getKariai() - isgyvenePriesuKariai, 3);
				Zemzeniai.kariaiPoMusio(isgyvenePriesuKariai);
				if (karvedys.getKariai() > 0) {
					std::cout << "Laimejote!" << std::endl;
					karvedys.setAuksiniai(Zemzeniai.getAuksiniai(), 1);
					Zemzeniai.auksasPoMusio(0);
					karvedys.setGinklai(Zemzeniai.getGinklai());
					Zemzeniai.ginklaiPoMusio(0);
					karvedys.setMaistas(Zemzeniai.getMaistas());
					Zemzeniai.maistasPoMusio(0);
				}
				else if (isgyvenePriesuKariai > 0) {
					std::cout << "n00b!" << std::endl;
				}
				Sleep(800);
			}
			else if (location == 210) {
				isgyvenePriesuKariai = battle(Dumbirdai.getKariai(), Dumbirdai.getGinklai(), 2.5);
				karvedys.setExp(Dumbirdai.getKariai() - isgyvenePriesuKariai, 3);
				Dumbirdai.kariaiPoMusio(isgyvenePriesuKariai);
				if (karvedys.getKariai() > 0) {
					std::cout << "Laimejote!" << std::endl;
					karvedys.setAuksiniai(Dumbirdai.getAuksiniai(), 1);
					Dumbirdai.auksasPoMusio(0);
					karvedys.setGinklai(Dumbirdai.getGinklai());
					Dumbirdai.ginklaiPoMusio(0);
					karvedys.setMaistas(Dumbirdai.getMaistas());
					Dumbirdai.maistasPoMusio(0);
				}
				else if (isgyvenePriesuKariai > 0) {
					std::cout << "n00b!" << std::endl;
				}
				Sleep(800);
			}
			else if (location == 211) {
				isgyvenePriesuKariai = battle(Likoniai.getKariai(), Likoniai.getGinklai(), 2.5);
				karvedys.setExp(Likoniai.getKariai() - isgyvenePriesuKariai, 3);
				Likoniai.kariaiPoMusio(isgyvenePriesuKariai);
				if (karvedys.getKariai() > 0) {
					std::cout << "Laimejote!" << std::endl;
					karvedys.setAuksiniai(Likoniai.getAuksiniai(), 1);
					Likoniai.auksasPoMusio(0);
					karvedys.setGinklai(Likoniai.getGinklai());
					Likoniai.ginklaiPoMusio(0);
					karvedys.setMaistas(Likoniai.getMaistas());
					Likoniai.maistasPoMusio(0);
				}
				else if (isgyvenePriesuKariai > 0) {
					std::cout << "n00b!" << std::endl;
				}
				Sleep(800);
			}
			else if (location == 212) {
				isgyvenePriesuKariai = battle(Ceckes.getKariai(), Ceckes.getGinklai(), 2.5);
				karvedys.setExp(Ceckes.getKariai() - isgyvenePriesuKariai, 3);
				Ceckes.kariaiPoMusio(isgyvenePriesuKariai);
				if (karvedys.getKariai() > 0) {
					std::cout << "Laimejote!" << std::endl;
					karvedys.setAuksiniai(Ceckes.getAuksiniai(), 1);
					Ceckes.auksasPoMusio(0);
					karvedys.setGinklai(Ceckes.getGinklai());
					Ceckes.ginklaiPoMusio(0);
					karvedys.setMaistas(Ceckes.getMaistas());
					Ceckes.maistasPoMusio(0);
				}
				else if (isgyvenePriesuKariai > 0) {
					std::cout << "n00b!" << std::endl;
				}
				Sleep(800);
			}
			else if (location == 213) {
				isgyvenePriesuKariai = battle(Grazdionys.getKariai(), Grazdionys.getGinklai(), 2.5);
				karvedys.setExp(Grazdionys.getKariai() - isgyvenePriesuKariai, 3);
				Grazdionys.kariaiPoMusio(isgyvenePriesuKariai);
				if (karvedys.getKariai() > 0) {
					std::cout << "Laimejote!" << std::endl;
					karvedys.setAuksiniai(Grazdionys.getAuksiniai(), 1);
					Grazdionys.auksasPoMusio(0);
					karvedys.setGinklai(Grazdionys.getGinklai());
					Grazdionys.ginklaiPoMusio(0);
					karvedys.setMaistas(Grazdionys.getMaistas());
					Grazdionys.maistasPoMusio(0);
				}
				else if (isgyvenePriesuKariai > 0) {
					std::cout << "n00b!" << std::endl;
				}
				Sleep(800);
			}
			else if (location == 214) {
				isgyvenePriesuKariai = battle(Programintai.getKariai(), Programintai.getGinklai(), 2.5);
				karvedys.setExp(Programintai.getKariai() - isgyvenePriesuKariai, 3);
				Programintai.kariaiPoMusio(isgyvenePriesuKariai);
				if (karvedys.getKariai() > 0) {
					std::cout << "Laimejote!" << std::endl;
					karvedys.setAuksiniai(Programintai.getAuksiniai(), 1);
					Programintai.auksasPoMusio(0);
					karvedys.setGinklai(Programintai.getGinklai());
					Programintai.ginklaiPoMusio(0);
					karvedys.setMaistas(Programintai.getMaistas());
					Programintai.maistasPoMusio(0);
				}
				else if (isgyvenePriesuKariai > 0) {
					std::cout << "n00b!" << std::endl;
				}
				Sleep(800);
			}
			break;
		default:
			std::cout << "Tokio pasirinkimo nera" << std::endl;
			Sleep(800);
		}
	}
	system("cls");
}

void game::parduotuveMenu(int location) {

	this->pasirinkParduot = 0; // semaforas
	this->pasirinkPirkt = 0;// semaforas
	this->pasirinkParduotuve = 0;// semaforas
	int pirktasKiekis{ 0 };
	int parduotasKiekis{ 0 };
	while (pasirinkParduotuve != 4) {
		karvedys.printInfo();
		std::cout << std::endl;
		std::cout << "Parduotuve\n";
		std::cout << "-----------------\n";
		std::cout << "1. Pirkti \n";
		std::cout << "2. Parduoti \n";
		std::cout << "0. Iseiti \n";
		std::cout << "-----------------\n";
		std::cout << std::endl << "Pasirinkimas: ";
		std::cin >> pasirinkParduotuve;
		std::cout << std::endl;
		system("cls");
		switch (pasirinkParduotuve) {
		case 0: //quit
			pasirinkParduotuve = 4;
			break;
		case 1: // pirkti
			karvedys.printInfo();
//Truviskes
			if (location == 20) {
				std::cout << "Ka norite pirkti\n";
				std::cout << "-----------------\n";
				std::cout << "1. Maista " << "| kiekis: " << Truviskes.getMaistas() << " | kaina uz vienteta: " << "3 auksiniai" << std::endl;
				std::cout << "2. Ginklus " << "| kiekis: " << Truviskes.getPirktGinklai() << " | kaina uz vieneta: " << "5 auksiniai" << std::endl;
				std::cout << "0. Iseiti \n";
				std::cout << "-----------------\n";
				std::cout << std::endl << "Pasirinkimas: ";
				std::cin >> pasirinkPirkt;
				std::cout << std::endl;
				if (pasirinkPirkt == 1) {
					std::cout << "Kiek maisto norite pirkti?" << std::endl;
					std::cin >> pirktasKiekis;
					if (karvedys.getAuksiniai() < pirktasKiekis * 3) {
						std::cout << "Nepakanka auksiniu!" << std::endl;
					}
					else if (Truviskes.getMaistas() < pirktasKiekis) {
						std::cout << "Nera tiek maisto!" << std::endl;
					}
					else {
						karvedys.setMaistas(pirktasKiekis);
						karvedys.setAuksiniai(-pirktasKiekis, 3);
						std::cout << std::endl;
						std::cout << "Nusipirkote: " << pirktasKiekis << " maisto" << std::endl;
						Truviskes.setMaistas(-pirktasKiekis);
						Truviskes.setAuksas(pirktasKiekis, 3);
					}
					Sleep(800);
					system("cls");
				}
				else if (pasirinkPirkt == 2) {
					std::cout << "Kiek ginklu norite pirkti?" << std::endl;
					std::cin >> pirktasKiekis;
					if (karvedys.getAuksiniai() < pirktasKiekis * 5) {
						std::cout << "Nepakanka auksiniu!" << std::endl;
					}
					else if (Truviskes.getPirktGinklai() < pirktasKiekis) {
						std::cout << "Nera tiek ginklu!" << std::endl;
					}
					else {
						karvedys.setGinklai(pirktasKiekis);
						karvedys.setAuksiniai(-pirktasKiekis, 5);
						std::cout << std::endl;
						std::cout << "Nusipirkote: " << pirktasKiekis << " ginklu" << std::endl;
						Truviskes.setPirktGinklai(-pirktasKiekis);
						Truviskes.setAuksas(pirktasKiekis, 5);
					}
					Sleep(800);
					system("cls");
				}
				else if (pasirinkPirkt == 0) {
					break;
				}
			}
//Barteliskes
			else if (location == 21) {
				std::cout << "Ka norite pirkti\n";
				std::cout << "-----------------\n";
				std::cout << "1. Maista " << "| kiekis: " << Barteliskes.getMaistas() << " | kaina uz vienteta: " << "3 auksiniai" << std::endl;
				std::cout << "2. Ginklus " << "| kiekis: " << Barteliskes.getPirktGinklai() << " | kaina uz vieneta: " << "5 auksiniai" << std::endl;
				std::cout << "0. Iseiti \n";
				std::cout << "-----------------\n";
				std::cout << std::endl << "Pasirinkimas: ";
				std::cin >> pasirinkPirkt;
				std::cout << std::endl;
				if (pasirinkPirkt == 1) {
					std::cout << "Kiek maisto norite pirkti?" << std::endl;
					std::cin >> pirktasKiekis;
					if (karvedys.getAuksiniai() < pirktasKiekis * 3) {
						std::cout << "Nepakanka auksiniu!" << std::endl;
					}
					else if (Barteliskes.getMaistas() < pirktasKiekis) {
						std::cout << "Nera tiek maisto!" << std::endl;
					}
					else {
						karvedys.setMaistas(pirktasKiekis);
						karvedys.setAuksiniai(-pirktasKiekis, 3);
						std::cout << std::endl;
						std::cout << "Nusipirkote: " << pirktasKiekis << " maisto" << std::endl;
						Barteliskes.setMaistas(-pirktasKiekis);
						Barteliskes.setAuksas(pirktasKiekis, 3);
					}
					Sleep(800);
					system("cls");
				}
				else if (pasirinkPirkt == 2) {
					std::cout << "Kiek ginklu norite pirkti?" << std::endl;
					std::cin >> pirktasKiekis;
					if (karvedys.getAuksiniai() < pirktasKiekis * 5) {
						std::cout << "Nepakanka auksiniu!" << std::endl;
					}
					else if (Barteliskes.getPirktGinklai() < pirktasKiekis) {
						std::cout << "Nera tiek ginklu!" << std::endl;
					}
					else {
						karvedys.setGinklai(pirktasKiekis);
						karvedys.setAuksiniai(-pirktasKiekis, 5);
						std::cout << std::endl;
						std::cout << "Nusipirkote: " << pirktasKiekis << " ginklu" << std::endl;
						Barteliskes.setPirktGinklai(-pirktasKiekis);
						Barteliskes.setAuksas(pirktasKiekis, 5);
					}
					Sleep(800);
					system("cls");
				}
				else if (pasirinkPirkt == 0) {
					break;
				}
			}
//Teviskes

			else if (location == 22) {
				std::cout << "Ka norite pirkti\n";
				std::cout << "-----------------\n";
				std::cout << "1. Maista " << "| kiekis: " << Teviskes.getMaistas() << " | kaina uz vienteta: " << "3 auksiniai" << std::endl;
				std::cout << "2. Ginklus " << "| kiekis: " << Teviskes.getPirktGinklai() << " | kaina uz vieneta: " << "5 auksiniai" << std::endl;
				std::cout << "0. Iseiti \n";
				std::cout << "-----------------\n";
				std::cout << std::endl << "Pasirinkimas: ";
				std::cin >> pasirinkPirkt;
				std::cout << std::endl;
				if (pasirinkPirkt == 1) {
					std::cout << "Kiek maisto norite pirkti?" << std::endl;
					std::cin >> pirktasKiekis;
					if (karvedys.getAuksiniai() < pirktasKiekis * 3) {
						std::cout << "Nepakanka auksiniu!" << std::endl;
					}
					else if (Teviskes.getMaistas() < pirktasKiekis) {
						std::cout << "Nera tiek maisto!" << std::endl;
					}
					else {
						karvedys.setMaistas(pirktasKiekis);
						karvedys.setAuksiniai(-pirktasKiekis, 3);
						std::cout << std::endl;
						std::cout << "Nusipirkote: " << pirktasKiekis << " maisto" << std::endl;
						Teviskes.setMaistas(-pirktasKiekis);
						Teviskes.setAuksas(pirktasKiekis, 3);
					}
					Sleep(800);
					system("cls");
				}
				else if (pasirinkPirkt == 2) {
					std::cout << "Kiek ginklu norite pirkti?" << std::endl;
					std::cin >> pirktasKiekis;
					if (karvedys.getAuksiniai() < pirktasKiekis * 5) {
						std::cout << "Nepakanka auksiniu!" << std::endl;
					}
					else if (Teviskes.getPirktGinklai() < pirktasKiekis) {
						std::cout << "Nera tiek ginklu!" << std::endl;
					}
					else {
						karvedys.setGinklai(pirktasKiekis);
						karvedys.setAuksiniai(-pirktasKiekis, 5);
						std::cout << std::endl;
						std::cout << "Nusipirkote: " << pirktasKiekis << " ginklu" << std::endl;
						Teviskes.setPirktGinklai(-pirktasKiekis);
						Teviskes.setAuksas(pirktasKiekis, 5);
					}
					Sleep(800);
					system("cls");
				}
				else if (pasirinkPirkt == 0) {
					break;
				}
			}
//Triogalai
			else if (location == 23) {
				std::cout << "Ka norite pirkti\n";
				std::cout << "-----------------\n";
				std::cout << "1. Maista " << "| kiekis: " << Triogalai.getMaistas() << " | kaina uz vienteta: " << "3 auksiniai" << std::endl;
				std::cout << "2. Ginklus " << "| kiekis: " << Triogalai.getPirktGinklai() << " | kaina uz vieneta: " << "5 auksiniai" << std::endl;
				std::cout << "0. Iseiti \n";
				std::cout << "-----------------\n";
				std::cout << std::endl << "Pasirinkimas: ";
				std::cin >> pasirinkPirkt;
				std::cout << std::endl;
				if (pasirinkPirkt == 1) {
					std::cout << "Kiek maisto norite pirkti?" << std::endl;
					std::cin >> pirktasKiekis;
					if (karvedys.getAuksiniai() < pirktasKiekis * 3) {
						std::cout << "Nepakanka auksiniu!" << std::endl;
					}
					else if (Triogalai.getMaistas() < pirktasKiekis) {
						std::cout << "Nera tiek maisto!" << std::endl;
					}
					else {
						karvedys.setMaistas(pirktasKiekis);
						karvedys.setAuksiniai(-pirktasKiekis, 3);
						std::cout << std::endl;
						std::cout << "Nusipirkote: " << pirktasKiekis << " maisto" << std::endl;
						Triogalai.setMaistas(-pirktasKiekis);
						Triogalai.setAuksas(pirktasKiekis, 3);
					}
					Sleep(800);
					system("cls");
				}
				else if (pasirinkPirkt == 2) {
					std::cout << "Kiek ginklu norite pirkti?" << std::endl;
					std::cin >> pirktasKiekis;
					if (karvedys.getAuksiniai() < pirktasKiekis * 5) {
						std::cout << "Nepakanka auksiniu!" << std::endl;
					}
					else if (Triogalai.getPirktGinklai() < pirktasKiekis) {
						std::cout << "Nera tiek ginklu!" << std::endl;
					}
					else {
						karvedys.setGinklai(pirktasKiekis);
						karvedys.setAuksiniai(-pirktasKiekis, 5);
						std::cout << std::endl;
						std::cout << "Nusipirkote: " << pirktasKiekis << " ginklu" << std::endl;
						Triogalai.setPirktGinklai(-pirktasKiekis);
						Triogalai.setAuksas(pirktasKiekis, 5);
					}
					Sleep(800);
					system("cls");
				}
				else if (pasirinkPirkt == 0) {
					break;
				}
			}
//Turipai

			else if (location == 24) {
				std::cout << "Ka norite pirkti\n";
				std::cout << "-----------------\n";
				std::cout << "1. Maista " << "| kiekis: " << Turipai.getMaistas() << " | kaina uz vienteta: " << "3 auksiniai" << std::endl;
				std::cout << "2. Ginklus " << "| kiekis: " << Turipai.getPirktGinklai() << " | kaina uz vieneta: " << "5 auksiniai" << std::endl;
				std::cout << "0. Iseiti \n";
				std::cout << "-----------------\n";
				std::cout << std::endl << "Pasirinkimas: ";
				std::cin >> pasirinkPirkt;
				std::cout << std::endl;
				if (pasirinkPirkt == 1) {
					std::cout << "Kiek maisto norite pirkti?" << std::endl;
					std::cin >> pirktasKiekis;
					if (karvedys.getAuksiniai() < pirktasKiekis * 3) {
						std::cout << "Nepakanka auksiniu!" << std::endl;
					}
					else if (Turipai.getMaistas() < pirktasKiekis) {
						std::cout << "Nera tiek maisto!" << std::endl;
					}
					else {
						karvedys.setMaistas(pirktasKiekis);
						karvedys.setAuksiniai(-pirktasKiekis, 3);
						std::cout << std::endl;
						std::cout << "Nusipirkote: " << pirktasKiekis << " maisto" << std::endl;
						Turipai.setMaistas(-pirktasKiekis);
						Turipai.setAuksas(pirktasKiekis, 3);
					}
					Sleep(800);
					system("cls");
				}
				else if (pasirinkPirkt == 2) {
					std::cout << "Kiek ginklu norite pirkti?" << std::endl;
					std::cin >> pirktasKiekis;
					if (karvedys.getAuksiniai() < pirktasKiekis * 5) {
						std::cout << "Nepakanka auksiniu!" << std::endl;
					}
					else if (Turipai.getPirktGinklai() < pirktasKiekis) {
						std::cout << "Nera tiek ginklu!" << std::endl;
					}
					else {
						karvedys.setGinklai(pirktasKiekis);
						karvedys.setAuksiniai(-pirktasKiekis, 5);
						std::cout << std::endl;
						std::cout << "Nusipirkote: " << pirktasKiekis << " ginklu" << std::endl;
						Turipai.setPirktGinklai(-pirktasKiekis);
						Turipai.setAuksas(pirktasKiekis, 5);
					}
					Sleep(800);
					system("cls");
				}
				else if (pasirinkPirkt == 0) {
					break;
				}
			}
//Karoliskes

			else if (location == 25) {
				std::cout << "Ka norite pirkti\n";
				std::cout << "-----------------\n";
				std::cout << "1. Maista " << "| kiekis: " << Karoliskes.getMaistas() << " | kaina uz vienteta: " << "3 auksiniai" << std::endl;
				std::cout << "2. Ginklus " << "| kiekis: " << Karoliskes.getPirktGinklai() << " | kaina uz vieneta: " << "5 auksiniai" << std::endl;
				std::cout << "0. Iseiti \n";
				std::cout << "-----------------\n";
				std::cout << std::endl << "Pasirinkimas: ";
				std::cin >> pasirinkPirkt;
				std::cout << std::endl;
				if (pasirinkPirkt == 1) {
					std::cout << "Kiek maisto norite pirkti?" << std::endl;
					std::cin >> pirktasKiekis;
					if (karvedys.getAuksiniai() < pirktasKiekis * 3) {
						std::cout << "Nepakanka auksiniu!" << std::endl;
					}
					else if (Karoliskes.getMaistas() < pirktasKiekis) {
						std::cout << "Nera tiek maisto!" << std::endl;
					}
					else {
						karvedys.setMaistas(pirktasKiekis);
						karvedys.setAuksiniai(-pirktasKiekis, 3);
						std::cout << std::endl;
						std::cout << "Nusipirkote: " << pirktasKiekis << " maisto" << std::endl;
						Karoliskes.setMaistas(-pirktasKiekis);
						Karoliskes.setAuksas(pirktasKiekis, 3);
					}
					Sleep(800);
					system("cls");
				}
				else if (pasirinkPirkt == 2) {
					std::cout << "Kiek ginklu norite pirkti?" << std::endl;
					std::cin >> pirktasKiekis;
					if (karvedys.getAuksiniai() < pirktasKiekis * 5) {
						std::cout << "Nepakanka auksiniu!" << std::endl;
					}
					else if (Karoliskes.getPirktGinklai() < pirktasKiekis) {
						std::cout << "Nera tiek ginklu!" << std::endl;
					}
					else {
						karvedys.setGinklai(pirktasKiekis);
						karvedys.setAuksiniai(-pirktasKiekis, 5);
						std::cout << std::endl;
						std::cout << "Nusipirkote: " << pirktasKiekis << " ginklu" << std::endl;
						Karoliskes.setPirktGinklai(-pirktasKiekis);
						Karoliskes.setAuksas(pirktasKiekis, 5);
					}
					Sleep(800);
					system("cls");
				}
				else if (pasirinkPirkt == 0) {
					break;
				}
			}
//Pakalniskes
			else if (location == 26) {
				std::cout << "Ka norite pirkti\n";
				std::cout << "-----------------\n";
				std::cout << "1. Maista " << "| kiekis: " << Pakalniskes.getMaistas() << " | kaina uz vienteta: " << "3 auksiniai" << std::endl;
				std::cout << "2. Ginklus " << "| kiekis: " << Pakalniskes.getPirktGinklai() << " | kaina uz vieneta: " << "5 auksiniai" << std::endl;
				std::cout << "0. Iseiti \n";
				std::cout << "-----------------\n";
				std::cout << std::endl << "Pasirinkimas: ";
				std::cin >> pasirinkPirkt;
				std::cout << std::endl;
				if (pasirinkPirkt == 1) {
					std::cout << "Kiek maisto norite pirkti?" << std::endl;
					std::cin >> pirktasKiekis;
					if (karvedys.getAuksiniai() < pirktasKiekis * 3) {
						std::cout << "Nepakanka auksiniu!" << std::endl;
					}
					else if (Pakalniskes.getMaistas() < pirktasKiekis) {
						std::cout << "Nera tiek maisto!" << std::endl;
					}
					else {
						karvedys.setMaistas(pirktasKiekis);
						karvedys.setAuksiniai(-pirktasKiekis, 3);
						std::cout << std::endl;
						std::cout << "Nusipirkote: " << pirktasKiekis << " maisto" << std::endl;
						Pakalniskes.setMaistas(-pirktasKiekis);
						Pakalniskes.setAuksas(pirktasKiekis, 3);
					}
					Sleep(800);
					system("cls");
				}
				else if (pasirinkPirkt == 2) {
					std::cout << "Kiek ginklu norite pirkti?" << std::endl;
					std::cin >> pirktasKiekis;
					if (karvedys.getAuksiniai() < pirktasKiekis * 5) {
						std::cout << "Nepakanka auksiniu!" << std::endl;
					}
					else if (Pakalniskes.getPirktGinklai() < pirktasKiekis) {
						std::cout << "Nera tiek ginklu!" << std::endl;
					}
					else {
						karvedys.setGinklai(pirktasKiekis);
						karvedys.setAuksiniai(-pirktasKiekis, 5);
						std::cout << std::endl;
						std::cout << "Nusipirkote: " << pirktasKiekis << " ginklu" << std::endl;
						Pakalniskes.setPirktGinklai(-pirktasKiekis);
						Pakalniskes.setAuksas(pirktasKiekis, 5);
					}
					Sleep(800);
					system("cls");
				}
				else if (pasirinkPirkt == 0) {
					break;
				}
			}
//Genininkai

			else if (location == 27) {
				std::cout << "Ka norite pirkti\n";
				std::cout << "-----------------\n";
				std::cout << "1. Maista " << "| kiekis: " << Genininkai.getMaistas() << " | kaina uz vienteta: " << "3 auksiniai" << std::endl;
				std::cout << "2. Ginklus " << "| kiekis: " << Genininkai.getPirktGinklai() << " | kaina uz vieneta: " << "5 auksiniai" << std::endl;
				std::cout << "0. Iseiti \n";
				std::cout << "-----------------\n";
				std::cout << std::endl << "Pasirinkimas: ";
				std::cin >> pasirinkPirkt;
				std::cout << std::endl;
				if (pasirinkPirkt == 1) {
					std::cout << "Kiek maisto norite pirkti?" << std::endl;
					std::cin >> pirktasKiekis;
					if (karvedys.getAuksiniai() < pirktasKiekis * 3) {
						std::cout << "Nepakanka auksiniu!" << std::endl;
					}
					else if (Genininkai.getMaistas() < pirktasKiekis) {
						std::cout << "Nera tiek maisto!" << std::endl;
					}
					else {
						karvedys.setMaistas(pirktasKiekis);
						karvedys.setAuksiniai(-pirktasKiekis, 3);
						std::cout << std::endl;
						std::cout << "Nusipirkote: " << pirktasKiekis << " maisto" << std::endl;
						Genininkai.setMaistas(-pirktasKiekis);
						Genininkai.setAuksas(pirktasKiekis, 3);
					}
					Sleep(800);
					system("cls");
				}
				else if (pasirinkPirkt == 2) {
					std::cout << "Kiek ginklu norite pirkti?" << std::endl;
					std::cin >> pirktasKiekis;
					if (karvedys.getAuksiniai() < pirktasKiekis * 5) {
						std::cout << "Nepakanka auksiniu!" << std::endl;
					}
					else if (Genininkai.getPirktGinklai() < pirktasKiekis) {
						std::cout << "Nera tiek ginklu!" << std::endl;
					}
					else {
						karvedys.setGinklai(pirktasKiekis);
						karvedys.setAuksiniai(-pirktasKiekis, 5);
						std::cout << std::endl;
						std::cout << "Nusipirkote: " << pirktasKiekis << " ginklu" << std::endl;
						Genininkai.setPirktGinklai(-pirktasKiekis);
						Genininkai.setAuksas(pirktasKiekis, 5);
					}
					Sleep(800);
					system("cls");
				}
				else if (pasirinkPirkt == 0) {
					break;
				}
			}
//Ariogala

			else if (location == 28) {
				std::cout << "Ka norite pirkti\n";
				std::cout << "-----------------\n";
				std::cout << "1. Maista " << "| kiekis: " << Ariogala.getMaistas() << " | kaina uz vienteta: " << "3 auksiniai" << std::endl;
				std::cout << "2. Ginklus " << "| kiekis: " << Ariogala.getPirktGinklai() << " | kaina uz vieneta: " << "5 auksiniai" << std::endl;
				std::cout << "0. Iseiti \n";
				std::cout << "-----------------\n";
				std::cout << std::endl << "Pasirinkimas: ";
				std::cin >> pasirinkPirkt;
				std::cout << std::endl;
				if (pasirinkPirkt == 1) {
					std::cout << "Kiek maisto norite pirkti?" << std::endl;
					std::cin >> pirktasKiekis;
					if (karvedys.getAuksiniai() < pirktasKiekis * 3) {
						std::cout << "Nepakanka auksiniu!" << std::endl;
					}
					else if (Ariogala.getMaistas() < pirktasKiekis) {
						std::cout << "Nera tiek maisto!" << std::endl;
					}
					else {
						karvedys.setMaistas(pirktasKiekis);
						karvedys.setAuksiniai(-pirktasKiekis, 3);
						std::cout << std::endl;
						std::cout << "Nusipirkote: " << pirktasKiekis << " maisto" << std::endl;
						Ariogala.setMaistas(-pirktasKiekis);
						Ariogala.setAuksas(pirktasKiekis, 3);
					}
					Sleep(800);
					system("cls");
				}
				else if (pasirinkPirkt == 2) {
					std::cout << "Kiek ginklu norite pirkti?" << std::endl;
					std::cin >> pirktasKiekis;
					if (karvedys.getAuksiniai() < pirktasKiekis * 5) {
						std::cout << "Nepakanka auksiniu!" << std::endl;
					}
					else if (Ariogala.getPirktGinklai() < pirktasKiekis) {
						std::cout << "Nera tiek ginklu!" << std::endl;
					}
					else {
						karvedys.setGinklai(pirktasKiekis);
						karvedys.setAuksiniai(-pirktasKiekis, 5);
						std::cout << std::endl;
						std::cout << "Nusipirkote: " << pirktasKiekis << " ginklu" << std::endl;
						Ariogala.setPirktGinklai(-pirktasKiekis);
						Ariogala.setAuksas(pirktasKiekis, 5);
					}
					Sleep(800);
					system("cls");
				}
				else if (pasirinkPirkt == 0) {
					break;
				}
			}
//Zemzeniai

			else if (location == 29) {
				std::cout << "Ka norite pirkti\n";
				std::cout << "-----------------\n";
				std::cout << "1. Maista " << "| kiekis: " << Zemzeniai.getMaistas() << " | kaina uz vienteta: " << "3 auksiniai" << std::endl;
				std::cout << "2. Ginklus " << "| kiekis: " << Zemzeniai.getPirktGinklai() << " | kaina uz vieneta: " << "5 auksiniai" << std::endl;
				std::cout << "0. Iseiti \n";
				std::cout << "-----------------\n";
				std::cout << std::endl << "Pasirinkimas: ";
				std::cin >> pasirinkPirkt;
				std::cout << std::endl;
				if (pasirinkPirkt == 1) {
					std::cout << "Kiek maisto norite pirkti?" << std::endl;
					std::cin >> pirktasKiekis;
					if (karvedys.getAuksiniai() < pirktasKiekis * 3) {
						std::cout << "Nepakanka auksiniu!" << std::endl;
					}
					else if (Zemzeniai.getMaistas() < pirktasKiekis) {
						std::cout << "Nera tiek maisto!" << std::endl;
					}
					else {
						karvedys.setMaistas(pirktasKiekis);
						karvedys.setAuksiniai(-pirktasKiekis, 3);
						std::cout << std::endl;
						std::cout << "Nusipirkote: " << pirktasKiekis << " maisto" << std::endl;
						Zemzeniai.setMaistas(-pirktasKiekis);
						Zemzeniai.setAuksas(pirktasKiekis, 3);
					}
					Sleep(800);
					system("cls");
				}
				else if (pasirinkPirkt == 2) {
					std::cout << "Kiek ginklu norite pirkti?" << std::endl;
					std::cin >> pirktasKiekis;
					if (karvedys.getAuksiniai() < pirktasKiekis * 5) {
						std::cout << "Nepakanka auksiniu!" << std::endl;
					}
					else if (Zemzeniai.getPirktGinklai() < pirktasKiekis) {
						std::cout << "Nera tiek ginklu!" << std::endl;
					}
					else {
						karvedys.setGinklai(pirktasKiekis);
						karvedys.setAuksiniai(-pirktasKiekis, 5);
						std::cout << std::endl;
						std::cout << "Nusipirkote: " << pirktasKiekis << " ginklu" << std::endl;
						Zemzeniai.setPirktGinklai(-pirktasKiekis);
						Zemzeniai.setAuksas(pirktasKiekis, 5);
					}
					Sleep(800);
					system("cls");
				}
				else if (pasirinkPirkt == 0) {
					break;
				}
			}
//Dumbirdai

			else if (location == 210) {
				std::cout << "Ka norite pirkti\n";
				std::cout << "-----------------\n";
				std::cout << "1. Maista " << "| kiekis: " << Dumbirdai.getMaistas() << " | kaina uz vienteta: " << "3 auksiniai" << std::endl;
				std::cout << "2. Ginklus " << "| kiekis: " << Dumbirdai.getPirktGinklai() << " | kaina uz vieneta: " << "5 auksiniai" << std::endl;
				std::cout << "0. Iseiti \n";
				std::cout << "-----------------\n";
				std::cout << std::endl << "Pasirinkimas: ";
				std::cin >> pasirinkPirkt;
				std::cout << std::endl;
				if (pasirinkPirkt == 1) {
					std::cout << "Kiek maisto norite pirkti?" << std::endl;
					std::cin >> pirktasKiekis;
					if (karvedys.getAuksiniai() < pirktasKiekis * 3) {
						std::cout << "Nepakanka auksiniu!" << std::endl;
					}
					else if (Dumbirdai.getMaistas() < pirktasKiekis) {
						std::cout << "Nera tiek maisto!" << std::endl;
					}
					else {
						karvedys.setMaistas(pirktasKiekis);
						karvedys.setAuksiniai(-pirktasKiekis, 3);
						std::cout << std::endl;
						std::cout << "Nusipirkote: " << pirktasKiekis << " maisto" << std::endl;
						Dumbirdai.setMaistas(-pirktasKiekis);
						Dumbirdai.setAuksas(pirktasKiekis, 3);
					}
					Sleep(800);
					system("cls");
				}
				else if (pasirinkPirkt == 2) {
					std::cout << "Kiek ginklu norite pirkti?" << std::endl;
					std::cin >> pirktasKiekis;
					if (karvedys.getAuksiniai() < pirktasKiekis * 5) {
						std::cout << "Nepakanka auksiniu!" << std::endl;
					}
					else if (Dumbirdai.getPirktGinklai() < pirktasKiekis) {
						std::cout << "Nera tiek ginklu!" << std::endl;
					}
					else {
						karvedys.setGinklai(pirktasKiekis);
						karvedys.setAuksiniai(-pirktasKiekis, 5);
						std::cout << std::endl;
						std::cout << "Nusipirkote: " << pirktasKiekis << " ginklu" << std::endl;
						Dumbirdai.setPirktGinklai(-pirktasKiekis);
						Dumbirdai.setAuksas(pirktasKiekis, 5);
					}
					Sleep(800);
					system("cls");
				}
				else if (pasirinkPirkt == 0) {
					break;
				}
			}
//Likoniai

			else if (location == 211) {
				std::cout << "Ka norite pirkti\n";
				std::cout << "-----------------\n";
				std::cout << "1. Maista " << "| kiekis: " << Likoniai.getMaistas() << " | kaina uz vienteta: " << "3 auksiniai" << std::endl;
				std::cout << "2. Ginklus " << "| kiekis: " << Likoniai.getPirktGinklai() << " | kaina uz vieneta: " << "5 auksiniai" << std::endl;
				std::cout << "0. Iseiti \n";
				std::cout << "-----------------\n";
				std::cout << std::endl << "Pasirinkimas: ";
				std::cin >> pasirinkPirkt;
				std::cout << std::endl;
				if (pasirinkPirkt == 1) {
					std::cout << "Kiek maisto norite pirkti?" << std::endl;
					std::cin >> pirktasKiekis;
					if (karvedys.getAuksiniai() < pirktasKiekis * 3) {
						std::cout << "Nepakanka auksiniu!" << std::endl;
					}
					else if (Likoniai.getMaistas() < pirktasKiekis) {
						std::cout << "Nera tiek maisto!" << std::endl;
					}
					else {
						karvedys.setMaistas(pirktasKiekis);
						karvedys.setAuksiniai(-pirktasKiekis, 3);
						std::cout << std::endl;
						std::cout << "Nusipirkote: " << pirktasKiekis << " maisto" << std::endl;
						Likoniai.setMaistas(-pirktasKiekis);
						Likoniai.setAuksas(pirktasKiekis, 3);
					}
					Sleep(800);
					system("cls");
				}
				else if (pasirinkPirkt == 2) {
					std::cout << "Kiek ginklu norite pirkti?" << std::endl;
					std::cin >> pirktasKiekis;
					if (karvedys.getAuksiniai() < pirktasKiekis * 5) {
						std::cout << "Nepakanka auksiniu!" << std::endl;
					}
					else if (Likoniai.getPirktGinklai() < pirktasKiekis) {
						std::cout << "Nera tiek ginklu!" << std::endl;
					}
					else {
						karvedys.setGinklai(pirktasKiekis);
						karvedys.setAuksiniai(-pirktasKiekis, 5);
						std::cout << std::endl;
						std::cout << "Nusipirkote: " << pirktasKiekis << " ginklu" << std::endl;
						Likoniai.setPirktGinklai(-pirktasKiekis);
						Likoniai.setAuksas(pirktasKiekis, 5);
					}
					Sleep(800);
					system("cls");
				}
				else if (pasirinkPirkt == 0) {
					break;
				}
			}
//Ceckes

			else if (location == 212) {
				std::cout << "Ka norite pirkti\n";
				std::cout << "-----------------\n";
				std::cout << "1. Maista " << "| kiekis: " << Ceckes.getMaistas() << " | kaina uz vienteta: " << "3 auksiniai" << std::endl;
				std::cout << "2. Ginklus " << "| kiekis: " << Ceckes.getPirktGinklai() << " | kaina uz vieneta: " << "5 auksiniai" << std::endl;
				std::cout << "0. Iseiti \n";
				std::cout << "-----------------\n";
				std::cout << std::endl << "Pasirinkimas: ";
				std::cin >> pasirinkPirkt;
				std::cout << std::endl;
				if (pasirinkPirkt == 1) {
					std::cout << "Kiek maisto norite pirkti?" << std::endl;
					std::cin >> pirktasKiekis;
					if (karvedys.getAuksiniai() < pirktasKiekis * 3) {
						std::cout << "Nepakanka auksiniu!" << std::endl;
					}
					else if (Ceckes.getMaistas() < pirktasKiekis) {
						std::cout << "Nera tiek maisto!" << std::endl;
					}
					else {
						karvedys.setMaistas(pirktasKiekis);
						karvedys.setAuksiniai(-pirktasKiekis, 3);
						std::cout << std::endl;
						std::cout << "Nusipirkote: " << pirktasKiekis << " maisto" << std::endl;
						Ceckes.setMaistas(-pirktasKiekis);
						Ceckes.setAuksas(pirktasKiekis, 3);
					}
					Sleep(800);
					system("cls");
				}
				else if (pasirinkPirkt == 2) {
					std::cout << "Kiek ginklu norite pirkti?" << std::endl;
					std::cin >> pirktasKiekis;
					if (karvedys.getAuksiniai() < pirktasKiekis * 5) {
						std::cout << "Nepakanka auksiniu!" << std::endl;
					}
					else if (Ceckes.getPirktGinklai() < pirktasKiekis) {
						std::cout << "Nera tiek ginklu!" << std::endl;
					}
					else {
						karvedys.setGinklai(pirktasKiekis);
						karvedys.setAuksiniai(-pirktasKiekis, 5);
						std::cout << std::endl;
						std::cout << "Nusipirkote: " << pirktasKiekis << " ginklu" << std::endl;
						Ceckes.setPirktGinklai(-pirktasKiekis);
						Ceckes.setAuksas(pirktasKiekis, 5);
					}
					Sleep(800);
					system("cls");
				}
				else if (pasirinkPirkt == 0) {
					break;
				}
			}
//Grazdionys
			else if (location == 213) {
				std::cout << "Ka norite pirkti\n";
				std::cout << "-----------------\n";
				std::cout << "1. Maista " << "| kiekis: " << Grazdionys.getMaistas() << " | kaina uz vienteta: " << "3 auksiniai" << std::endl;
				std::cout << "2. Ginklus " << "| kiekis: " << Grazdionys.getPirktGinklai() << " | kaina uz vieneta: " << "5 auksiniai" << std::endl;
				std::cout << "0. Iseiti \n";
				std::cout << "-----------------\n";
				std::cout << std::endl << "Pasirinkimas: ";
				std::cin >> pasirinkPirkt;
				std::cout << std::endl;
				if (pasirinkPirkt == 1) {
					std::cout << "Kiek maisto norite pirkti?" << std::endl;
					std::cin >> pirktasKiekis;
					if (karvedys.getAuksiniai() < pirktasKiekis * 3) {
						std::cout << "Nepakanka auksiniu!" << std::endl;
					}
					else if (Grazdionys.getMaistas() < pirktasKiekis) {
						std::cout << "Nera tiek maisto!" << std::endl;
					}
					else {
						karvedys.setMaistas(pirktasKiekis);
						karvedys.setAuksiniai(-pirktasKiekis, 3);
						std::cout << std::endl;
						std::cout << "Nusipirkote: " << pirktasKiekis << " maisto" << std::endl;
						Grazdionys.setMaistas(-pirktasKiekis);
						Grazdionys.setAuksas(pirktasKiekis, 3);
					}
					Sleep(800);
					system("cls");
				}
				else if (pasirinkPirkt == 2) {
					std::cout << "Kiek ginklu norite pirkti?" << std::endl;
					std::cin >> pirktasKiekis;
					if (karvedys.getAuksiniai() < pirktasKiekis * 5) {
						std::cout << "Nepakanka auksiniu!" << std::endl;
					}
					else if (Grazdionys.getPirktGinklai() < pirktasKiekis) {
						std::cout << "Nera tiek ginklu!" << std::endl;
					}
					else {
						karvedys.setGinklai(pirktasKiekis);
						karvedys.setAuksiniai(-pirktasKiekis, 5);
						std::cout << std::endl;
						std::cout << "Nusipirkote: " << pirktasKiekis << " ginklu" << std::endl;
						Grazdionys.setPirktGinklai(-pirktasKiekis);
						Grazdionys.setAuksas(pirktasKiekis, 5);
					}
					Sleep(800);
					system("cls");
				}
				else if (pasirinkPirkt == 0) {
					break;
				}
			}
//Programintai

			else if (location == 214) {
				std::cout << "Ka norite pirkti\n";
				std::cout << "-----------------\n";
				std::cout << "1. Maista " << "| kiekis: " << Programintai.getMaistas() << " | kaina uz vienteta: " << "3 auksiniai" << std::endl;
				std::cout << "2. Ginklus " << "| kiekis: " << Programintai.getPirktGinklai() << " | kaina uz vieneta: " << "5 auksiniai" << std::endl;
				std::cout << "0. Iseiti \n";
				std::cout << "-----------------\n";
				std::cout << std::endl << "Pasirinkimas: ";
				std::cin >> pasirinkPirkt;
				std::cout << std::endl;
				if (pasirinkPirkt == 1) {
					std::cout << "Kiek maisto norite pirkti?" << std::endl;
					std::cin >> pirktasKiekis;
					if (karvedys.getAuksiniai() < pirktasKiekis * 3) {
						std::cout << "Nepakanka auksiniu!" << std::endl;
					}
					else if (Programintai.getMaistas() < pirktasKiekis) {
						std::cout << "Nera tiek maisto!" << std::endl;
					}
					else {
						karvedys.setMaistas(pirktasKiekis);
						karvedys.setAuksiniai(-pirktasKiekis, 3);
						std::cout << std::endl;
						std::cout << "Nusipirkote: " << pirktasKiekis << " maisto" << std::endl;
						Programintai.setMaistas(-pirktasKiekis);
						Programintai.setAuksas(pirktasKiekis, 3);
					}
					Sleep(800);
					system("cls");
				}
				else if (pasirinkPirkt == 2) {
					std::cout << "Kiek ginklu norite pirkti?" << std::endl;
					std::cin >> pirktasKiekis;
					if (karvedys.getAuksiniai() < pirktasKiekis * 5) {
						std::cout << "Nepakanka auksiniu!" << std::endl;
					}
					else if (Programintai.getPirktGinklai() < pirktasKiekis) {
						std::cout << "Nera tiek ginklu!" << std::endl;
					}
					else {
						karvedys.setGinklai(pirktasKiekis);
						karvedys.setAuksiniai(-pirktasKiekis, 5);
						std::cout << std::endl;
						std::cout << "Nusipirkote: " << pirktasKiekis << " ginklu" << std::endl;
						Programintai.setPirktGinklai(-pirktasKiekis);
						Programintai.setAuksas(pirktasKiekis, 5);
					}
					Sleep(800);
					system("cls");
				}
				else if (pasirinkPirkt == 0) {
					break;
				}
			}
//Frankai

			else if (location == 30) {
				std::cout << "Ka norite pirkti\n";
				std::cout << "-----------------\n";
				std::cout << "1. Maista " << "| kiekis: " << Frankite.getMaistas() << " | kaina uz vienteta: " << "5 auksiniai" << std::endl;
				std::cout << "2. Ginklus " << "| kiekis: " << Frankite.getPirktGinklai() << " | kaina uz vieneta: " << "7 auksiniai" << std::endl;
				std::cout << "0. Iseiti \n";
				std::cout << "-----------------\n";
				std::cout << std::endl << "Pasirinkimas: ";
				std::cin >> pasirinkPirkt;
				std::cout << std::endl;
				if (pasirinkPirkt == 1) {
					std::cout << "Kiek maisto norite pirkti?" << std::endl;
					std::cin >> pirktasKiekis;
					if (karvedys.getAuksiniai() < pirktasKiekis * 5) {
						std::cout << "Nepakanka auksiniu!" << std::endl;
					}
					else if (Frankite.getMaistas() < pirktasKiekis) {
						std::cout << "Nera tiek maisto!" << std::endl;
					}
					else {
						karvedys.setMaistas(pirktasKiekis);
						karvedys.setAuksiniai(-pirktasKiekis, 5);
						std::cout << std::endl;
						std::cout << "Nusipirkote: " << pirktasKiekis << " maisto" << std::endl;
						Frankite.setMaistas(-pirktasKiekis);
						Frankite.setAuksas(pirktasKiekis, 5);;
					}
					Sleep(800);
					system("cls");
				}
				else if (pasirinkPirkt == 2) {
					std::cout << "Kiek ginklu norite pirkti?" << std::endl;
					std::cin >> pirktasKiekis;
					if (karvedys.getAuksiniai() < pirktasKiekis * 7) {
						std::cout << "Nepakanka auksiniu!" << std::endl;
					}
					else if (Frankite.getPirktGinklai() < pirktasKiekis) {
						std::cout << "Nera tiek ginklu!" << std::endl;
					}
					else {
						karvedys.setGinklai(pirktasKiekis);
						karvedys.setAuksiniai(-pirktasKiekis, 7);
						std::cout << std::endl;
						std::cout << "Nusipirkote: " << pirktasKiekis << " ginklu" << std::endl;
						Frankite.setPirktGinklai(-pirktasKiekis);
						Frankite.setAuksas(pirktasKiekis, 7);
					}
					Sleep(800);
					system("cls");
				}
				else if (pasirinkPirkt == 0) {
					break;
				}
			}
//Germanite

			else if (location == 31) {
				std::cout << "Ka norite pirkti\n";
				std::cout << "-----------------\n";
				std::cout << "1. Maista " << "| kiekis: " << Germanite.getMaistas() << " | kaina uz vienteta: " << "5 auksiniai" << std::endl;
				std::cout << "2. Ginklus " << "| kiekis: " << Germanite.getPirktGinklai() << " | kaina uz vieneta: " << "7 auksiniai" << std::endl;
				std::cout << "0. Iseiti \n";
				std::cout << "-----------------\n";
				std::cout << std::endl << "Pasirinkimas: ";
				std::cin >> pasirinkPirkt;
				std::cout << std::endl;
				if (pasirinkPirkt == 1) {
					std::cout << "Kiek maisto norite pirkti?" << std::endl;
					std::cin >> pirktasKiekis;
					if (karvedys.getAuksiniai() < pirktasKiekis * 5) {
						std::cout << "Nepakanka auksiniu!" << std::endl;
					}
					else if (Germanite.getMaistas() < pirktasKiekis) {
						std::cout << "Nera tiek maisto!" << std::endl;
					}
					else {
						karvedys.setMaistas(pirktasKiekis);
						karvedys.setAuksiniai(-pirktasKiekis, 5);
						std::cout << std::endl;
						std::cout << "Nusipirkote: " << pirktasKiekis << " maisto" << std::endl;
						Germanite.setMaistas(-pirktasKiekis);
						Germanite.setAuksas(pirktasKiekis, 5);
					}
					Sleep(800);
					system("cls");
				}
				else if (pasirinkPirkt == 2) {
					std::cout << "Kiek ginklu norite pirkti?" << std::endl;
					std::cin >> pirktasKiekis;
					if (karvedys.getAuksiniai() < pirktasKiekis * 7) {
						std::cout << "Nepakanka auksiniu!" << std::endl;
					}
					else if (Germanite.getPirktGinklai() < pirktasKiekis) {
						std::cout << "Nera tiek ginklu!" << std::endl;
					}
					else {
						karvedys.setGinklai(pirktasKiekis);
						karvedys.setAuksiniai(-pirktasKiekis, 7);
						std::cout << std::endl;
						std::cout << "Nusipirkote: " << pirktasKiekis << " ginklu" << std::endl;
						Germanite.setPirktGinklai(-pirktasKiekis);
						Germanite.setAuksas(pirktasKiekis, 7);
					}
					Sleep(800);
					system("cls");
				}
				else if (pasirinkPirkt == 0) {
					break;
				}
			}
//Svedite

			else if (location == 32) {
				std::cout << "Ka norite pirkti\n";
				std::cout << "-----------------\n";
				std::cout << "1. Maista " << "| kiekis: " << Svedite.getMaistas() << " | kaina uz vienteta: " << "5 auksiniai" << std::endl;
				std::cout << "2. Ginklus " << "| kiekis: " << Svedite.getPirktGinklai() << " | kaina uz vieneta: " << "7 auksiniai" << std::endl;
				std::cout << "0. Iseiti \n";
				std::cout << "-----------------\n";
				std::cout << std::endl << "Pasirinkimas: ";
				std::cin >> pasirinkPirkt;
				std::cout << std::endl;
				if (pasirinkPirkt == 1) {
					std::cout << "Kiek maisto norite pirkti?" << std::endl;
					std::cin >> pirktasKiekis;
					if (karvedys.getAuksiniai() < pirktasKiekis * 5) {
						std::cout << "Nepakanka auksiniu!" << std::endl;
					}
					else if (Svedite.getMaistas() < pirktasKiekis) {
						std::cout << "Nera tiek maisto!" << std::endl;
					}
					else {
						karvedys.setMaistas(pirktasKiekis);
						karvedys.setAuksiniai(-pirktasKiekis, 5);
						std::cout << std::endl;
						std::cout << "Nusipirkote: " << pirktasKiekis << " maisto" << std::endl;
						Svedite.setMaistas(-pirktasKiekis);
						Svedite.setAuksas(pirktasKiekis, 5);
					}
					Sleep(800);
					system("cls");
				}
				else if (pasirinkPirkt == 2) {
					std::cout << "Kiek ginklu norite pirkti?" << std::endl;
					std::cin >> pirktasKiekis;
					if (karvedys.getAuksiniai() < pirktasKiekis * 7) {
						std::cout << "Nepakanka auksiniu!" << std::endl;
					}
					else if (Svedite.getPirktGinklai() < pirktasKiekis) {
						std::cout << "Nera tiek ginklu!" << std::endl;
					}
					else {
						karvedys.setGinklai(pirktasKiekis);
						karvedys.setAuksiniai(-pirktasKiekis, 7);
						std::cout << std::endl;
						std::cout << "Nusipirkote: " << pirktasKiekis << " ginklu" << std::endl;
						Svedite.setPirktGinklai(-pirktasKiekis);
						Svedite.setAuksas(pirktasKiekis, 7);
					}
					Sleep(800);
					system("cls");
				}
				else if (pasirinkPirkt == 0) {
					break;
				}
			}
//Italiano

			else if (location == 33) {
				std::cout << "Ka norite pirkti\n";
				std::cout << "-----------------\n";
				std::cout << "1. Maista " << "| kiekis: " << Italiano.getMaistas() << " | kaina uz vienteta: " << "5 auksiniai" << std::endl;
				std::cout << "2. Ginklus " << "| kiekis: " << Italiano.getPirktGinklai() << " | kaina uz vieneta: " << "7 auksiniai" << std::endl;
				std::cout << "0. Iseiti \n";
				std::cout << "-----------------\n";
				std::cout << std::endl << "Pasirinkimas: ";
				std::cin >> pasirinkPirkt;
				std::cout << std::endl;
				if (pasirinkPirkt == 1) {
					std::cout << "Kiek maisto norite pirkti?" << std::endl;
					std::cin >> pirktasKiekis;
					if (karvedys.getAuksiniai() < pirktasKiekis * 5) {
						std::cout << "Nepakanka auksiniu!" << std::endl;
					}
					else if (Italiano.getMaistas() < pirktasKiekis) {
						std::cout << "Nera tiek maisto!" << std::endl;
					}
					else {
						karvedys.setMaistas(pirktasKiekis);
						karvedys.setAuksiniai(-pirktasKiekis, 5);
						std::cout << std::endl;
						std::cout << "Nusipirkote: " << pirktasKiekis << " maisto" << std::endl;
						Italiano.setMaistas(-pirktasKiekis);
						Italiano.setAuksas(pirktasKiekis, 5);
					}
					Sleep(800);
					system("cls");
				}
				else if (pasirinkPirkt == 2) {
					std::cout << "Kiek ginklu norite pirkti?" << std::endl;
					std::cin >> pirktasKiekis;
					if (karvedys.getAuksiniai() < pirktasKiekis * 7) {
						std::cout << "Nepakanka auksiniu!" << std::endl;
					}
					else if (Italiano.getPirktGinklai() < pirktasKiekis) {
						std::cout << "Nera tiek ginklu!" << std::endl;
					}
					else {
						karvedys.setGinklai(pirktasKiekis);
						karvedys.setAuksiniai(-pirktasKiekis, 7);
						std::cout << std::endl;
						std::cout << "Nusipirkote: " << pirktasKiekis << " ginklu" << std::endl;
						Italiano.setPirktGinklai(-pirktasKiekis);
						Italiano.setAuksas(pirktasKiekis, 7);
					}
					Sleep(800);
					system("cls");
				}
				else if (pasirinkPirkt == 0) {
					break;
				}
			}
//Galiano

			else if (location == 34) {
				std::cout << "Ka norite pirkti\n";
				std::cout << "-----------------\n";
				std::cout << "1. Maista " << "| kiekis: " << Galiano.getMaistas() << " | kaina uz vienteta: " << "5 auksiniai" << std::endl;
				std::cout << "2. Ginklus " << "| kiekis: " << Galiano.getPirktGinklai() << " | kaina uz vieneta: " << "7 auksiniai" << std::endl;
				std::cout << "0. Iseiti \n";
				std::cout << "-----------------\n";
				std::cout << std::endl << "Pasirinkimas: ";
				std::cin >> pasirinkPirkt;
				std::cout << std::endl;
				if (pasirinkPirkt == 1) {
					std::cout << "Kiek maisto norite pirkti?" << std::endl;
					std::cin >> pirktasKiekis;
					if (karvedys.getAuksiniai() < pirktasKiekis * 5) {
						std::cout << "Nepakanka auksiniu!" << std::endl;
					}
					else if (Galiano.getMaistas() < pirktasKiekis) {
						std::cout << "Nera tiek maisto!" << std::endl;
					}
					else {
						karvedys.setMaistas(pirktasKiekis);
						karvedys.setAuksiniai(-pirktasKiekis, 5);
						std::cout << std::endl;
						std::cout << "Nusipirkote: " << pirktasKiekis << " maisto" << std::endl;
						Galiano.setMaistas(-pirktasKiekis);
						Galiano.setAuksas(pirktasKiekis, 5);
					}
					Sleep(800);
					system("cls");
				}
				else if (pasirinkPirkt == 2) {
					std::cout << "Kiek ginklu norite pirkti?" << std::endl;
					std::cin >> pirktasKiekis;
					if (karvedys.getAuksiniai() < pirktasKiekis * 7) {
						std::cout << "Nepakanka auksiniu!" << std::endl;
					}
					else if (Galiano.getPirktGinklai() < pirktasKiekis) {
						std::cout << "Nera tiek ginklu!" << std::endl;
					}
					else {
						karvedys.setGinklai(pirktasKiekis);
						karvedys.setAuksiniai(-pirktasKiekis, 7);
						std::cout << std::endl;
						std::cout << "Nusipirkote: " << pirktasKiekis << " ginklu" << std::endl;
						Galiano.setPirktGinklai(-pirktasKiekis);
						Galiano.setAuksas(pirktasKiekis, 7);
					}
					Sleep(800);
					system("cls");
				}
				else if (pasirinkPirkt == 0) {
					break;
				}
			}
//Vikingaites

			else if (location == 35) {
				std::cout << "Ka norite pirkti\n";
				std::cout << "-----------------\n";
				std::cout << "1. Maista " << "| kiekis: " << Vikingaites.getMaistas() << " | kaina uz vienteta: " << "5 auksiniai" << std::endl;
				std::cout << "2. Ginklus " << "| kiekis: " << Vikingaites.getPirktGinklai() << " | kaina uz vieneta: " << "7 auksiniai" << std::endl;
				std::cout << "0. Iseiti \n";
				std::cout << "-----------------\n";
				std::cout << std::endl << "Pasirinkimas: ";
				std::cin >> pasirinkPirkt;
				std::cout << std::endl;
				if (pasirinkPirkt == 1) {
					std::cout << "Kiek maisto norite pirkti?" << std::endl;
					std::cin >> pirktasKiekis;
					if (karvedys.getAuksiniai() < pirktasKiekis * 5) {
						std::cout << "Nepakanka auksiniu!" << std::endl;
					}
					else if (Vikingaites.getMaistas() < pirktasKiekis) {
						std::cout << "Nera tiek maisto!" << std::endl;
					}
					else {
						karvedys.setMaistas(pirktasKiekis);
						karvedys.setAuksiniai(-pirktasKiekis, 5);
						std::cout << std::endl;
						std::cout << "Nusipirkote: " << pirktasKiekis << " maisto" << std::endl;
						Vikingaites.setMaistas(-pirktasKiekis);
						Vikingaites.setAuksas(pirktasKiekis, 5);
					}
					Sleep(800);
					system("cls");
				}
				else if (pasirinkPirkt == 2) {
					std::cout << "Kiek ginklu norite pirkti?" << std::endl;
					std::cin >> pirktasKiekis;
					if (karvedys.getAuksiniai() < pirktasKiekis * 7) {
						std::cout << "Nepakanka auksiniu!" << std::endl;
					}
					else if (Vikingaites.getPirktGinklai() < pirktasKiekis) {
						std::cout << "Nera tiek ginklu!" << std::endl;
					}
					else {
						karvedys.setGinklai(pirktasKiekis);
						karvedys.setAuksiniai(-pirktasKiekis, 7);
						std::cout << std::endl;
						std::cout << "Nusipirkote: " << pirktasKiekis << " ginklu" << std::endl;
						Vikingaites.setPirktGinklai(-pirktasKiekis);
						Vikingaites.setAuksas(pirktasKiekis, 7);
					}
					Sleep(800);
					system("cls");
				}
				else if (pasirinkPirkt == 0) {
					break;
				}
			}
//Lituanica

			else if (location == 36) {
				std::cout << "Ka norite pirkti\n";
				std::cout << "-----------------\n";
				std::cout << "1. Maista " << "| kiekis: " << Lituanica.getMaistas() << " | kaina uz vienteta: " << "5 auksiniai" << std::endl;
				std::cout << "2. Ginklus " << "| kiekis: " << Lituanica.getPirktGinklai() << " | kaina uz vieneta: " << "7 auksiniai" << std::endl;
				std::cout << "0. Iseiti \n";
				std::cout << "-----------------\n";
				std::cout << std::endl << "Pasirinkimas: ";
				std::cin >> pasirinkPirkt;
				std::cout << std::endl;
				if (pasirinkPirkt == 1) {
					std::cout << "Kiek maisto norite pirkti?" << std::endl;
					std::cin >> pirktasKiekis;
					if (karvedys.getAuksiniai() < pirktasKiekis * 5) {
						std::cout << "Nepakanka auksiniu!" << std::endl;
					}
					else if (Lituanica.getMaistas() < pirktasKiekis) {
						std::cout << "Nera tiek maisto!" << std::endl;
					}
					else {
						karvedys.setMaistas(pirktasKiekis);
						karvedys.setAuksiniai(-pirktasKiekis, 5);
						std::cout << std::endl;
						std::cout << "Nusipirkote: " << pirktasKiekis << " maisto" << std::endl;
						Lituanica.setMaistas(-pirktasKiekis);
						Lituanica.setAuksas(pirktasKiekis, 5);
					}
					Sleep(800);
					system("cls");
				}
				else if (pasirinkPirkt == 2) {
					std::cout << "Kiek ginklu norite pirkti?" << std::endl;
					std::cin >> pirktasKiekis;
					if (karvedys.getAuksiniai() < pirktasKiekis * 7) {
						std::cout << "Nepakanka auksiniu!" << std::endl;
					}
					else if (Lituanica.getPirktGinklai() < pirktasKiekis) {
						std::cout << "Nera tiek ginklu!" << std::endl;
					}
					else {
						karvedys.setGinklai(pirktasKiekis);
						karvedys.setAuksiniai(-pirktasKiekis, 7);
						std::cout << std::endl;
						std::cout << "Nusipirkote: " << pirktasKiekis << " ginklu" << std::endl;
						Lituanica.setPirktGinklai(-pirktasKiekis);
						Lituanica.setAuksas(pirktasKiekis, 7);
					}
					Sleep(800);
					system("cls");
				}
				else if (pasirinkPirkt == 0) {
					break;
				}
			}
//Zemaiteskai

			else if (location == 37) {
				std::cout << "Ka norite pirkti\n";
				std::cout << "-----------------\n";
				std::cout << "1. Maista " << "| kiekis: " << Zemaiteskai.getMaistas() << " | kaina uz vienteta: " << "5 auksiniai" << std::endl;
				std::cout << "2. Ginklus " << "| kiekis: " << Zemaiteskai.getPirktGinklai() << " | kaina uz vieneta: " << "7 auksiniai" << std::endl;
				std::cout << "0. Iseiti \n";
				std::cout << "-----------------\n";
				std::cout << std::endl << "Pasirinkimas: ";
				std::cin >> pasirinkPirkt;
				std::cout << std::endl;
				if (pasirinkPirkt == 1) {
					std::cout << "Kiek maisto norite pirkti?" << std::endl;
					std::cin >> pirktasKiekis;
					if (karvedys.getAuksiniai() < pirktasKiekis * 5) {
						std::cout << "Nepakanka auksiniu!" << std::endl;
					}
					else if (Zemaiteskai.getMaistas() < pirktasKiekis) {
						std::cout << "Nera tiek maisto!" << std::endl;
					}
					else {
						karvedys.setMaistas(pirktasKiekis);
						karvedys.setAuksiniai(-pirktasKiekis, 5);
						std::cout << std::endl;
						std::cout << "Nusipirkote: " << pirktasKiekis << " maisto" << std::endl;
						Zemaiteskai.setMaistas(-pirktasKiekis);
						Zemaiteskai.setAuksas(pirktasKiekis, 5);
					}
					Sleep(800);
					system("cls");
				}
				else if (pasirinkPirkt == 2) {
					std::cout << "Kiek ginklu norite pirkti?" << std::endl;
					std::cin >> pirktasKiekis;
					if (karvedys.getAuksiniai() < pirktasKiekis * 7) {
						std::cout << "Nepakanka auksiniu!" << std::endl;
					}
					else if (Zemaiteskai.getPirktGinklai() < pirktasKiekis) {
						std::cout << "Nera tiek ginklu!" << std::endl;
					}
					else {
						karvedys.setGinklai(pirktasKiekis);
						karvedys.setAuksiniai(-pirktasKiekis, 7);
						std::cout << std::endl;
						std::cout << "Nusipirkote: " << pirktasKiekis << " ginklu" << std::endl;
						Zemaiteskai.setPirktGinklai(-pirktasKiekis);
						Zemaiteskai.setAuksas(pirktasKiekis, 7);
					}
					Sleep(800);
					system("cls");
				}
				else if (pasirinkPirkt == 0) {
					break;
				}
			}
//Ruskiai

			else if (location == 38) {
				std::cout << "Ka norite pirkti\n";
				std::cout << "-----------------\n";
				std::cout << "1. Maista " << "| kiekis: " << Ruskiai.getMaistas() << " | kaina uz vienteta: " << "5 auksiniai" << std::endl;
				std::cout << "2. Ginklus " << "| kiekis: " << Ruskiai.getPirktGinklai() << " | kaina uz vieneta: " << "7 auksiniai" << std::endl;
				std::cout << "0. Iseiti \n";
				std::cout << "-----------------\n";
				std::cout << std::endl << "Pasirinkimas: ";
				std::cin >> pasirinkPirkt;
				std::cout << std::endl;
				if (pasirinkPirkt == 1) {
					std::cout << "Kiek maisto norite pirkti?" << std::endl;
					std::cin >> pirktasKiekis;
					if (karvedys.getAuksiniai() < pirktasKiekis * 5) {
						std::cout << "Nepakanka auksiniu!" << std::endl;
					}
					else if (Ruskiai.getMaistas() < pirktasKiekis) {
						std::cout << "Nera tiek maisto!" << std::endl;
					}
					else {
						karvedys.setMaistas(pirktasKiekis);
						karvedys.setAuksiniai(-pirktasKiekis, 5);
						std::cout << std::endl;
						std::cout << "Nusipirkote: " << pirktasKiekis << " maisto" << std::endl;
						Ruskiai.setMaistas(-pirktasKiekis);
						Ruskiai.setAuksas(pirktasKiekis, 5);
					}
					Sleep(800);
					system("cls");
				}
				else if (pasirinkPirkt == 2) {
					std::cout << "Kiek ginklu norite pirkti?" << std::endl;
					std::cin >> pirktasKiekis;
					if (karvedys.getAuksiniai() < pirktasKiekis * 7) {
						std::cout << "Nepakanka auksiniu!" << std::endl;
					}
					else if (Ruskiai.getPirktGinklai() < pirktasKiekis) {
						std::cout << "Nera tiek ginklu!" << std::endl;
					}
					else {
						karvedys.setGinklai(pirktasKiekis);
						karvedys.setAuksiniai(-pirktasKiekis, 7);
						std::cout << std::endl;
						std::cout << "Nusipirkote: " << pirktasKiekis << " ginklu" << std::endl;
						Ruskiai.setPirktGinklai(-pirktasKiekis);
						Ruskiai.setAuksas(pirktasKiekis, 7);
					}
					Sleep(800);
					system("cls");
				}
				else if (pasirinkPirkt == 0) {
					break;
				}
			}
//Otomanijai

			else if (location == 39) {
				std::cout << "Ka norite pirkti\n";
				std::cout << "-----------------\n";
				std::cout << "1. Maista " << "| kiekis: " << Otomanijai.getMaistas() << " | kaina uz vienteta: " << "5 auksiniai" << std::endl;
				std::cout << "2. Ginklus " << "| kiekis: " << Otomanijai.getPirktGinklai() << " | kaina uz vieneta: " << "7 auksiniai" << std::endl;
				std::cout << "0. Iseiti \n";
				std::cout << "-----------------\n";
				std::cout << std::endl << "Pasirinkimas: ";
				std::cin >> pasirinkPirkt;
				std::cout << std::endl;
				if (pasirinkPirkt == 1) {
					std::cout << "Kiek maisto norite pirkti?" << std::endl;
					std::cin >> pirktasKiekis;
					if (karvedys.getAuksiniai() < pirktasKiekis * 5) {
						std::cout << "Nepakanka auksiniu!" << std::endl;
					}
					else if (Otomanijai.getMaistas() < pirktasKiekis) {
						std::cout << "Nera tiek maisto!" << std::endl;
					}
					else {
						karvedys.setMaistas(pirktasKiekis);
						karvedys.setAuksiniai(-pirktasKiekis, 5);
						std::cout << std::endl;
						std::cout << "Nusipirkote: " << pirktasKiekis << " maisto" << std::endl;
						Otomanijai.setMaistas(-pirktasKiekis);
						Otomanijai.setAuksas(pirktasKiekis, 5);
					}
					Sleep(800);
					system("cls");
				}
				else if (pasirinkPirkt == 2) {
					std::cout << "Kiek ginklu norite pirkti?" << std::endl;
					std::cin >> pirktasKiekis;
					if (karvedys.getAuksiniai() < pirktasKiekis * 7) {
						std::cout << "Nepakanka auksiniu!" << std::endl;
					}
					else if (Otomanijai.getPirktGinklai() < pirktasKiekis) {
						std::cout << "Nera tiek ginklu!" << std::endl;
					}
					else {
						karvedys.setGinklai(pirktasKiekis);
						karvedys.setAuksiniai(-pirktasKiekis, 7);
						std::cout << std::endl;
						std::cout << "Nusipirkote: " << pirktasKiekis << " ginklu" << std::endl;
						Otomanijai.setPirktGinklai(-pirktasKiekis);
						Otomanijai.setAuksas(pirktasKiekis, 7);
					}
					Sleep(800);
					system("cls");
				}
				else if (pasirinkPirkt == 0) {
					break;
				}
			}
			break;
		case 2: // parduoti
			karvedys.printInfo();
			std::cout << "Ka norite parduoti?\n";
			std::cout << "-----------------\n";
			std::cout << "1. Maista " << "| kaina: 2 | turimas kiekis: " << karvedys.getMaistas() << std::endl;
			std::cout << "2. Ginklus " << "| kaina: 3 | turimas kiekis: " << karvedys.getGinklai() << std::endl;
			std::cout << "-----------------\n";
			std::cout << std::endl << "Pasirinkimas: ";
			std::cin >> pasirinkParduot;
			std::cout << std::endl;
			if (pasirinkParduot == 1) {
//Truviskes	
				if (location == 20) {
					std::cout << "Kiek maisto norite parduoti?" << std::endl;
					std::cin >> parduotasKiekis;
					if (Truviskes.getAuksiniai() < parduotasKiekis * 2) {
						std::cout << "Parduotuvei nepakanka auksiniu!" << std::endl;
					}
					else if (karvedys.getMaistas() < parduotasKiekis) {
						std::cout << "Neturite tiek maisto!" << std::endl;
					}
					else {
						karvedys.setMaistas(-parduotasKiekis);
						karvedys.setAuksiniai(parduotasKiekis, 2);
						Truviskes.setMaistas(parduotasKiekis);
						Truviskes.setAuksas(-parduotasKiekis, 2);
					}
				}
//Barteliskes
				else if (location == 21) {
					std::cout << "Kiek maisto norite parduoti?" << std::endl;
					std::cin >> parduotasKiekis;
					if (Barteliskes.getAuksiniai() < parduotasKiekis * 2) {
						std::cout << "Parduotuvei nepakanka auksiniu!" << std::endl;
					}
					else if (karvedys.getMaistas() < parduotasKiekis) {
						std::cout << "Neturite tiek maisto!" << std::endl;
					}
					else {
						karvedys.setMaistas(-parduotasKiekis);
						karvedys.setAuksiniai(parduotasKiekis, 2);
						Barteliskes.setMaistas(parduotasKiekis);
						Barteliskes.setAuksas(-parduotasKiekis, 2);
					}
				}
//Teviskes
				else if (location == 22) {
					std::cout << "Kiek maisto norite parduoti?" << std::endl;
					std::cin >> parduotasKiekis;
					if (Teviskes.getAuksiniai() < parduotasKiekis * 2) {
						std::cout << "Parduotuvei nepakanka auksiniu!" << std::endl;
					}
					else if (karvedys.getMaistas() < parduotasKiekis) {
						std::cout << "Neturite tiek maisto!" << std::endl;
					}
					else {
						karvedys.setMaistas(-parduotasKiekis);
						karvedys.setAuksiniai(parduotasKiekis, 2);
						Teviskes.setMaistas(parduotasKiekis);
						Teviskes.setAuksas(-parduotasKiekis, 2);
					}
				}
//Triogalai	
				else if (location == 23) {
					std::cout << "Kiek maisto norite parduoti?" << std::endl;
					std::cin >> parduotasKiekis;
					if (Triogalai.getAuksiniai() < parduotasKiekis * 2) {
						std::cout << "Parduotuvei nepakanka auksiniu!" << std::endl;
					}
					else if (karvedys.getMaistas() < parduotasKiekis) {
						std::cout << "Neturite tiek maisto!" << std::endl;
					}
					else {
						karvedys.setMaistas(-parduotasKiekis);
						karvedys.setAuksiniai(parduotasKiekis, 2);
						Triogalai.setMaistas(parduotasKiekis);
						Triogalai.setAuksas(-parduotasKiekis, 2);
					}
				}
//Turipai
				else if (location == 24) {
					std::cout << "Kiek maisto norite parduoti?" << std::endl;
					std::cin >> parduotasKiekis;
					if (Turipai.getAuksiniai() < parduotasKiekis * 2) {
						std::cout << "Parduotuvei nepakanka auksiniu!" << std::endl;
					}
					else if (karvedys.getMaistas() < parduotasKiekis) {
						std::cout << "Neturite tiek maisto!" << std::endl;
					}
					else {
						karvedys.setMaistas(-parduotasKiekis);
						karvedys.setAuksiniai(parduotasKiekis, 2);
						Turipai.setMaistas(parduotasKiekis);
						Turipai.setAuksas(-parduotasKiekis, 2);
					}
				}
//Karoliskes
				else if (location == 25) {
					std::cout << "Kiek maisto norite parduoti?" << std::endl;
					std::cin >> parduotasKiekis;
					if (Karoliskes.getAuksiniai() < parduotasKiekis * 2) {
						std::cout << "Parduotuvei nepakanka auksiniu!" << std::endl;
					}
					else if (karvedys.getMaistas() < parduotasKiekis) {
						std::cout << "Neturite tiek maisto!" << std::endl;
					}
					else {
						karvedys.setMaistas(-parduotasKiekis);
						karvedys.setAuksiniai(parduotasKiekis, 2);
						Karoliskes.setMaistas(parduotasKiekis);
						Karoliskes.setAuksas(-parduotasKiekis, 2);
					}
				}
//Pakalniskes
				else if (location == 26) {
					std::cout << "Kiek maisto norite parduoti?" << std::endl;
					std::cin >> parduotasKiekis;
					if (Pakalniskes.getAuksiniai() < parduotasKiekis * 2) {
						std::cout << "Parduotuvei nepakanka auksiniu!" << std::endl;
					}
					else if (karvedys.getMaistas() < parduotasKiekis) {
						std::cout << "Neturite tiek maisto!" << std::endl;
					}
					else {
						karvedys.setMaistas(-parduotasKiekis);
						karvedys.setAuksiniai(parduotasKiekis, 2);
						Pakalniskes.setMaistas(parduotasKiekis);
						Pakalniskes.setAuksas(-parduotasKiekis, 2);
					}
				}
//Genininkai
				else if (location == 27) {
					std::cout << "Kiek maisto norite parduoti?" << std::endl;
					std::cin >> parduotasKiekis;
					if (Genininkai.getAuksiniai() < parduotasKiekis * 2) {
						std::cout << "Parduotuvei nepakanka auksiniu!" << std::endl;
					}
					else if (karvedys.getMaistas() < parduotasKiekis) {
						std::cout << "Neturite tiek maisto!" << std::endl;
					}
					else {
						karvedys.setMaistas(-parduotasKiekis);
						karvedys.setAuksiniai(parduotasKiekis, 2);
						Genininkai.setMaistas(parduotasKiekis);
						Genininkai.setAuksas(-parduotasKiekis, 2);
					}
				}
//Ariogala			
				else if (location == 28) {
					std::cout << "Kiek maisto norite parduoti?" << std::endl;
					std::cin >> parduotasKiekis;
					if (Ariogala.getAuksiniai() < parduotasKiekis * 2) {
						std::cout << "Parduotuvei nepakanka auksiniu!" << std::endl;
					}
					else if (karvedys.getMaistas() < parduotasKiekis) {
						std::cout << "Neturite tiek maisto!" << std::endl;
					}
					else {
						karvedys.setMaistas(-parduotasKiekis);
						karvedys.setAuksiniai(parduotasKiekis, 2);
						Ariogala.setMaistas(parduotasKiekis);
						Ariogala.setAuksas(-parduotasKiekis, 2);
					}
				}
//Zemzeniai			
				else if (location == 29) {
					std::cout << "Kiek maisto norite parduoti?" << std::endl;
					std::cin >> parduotasKiekis;
					if (Zemzeniai.getAuksiniai() < parduotasKiekis * 2) {
						std::cout << "Parduotuvei nepakanka auksiniu!" << std::endl;
					}
					else if (karvedys.getMaistas() < parduotasKiekis) {
						std::cout << "Neturite tiek maisto!" << std::endl;
					}
					else {
						karvedys.setMaistas(-parduotasKiekis);
						karvedys.setAuksiniai(parduotasKiekis, 2);
						Zemzeniai.setMaistas(parduotasKiekis);
						Zemzeniai.setAuksas(-parduotasKiekis, 2);
					}
				}
//Dumbirdai			
				else if (location == 210) {
					std::cout << "Kiek maisto norite parduoti?" << std::endl;
					std::cin >> parduotasKiekis;
					if (Dumbirdai.getAuksiniai() < parduotasKiekis * 2) {
						std::cout << "Parduotuvei nepakanka auksiniu!" << std::endl;
					}
					else if (karvedys.getMaistas() < parduotasKiekis) {
						std::cout << "Neturite tiek maisto!" << std::endl;
					}
					else {
						karvedys.setMaistas(-parduotasKiekis);
						karvedys.setAuksiniai(parduotasKiekis, 2);
						Dumbirdai.setMaistas(parduotasKiekis);
						Dumbirdai.setAuksas(-parduotasKiekis, 2);
					}
				}
//Likoniai			
				else if (location == 211) {
					std::cout << "Kiek maisto norite parduoti?" << std::endl;
					std::cin >> parduotasKiekis;
					if (Likoniai.getAuksiniai() < parduotasKiekis * 2) {
						std::cout << "Parduotuvei nepakanka auksiniu!" << std::endl;
					}
					else if (karvedys.getMaistas() < parduotasKiekis) {
						std::cout << "Neturite tiek maisto!" << std::endl;
					}
					else {
						karvedys.setMaistas(-parduotasKiekis);
						karvedys.setAuksiniai(parduotasKiekis, 2);
						Likoniai.setMaistas(parduotasKiekis);
						Likoniai.setAuksas(-parduotasKiekis, 2);
					}
				}
//Ceckes			
				else if (location == 212) {
					std::cout << "Kiek maisto norite parduoti?" << std::endl;
					std::cin >> parduotasKiekis;
					if (Ceckes.getAuksiniai() < parduotasKiekis * 2) {
						std::cout << "Parduotuvei nepakanka auksiniu!" << std::endl;
					}
					else if (karvedys.getMaistas() < parduotasKiekis) {
						std::cout << "Neturite tiek maisto!" << std::endl;
					}
					else {
						karvedys.setMaistas(-parduotasKiekis);
						karvedys.setAuksiniai(parduotasKiekis, 2);
						Ceckes.setMaistas(parduotasKiekis);
						Ceckes.setAuksas(-parduotasKiekis, 2);
					}
				}
//Grazdionys			
				else if (location == 213) {
					std::cout << "Kiek maisto norite parduoti?" << std::endl;
					std::cin >> parduotasKiekis;
					if (Grazdionys.getAuksiniai() < parduotasKiekis * 2) {
						std::cout << "Parduotuvei nepakanka auksiniu!" << std::endl;
					}
					else if (karvedys.getMaistas() < parduotasKiekis) {
						std::cout << "Neturite tiek maisto!" << std::endl;
					}
					else {
						karvedys.setMaistas(-parduotasKiekis);
						karvedys.setAuksiniai(parduotasKiekis, 2);
						Grazdionys.setMaistas(parduotasKiekis);
						Grazdionys.setAuksas(-parduotasKiekis, 2);
					}
				}
//Programintai			
				else if (location == 214) {
					std::cout << "Kiek maisto norite parduoti?" << std::endl;
					std::cin >> parduotasKiekis;
					if (Programintai.getAuksiniai() < parduotasKiekis * 2) {
						std::cout << "Parduotuvei nepakanka auksiniu!" << std::endl;
					}
					else if (karvedys.getMaistas() < parduotasKiekis) {
						std::cout << "Neturite tiek maisto!" << std::endl;
					}
					else {
						karvedys.setMaistas(-parduotasKiekis);
						karvedys.setAuksiniai(parduotasKiekis, 2);
						Programintai.setMaistas(parduotasKiekis);
						Programintai.setAuksas(-parduotasKiekis, 2);
					}
				}

//Frankai			
				else if (location == 30) {
					std::cout << "Kiek maisto norite parduoti?" << std::endl;
					std::cin >> parduotasKiekis;
					if (Frankite.getAuksiniai() < parduotasKiekis * 2) {
						std::cout << "Parduotuvei nepakanka auksiniu!" << std::endl;
					}
					else if (karvedys.getMaistas() < parduotasKiekis) {
						std::cout << "Neturite tiek maisto!" << std::endl;
					}
					else {
						karvedys.setMaistas(-parduotasKiekis);
						karvedys.setAuksiniai(parduotasKiekis, 2);
						Frankite.setMaistas(parduotasKiekis);
						Frankite.setAuksas(-parduotasKiekis, 2);
					}
				}
//Germanite			
				else if (location == 31) {
					std::cout << "Kiek maisto norite parduoti?" << std::endl;
					std::cin >> parduotasKiekis;
					if (Germanite.getAuksiniai() < parduotasKiekis * 2) {
						std::cout << "Parduotuvei nepakanka auksiniu!" << std::endl;
					}
					else if (karvedys.getMaistas() < parduotasKiekis) {
						std::cout << "Neturite tiek maisto!" << std::endl;
					}
					else {
						karvedys.setMaistas(-parduotasKiekis);
						karvedys.setAuksiniai(parduotasKiekis, 2);
						Germanite.setMaistas(parduotasKiekis);
						Germanite.setAuksas(-parduotasKiekis, 2);
					}
				}
//Svedite			
				else if (location == 32) {
					std::cout << "Kiek maisto norite parduoti?" << std::endl;
					std::cin >> parduotasKiekis;
					if (Svedite.getAuksiniai() < parduotasKiekis * 2) {
						std::cout << "Parduotuvei nepakanka auksiniu!" << std::endl;
					}
					else if (karvedys.getMaistas() < parduotasKiekis) {
						std::cout << "Neturite tiek maisto!" << std::endl;
					}
					else {
						karvedys.setMaistas(-parduotasKiekis);
						karvedys.setAuksiniai(parduotasKiekis, 2);
						Svedite.setMaistas(parduotasKiekis);
						Svedite.setAuksas(-parduotasKiekis, 2);
					}
				}
//Italiano			
				else if (location == 33) {
					std::cout << "Kiek maisto norite parduoti?" << std::endl;
					std::cin >> parduotasKiekis;
					if (Italiano.getAuksiniai() < parduotasKiekis * 2) {
						std::cout << "Parduotuvei nepakanka auksiniu!" << std::endl;
					}
					else if (karvedys.getMaistas() < parduotasKiekis) {
						std::cout << "Neturite tiek maisto!" << std::endl;
					}
					else {
						karvedys.setMaistas(-parduotasKiekis);
						karvedys.setAuksiniai(parduotasKiekis, 2);
						Italiano.setMaistas(parduotasKiekis);
						Italiano.setAuksas(-parduotasKiekis, 2);
					}
				}
//Galiano			
				else if (location == 34) {
					std::cout << "Kiek maisto norite parduoti?" << std::endl;
					std::cin >> parduotasKiekis;
					if (Galiano.getAuksiniai() < parduotasKiekis * 2) {
						std::cout << "Parduotuvei nepakanka auksiniu!" << std::endl;
					}
					else if (karvedys.getMaistas() < parduotasKiekis) {
						std::cout << "Neturite tiek maisto!" << std::endl;
					}
					else {
						karvedys.setMaistas(-parduotasKiekis);
						karvedys.setAuksiniai(parduotasKiekis, 2);
						Galiano.setMaistas(parduotasKiekis);
						Galiano.setAuksas(-parduotasKiekis, 2);
					}
				}
//Vikingaites			
				else if (location == 35) {
					std::cout << "Kiek maisto norite parduoti?" << std::endl;
					std::cin >> parduotasKiekis;
					if (Vikingaites.getAuksiniai() < parduotasKiekis * 2) {
						std::cout << "Parduotuvei nepakanka auksiniu!" << std::endl;
					}
					else if (karvedys.getMaistas() < parduotasKiekis) {
						std::cout << "Neturite tiek maisto!" << std::endl;
					}
					else {
						karvedys.setMaistas(-parduotasKiekis);
						karvedys.setAuksiniai(parduotasKiekis, 2);
						Vikingaites.setMaistas(parduotasKiekis);
						Vikingaites.setAuksas(-parduotasKiekis, 2);
					}
				}
//Lituanica			
				else if (location == 36) {
					std::cout << "Kiek maisto norite parduoti?" << std::endl;
					std::cin >> parduotasKiekis;
					if (Lituanica.getAuksiniai() < parduotasKiekis * 2) {
						std::cout << "Parduotuvei nepakanka auksiniu!" << std::endl;
					}
					else if (karvedys.getMaistas() < parduotasKiekis) {
						std::cout << "Neturite tiek maisto!" << std::endl;
					}
					else {
						karvedys.setMaistas(-parduotasKiekis);
						karvedys.setAuksiniai(parduotasKiekis, 2);
						Lituanica.setMaistas(parduotasKiekis);
						Lituanica.setAuksas(-parduotasKiekis, 2);
					}
				}
//Zemaiteskai			
				else if (location == 37) {
					std::cout << "Kiek maisto norite parduoti?" << std::endl;
					std::cin >> parduotasKiekis;
					if (Zemaiteskai.getAuksiniai() < parduotasKiekis * 2) {
						std::cout << "Parduotuvei nepakanka auksiniu!" << std::endl;
					}
					else if (karvedys.getMaistas() < parduotasKiekis) {
						std::cout << "Neturite tiek maisto!" << std::endl;
					}
					else {
						karvedys.setMaistas(-parduotasKiekis);
						karvedys.setAuksiniai(parduotasKiekis, 2);
						Zemaiteskai.setMaistas(parduotasKiekis);
						Zemaiteskai.setAuksas(-parduotasKiekis, 2);
					}
				}
//Ruskiai			
				else if (location == 38) {
					std::cout << "Kiek maisto norite parduoti?" << std::endl;
					std::cin >> parduotasKiekis;
					if (Ruskiai.getAuksiniai() < parduotasKiekis * 2) {
						std::cout << "Parduotuvei nepakanka auksiniu!" << std::endl;
					}
					else if (karvedys.getMaistas() < parduotasKiekis) {
						std::cout << "Neturite tiek maisto!" << std::endl;
					}
					else {
						karvedys.setMaistas(-parduotasKiekis);
						karvedys.setAuksiniai(parduotasKiekis, 2);
						Ruskiai.setMaistas(parduotasKiekis);
						Ruskiai.setAuksas(-parduotasKiekis, 2);
					}
				}
//Otomanijai			
				else if (location == 39) {
					std::cout << "Kiek maisto norite parduoti?" << std::endl;
					std::cin >> parduotasKiekis;
					if (Otomanijai.getAuksiniai() < parduotasKiekis * 2) {
						std::cout << "Parduotuvei nepakanka auksiniu!" << std::endl;
					}
					else if (karvedys.getMaistas() < parduotasKiekis) {
						std::cout << "Neturite tiek maisto!" << std::endl;
					}
					else {
						karvedys.setMaistas(-parduotasKiekis);
						karvedys.setAuksiniai(parduotasKiekis, 2);
						Otomanijai.setMaistas(parduotasKiekis);
						Otomanijai.setAuksas(-parduotasKiekis, 2);
					}
				}
			Sleep(800);
			system("cls");
			}
			else if (pasirinkParduot == 2) {
//Truviskes			
				if (location == 20) {
					std::cout << "Kiek ginklu norite parduoti?" << std::endl;
					std::cin >> parduotasKiekis;
					if (Truviskes.getAuksiniai() < parduotasKiekis * 3) {
						std::cout << "Parduotuvei nepakanka auksiniu!" << std::endl;
					}
					else if (karvedys.getGinklai() < parduotasKiekis) {
						std::cout << "Neturite tiek ginklu!" << std::endl;
					}
					else {
						karvedys.setGinklai(-parduotasKiekis);
						karvedys.setAuksiniai(parduotasKiekis, 3);
						Truviskes.setGinklai(parduotasKiekis);
						Truviskes.setAuksas(-parduotasKiekis, 3);

					}
				}
//Barteliskes			
				else if (location == 21) {
					std::cout << "Kiek ginklu norite parduoti?" << std::endl;
					std::cin >> parduotasKiekis;
					if (Barteliskes.getAuksiniai() < parduotasKiekis * 3) {
						std::cout << "Parduotuvei nepakanka auksiniu!" << std::endl;
					}
					else if (karvedys.getGinklai() < parduotasKiekis) {
						std::cout << "Neturite tiek ginklu!" << std::endl;
					}
					else {
						karvedys.setGinklai(-parduotasKiekis);
						karvedys.setAuksiniai(parduotasKiekis, 3);
						Barteliskes.setGinklai(parduotasKiekis);
						Barteliskes.setAuksas(-parduotasKiekis, 3);

					}
				}
//Teviskes			
				else if (location == 22) {
					std::cout << "Kiek ginklu norite parduoti?" << std::endl;
					std::cin >> parduotasKiekis;
					if (Teviskes.getAuksiniai() < parduotasKiekis * 3) {
						std::cout << "Parduotuvei nepakanka auksiniu!" << std::endl;
					}
					else if (karvedys.getGinklai() < parduotasKiekis) {
						std::cout << "Neturite tiek ginklu!" << std::endl;
					}
					else {
						karvedys.setGinklai(-parduotasKiekis);
						karvedys.setAuksiniai(parduotasKiekis, 3);
						Teviskes.setGinklai(parduotasKiekis);
						Teviskes.setAuksas(-parduotasKiekis, 3);

					}
				}
//Triogalai			
				else if (location == 23) {
					std::cout << "Kiek ginklu norite parduoti?" << std::endl;
					std::cin >> parduotasKiekis;
					if (Triogalai.getAuksiniai() < parduotasKiekis * 3) {
						std::cout << "Parduotuvei nepakanka auksiniu!" << std::endl;
					}
					else if (karvedys.getGinklai() < parduotasKiekis) {
						std::cout << "Neturite tiek ginklu!" << std::endl;
					}
					else {
						karvedys.setGinklai(-parduotasKiekis);
						karvedys.setAuksiniai(parduotasKiekis, 3);
						Triogalai.setGinklai(parduotasKiekis);
						Triogalai.setAuksas(-parduotasKiekis, 3);

					}
				}
//Turipai			
				else if (location == 24) {
					std::cout << "Kiek ginklu norite parduoti?" << std::endl;
					std::cin >> parduotasKiekis;
					if (Turipai.getAuksiniai() < parduotasKiekis * 3) {
						std::cout << "Parduotuvei nepakanka auksiniu!" << std::endl;
					}
					else if (karvedys.getGinklai() < parduotasKiekis) {
						std::cout << "Neturite tiek ginklu!" << std::endl;
					}
					else {
						karvedys.setGinklai(-parduotasKiekis);
						karvedys.setAuksiniai(parduotasKiekis, 3);
						Turipai.setGinklai(parduotasKiekis);
						Turipai.setAuksas(-parduotasKiekis, 3);

					}
				}
//Karoliskes			
				else if (location == 25) {
					std::cout << "Kiek ginklu norite parduoti?" << std::endl;
					std::cin >> parduotasKiekis;
					if (Karoliskes.getAuksiniai() < parduotasKiekis * 3) {
						std::cout << "Parduotuvei nepakanka auksiniu!" << std::endl;
					}
					else if (karvedys.getGinklai() < parduotasKiekis) {
						std::cout << "Neturite tiek ginklu!" << std::endl;
					}
					else {
						karvedys.setGinklai(-parduotasKiekis);
						karvedys.setAuksiniai(parduotasKiekis, 3);
						Karoliskes.setGinklai(parduotasKiekis);
						Karoliskes.setAuksas(-parduotasKiekis, 3);

					}
				}
//Pakalniskes			
				else if (location == 26) {
					std::cout << "Kiek ginklu norite parduoti?" << std::endl;
					std::cin >> parduotasKiekis;
					if (Pakalniskes.getAuksiniai() < parduotasKiekis * 3) {
						std::cout << "Parduotuvei nepakanka auksiniu!" << std::endl;
					}
					else if (karvedys.getGinklai() < parduotasKiekis) {
						std::cout << "Neturite tiek ginklu!" << std::endl;
					}
					else {
						karvedys.setGinklai(-parduotasKiekis);
						karvedys.setAuksiniai(parduotasKiekis, 3);
						Pakalniskes.setGinklai(parduotasKiekis);
						Pakalniskes.setAuksas(-parduotasKiekis, 3);

					}
				}
//Genininkai			
				else if (location == 27) {
					std::cout << "Kiek ginklu norite parduoti?" << std::endl;
					std::cin >> parduotasKiekis;
					if (Genininkai.getAuksiniai() < parduotasKiekis * 3) {
						std::cout << "Parduotuvei nepakanka auksiniu!" << std::endl;
					}
					else if (karvedys.getGinklai() < parduotasKiekis) {
						std::cout << "Neturite tiek ginklu!" << std::endl;
					}
					else {
						karvedys.setGinklai(-parduotasKiekis);
						karvedys.setAuksiniai(parduotasKiekis, 3);
						Genininkai.setGinklai(parduotasKiekis);
						Genininkai.setAuksas(-parduotasKiekis, 3);

					}
				}
//Ariogala			
				else if (location == 28) {
					std::cout << "Kiek ginklu norite parduoti?" << std::endl;
					std::cin >> parduotasKiekis;
					if (Ariogala.getAuksiniai() < parduotasKiekis * 3) {
						std::cout << "Parduotuvei nepakanka auksiniu!" << std::endl;
					}
					else if (karvedys.getGinklai() < parduotasKiekis) {
						std::cout << "Neturite tiek ginklu!" << std::endl;
					}
					else {
						karvedys.setGinklai(-parduotasKiekis);
						karvedys.setAuksiniai(parduotasKiekis, 3);
						Ariogala.setGinklai(parduotasKiekis);
						Ariogala.setAuksas(-parduotasKiekis, 3);

					}
				}
//Zemzeniai			
				else if (location == 29) {
					std::cout << "Kiek ginklu norite parduoti?" << std::endl;
					std::cin >> parduotasKiekis;
					if (Zemzeniai.getAuksiniai() < parduotasKiekis * 3) {
						std::cout << "Parduotuvei nepakanka auksiniu!" << std::endl;
					}
					else if (karvedys.getGinklai() < parduotasKiekis) {
						std::cout << "Neturite tiek ginklu!" << std::endl;
					}
					else {
						karvedys.setGinklai(-parduotasKiekis);
						karvedys.setAuksiniai(parduotasKiekis, 3);
						Zemzeniai.setGinklai(parduotasKiekis);
						Zemzeniai.setAuksas(-parduotasKiekis, 3);

					}
				}
//Dumbirdai			
				else if (location == 210) {
					std::cout << "Kiek ginklu norite parduoti?" << std::endl;
					std::cin >> parduotasKiekis;
					if (Dumbirdai.getAuksiniai() < parduotasKiekis * 3) {
						std::cout << "Parduotuvei nepakanka auksiniu!" << std::endl;
					}
					else if (karvedys.getGinklai() < parduotasKiekis) {
						std::cout << "Neturite tiek ginklu!" << std::endl;
					}
					else {
						karvedys.setGinklai(-parduotasKiekis);
						karvedys.setAuksiniai(parduotasKiekis, 3);
						Dumbirdai.setGinklai(parduotasKiekis);
						Dumbirdai.setAuksas(-parduotasKiekis, 3);

					}
				}
//Likoniai			
				else if (location == 211) {
					std::cout << "Kiek ginklu norite parduoti?" << std::endl;
					std::cin >> parduotasKiekis;
					if (Likoniai.getAuksiniai() < parduotasKiekis * 3) {
						std::cout << "Parduotuvei nepakanka auksiniu!" << std::endl;
					}
					else if (karvedys.getGinklai() < parduotasKiekis) {
						std::cout << "Neturite tiek ginklu!" << std::endl;
					}
					else {
						karvedys.setGinklai(-parduotasKiekis);
						karvedys.setAuksiniai(parduotasKiekis, 3);
						Likoniai.setGinklai(parduotasKiekis);
						Likoniai.setAuksas(-parduotasKiekis, 3);

					}
				}
//Ceckes			
				else if (location == 212) {
					std::cout << "Kiek ginklu norite parduoti?" << std::endl;
					std::cin >> parduotasKiekis;
					if (Ceckes.getAuksiniai() < parduotasKiekis * 3) {
						std::cout << "Parduotuvei nepakanka auksiniu!" << std::endl;
					}
					else if (karvedys.getGinklai() < parduotasKiekis) {
						std::cout << "Neturite tiek ginklu!" << std::endl;
					}
					else {
						karvedys.setGinklai(-parduotasKiekis);
						karvedys.setAuksiniai(parduotasKiekis, 3);
						Ceckes.setGinklai(parduotasKiekis);
						Ceckes.setAuksas(-parduotasKiekis, 3);

					}
				}
//Grazdionys			
				else if (location == 213) {
					std::cout << "Kiek ginklu norite parduoti?" << std::endl;
					std::cin >> parduotasKiekis;
					if (Grazdionys.getAuksiniai() < parduotasKiekis * 3) {
						std::cout << "Parduotuvei nepakanka auksiniu!" << std::endl;
					}
					else if (karvedys.getGinklai() < parduotasKiekis) {
						std::cout << "Neturite tiek ginklu!" << std::endl;
					}
					else {
						karvedys.setGinklai(-parduotasKiekis);
						karvedys.setAuksiniai(parduotasKiekis, 3);
						Grazdionys.setGinklai(parduotasKiekis);
						Grazdionys.setAuksas(-parduotasKiekis, 3);

					}
				}
//Programintai			
				else if (location == 214) {
					std::cout << "Kiek ginklu norite parduoti?" << std::endl;
					std::cin >> parduotasKiekis;
					if (Programintai.getAuksiniai() < parduotasKiekis * 3) {
						std::cout << "Parduotuvei nepakanka auksiniu!" << std::endl;
					}
					else if (karvedys.getGinklai() < parduotasKiekis) {
						std::cout << "Neturite tiek ginklu!" << std::endl;
					}
					else {
						karvedys.setGinklai(-parduotasKiekis);
						karvedys.setAuksiniai(parduotasKiekis, 3);
						Programintai.setGinklai(parduotasKiekis);
						Programintai.setAuksas(-parduotasKiekis, 3);

					}
				}
//Frankai		
				else if (location == 30) {
					std::cout << "Kiek ginklu norite parduoti?" << std::endl;
					std::cin >> parduotasKiekis;
					if (Frankite.getAuksiniai() < parduotasKiekis * 3) {
						std::cout << "Parduotuvei nepakanka auksiniu!" << std::endl;
					}
					else if (karvedys.getGinklai() < parduotasKiekis) {
						std::cout << "Neturite tiek ginklu!" << std::endl;
					}
					else {
						karvedys.setGinklai(-parduotasKiekis);
						karvedys.setAuksiniai(parduotasKiekis, 3);
						Frankite.setGinklai(parduotasKiekis);
						Frankite.setAuksas(-parduotasKiekis, 3);

					}
				}
//Germanite		
				else if (location == 31) {
					std::cout << "Kiek ginklu norite parduoti?" << std::endl;
					std::cin >> parduotasKiekis;
					if (Germanite.getAuksiniai() < parduotasKiekis * 3) {
						std::cout << "Parduotuvei nepakanka auksiniu!" << std::endl;
					}
					else if (karvedys.getGinklai() < parduotasKiekis) {
						std::cout << "Neturite tiek ginklu!" << std::endl;
					}
					else {
						karvedys.setGinklai(-parduotasKiekis);
						karvedys.setAuksiniai(parduotasKiekis, 3);
						Germanite.setGinklai(parduotasKiekis);
						Germanite.setAuksas(-parduotasKiekis, 3);

					}
				}
//Svedite		
				else if (location == 32) {
					std::cout << "Kiek ginklu norite parduoti?" << std::endl;
					std::cin >> parduotasKiekis;
					if (Svedite.getAuksiniai() < parduotasKiekis * 3) {
						std::cout << "Parduotuvei nepakanka auksiniu!" << std::endl;
					}
					else if (karvedys.getGinklai() < parduotasKiekis) {
						std::cout << "Neturite tiek ginklu!" << std::endl;
					}
					else {
						karvedys.setGinklai(-parduotasKiekis);
						karvedys.setAuksiniai(parduotasKiekis, 3);
						Svedite.setGinklai(parduotasKiekis);
						Svedite.setAuksas(-parduotasKiekis, 3);

					}
				}
//Italiano		
				else if (location == 33) {
					std::cout << "Kiek ginklu norite parduoti?" << std::endl;
					std::cin >> parduotasKiekis;
					if (Italiano.getAuksiniai() < parduotasKiekis * 3) {
						std::cout << "Parduotuvei nepakanka auksiniu!" << std::endl;
					}
					else if (karvedys.getGinklai() < parduotasKiekis) {
						std::cout << "Neturite tiek ginklu!" << std::endl;
					}
					else {
						karvedys.setGinklai(-parduotasKiekis);
						karvedys.setAuksiniai(parduotasKiekis, 3);
						Italiano.setGinklai(parduotasKiekis);
						Italiano.setAuksas(-parduotasKiekis, 3);

					}
				}
//Galiano		
				else if (location == 34) {
					std::cout << "Kiek ginklu norite parduoti?" << std::endl;
					std::cin >> parduotasKiekis;
					if (Galiano.getAuksiniai() < parduotasKiekis * 3) {
						std::cout << "Parduotuvei nepakanka auksiniu!" << std::endl;
					}
					else if (karvedys.getGinklai() < parduotasKiekis) {
						std::cout << "Neturite tiek ginklu!" << std::endl;
					}
					else {
						karvedys.setGinklai(-parduotasKiekis);
						karvedys.setAuksiniai(parduotasKiekis, 3);
						Galiano.setGinklai(parduotasKiekis);
						Galiano.setAuksas(-parduotasKiekis, 3);

					}
				}
//Vikingaites		
				else if (location == 35) {
					std::cout << "Kiek ginklu norite parduoti?" << std::endl;
					std::cin >> parduotasKiekis;
					if (Vikingaites.getAuksiniai() < parduotasKiekis * 3) {
						std::cout << "Parduotuvei nepakanka auksiniu!" << std::endl;
					}
					else if (karvedys.getGinklai() < parduotasKiekis) {
						std::cout << "Neturite tiek ginklu!" << std::endl;
					}
					else {
						karvedys.setGinklai(-parduotasKiekis);
						karvedys.setAuksiniai(parduotasKiekis, 3);
						Vikingaites.setGinklai(parduotasKiekis);
						Vikingaites.setAuksas(-parduotasKiekis, 3);

					}
				}
//Lituanica		
				else if (location == 36) {
					std::cout << "Kiek ginklu norite parduoti?" << std::endl;
					std::cin >> parduotasKiekis;
					if (Lituanica.getAuksiniai() < parduotasKiekis * 3) {
						std::cout << "Parduotuvei nepakanka auksiniu!" << std::endl;
					}
					else if (karvedys.getGinklai() < parduotasKiekis) {
						std::cout << "Neturite tiek ginklu!" << std::endl;
					}
					else {
						karvedys.setGinklai(-parduotasKiekis);
						karvedys.setAuksiniai(parduotasKiekis, 3);
						Lituanica.setGinklai(parduotasKiekis);
						Lituanica.setAuksas(-parduotasKiekis, 3);

					}
				}
//Zemaiteskai		
				else if (location == 37) {
					std::cout << "Kiek ginklu norite parduoti?" << std::endl;
					std::cin >> parduotasKiekis;
					if (Zemaiteskai.getAuksiniai() < parduotasKiekis * 3) {
						std::cout << "Parduotuvei nepakanka auksiniu!" << std::endl;
					}
					else if (karvedys.getGinklai() < parduotasKiekis) {
						std::cout << "Neturite tiek ginklu!" << std::endl;
					}
					else {
						karvedys.setGinklai(-parduotasKiekis);
						karvedys.setAuksiniai(parduotasKiekis, 3);
						Zemaiteskai.setGinklai(parduotasKiekis);
						Zemaiteskai.setAuksas(-parduotasKiekis, 3);

					}
				}
//Ruskiai		
				else if (location == 38) {
					std::cout << "Kiek ginklu norite parduoti?" << std::endl;
					std::cin >> parduotasKiekis;
					if (Ruskiai.getAuksiniai() < parduotasKiekis * 3) {
						std::cout << "Parduotuvei nepakanka auksiniu!" << std::endl;
					}
					else if (karvedys.getGinklai() < parduotasKiekis) {
						std::cout << "Neturite tiek ginklu!" << std::endl;
					}
					else {
						karvedys.setGinklai(-parduotasKiekis);
						karvedys.setAuksiniai(parduotasKiekis, 3);
						Ruskiai.setGinklai(parduotasKiekis);
						Ruskiai.setAuksas(-parduotasKiekis, 3);
					}
				}
//Otomanijai		
				else if (location == 39) {
					std::cout << "Kiek ginklu norite parduoti?" << std::endl;
					std::cin >> parduotasKiekis;
					if (Otomanijai.getAuksiniai() < parduotasKiekis * 3) {
						std::cout << "Parduotuvei nepakanka auksiniu!" << std::endl;
					}
					else if (karvedys.getGinklai() < parduotasKiekis) {
						std::cout << "Neturite tiek ginklu!" << std::endl;
					}
					else {
						karvedys.setGinklai(-parduotasKiekis);
						karvedys.setAuksiniai(parduotasKiekis, 3);
						Otomanijai.setGinklai(parduotasKiekis);
						Otomanijai.setAuksas(-parduotasKiekis, 3);
					}
				}
				Sleep(800);
				system("cls");
			}
			else if (pasirinkParduot == 0) {
				break;
			}
			break;
		default:
			std::cout << "Tokio pasirinkimo nera" << std::endl;
		}
	}
	system("cls");
}

void game::travel() {
	std::string direction{};
	/* 0-siena, 1-kelias, 2-kaimas, 3-pilis, 4-bandits
	20- Truviskes 21-Berteliskes 22-Teviskes 23-Triogalai 24-Turipai 25-Karoliskes 26-Pakalniskes 27-Genininkai 28-Ariogala 29-Zemzeniai 210-Dumbirdai 211-Likoniai 212-Ceckes 213-Grazdionys, 214-Programintai
	30- Frankite 31-Germanite 32-Svedite 33-Italiano 34-Galiano 35-Vikingaites 36-Lituanica 37-Zemaiteskai 38- Ruskiai 39-Otomanijai
	40-Vandalai 41-Daktarai 42-Tulpiniai 43-Princai 44-Daskiniai 45-Caponiai 46-Vutangai 47-Kursiai 48-Garbetroskos 49-Kobros
	*/
	int map[11][11]{ 
		0,  0,  0,  0,  0,  0,  0,  0,  0,  0,0,
		0,  1,  1, 40, 20,  1, 30,  1, 41,  1,0,
		0, 31,  1, 21,  1,  1, 22,  1, 42,  1,0,
		0,  1, 23,  1, 32,  1, 43,  1, 24,  1,0,
		0, 25,  1, 44,  1, 26,  1, 33,  1,  1,0,
		0, 27, 34,  1,  1, 45,  1, 28,  1,  1,0,
		0,  1, 29, 46,  1,  1, 35,  1,  1,210,0,
		0, 36,  1,  1, 47,211, 37,  1,212,  1,0,
		0,  1,  1,  1,  1,  1,  1, 48,213, 38,0,
		0,  1,  1,  1,  1, 39,  1,214,  1, 49,0,
		0,  0,  0,  0,  0,  0,  0,  0,  0,  0,0
	};
	int location{ map[karvedys.getXPos()][karvedys.getYPos()] }; // veikejo vieta
	system("cls");
	while (direction != "atgal") {
		std::cout << "--------------------------------------------------" << std::endl; //meniu
		std::cout << "Jusu vieta " << location << std::endl;
		std::cout << "Keliavimas!" << std::endl;
		std::cout << "Iveskite krypti (siaure, pietus , rytai, vakarai)" << std::endl;
		std::cout << "Jei norite grizti iveskite zodi: atgal" << std::endl;
		std::cout << "--------------------------------------------------" << std::endl;
		std::cin >> direction;
		system("cls");
// kelione siauren
		if (direction == "siaure") { 
			karvedys.setNorthXpos();
			location = map[karvedys.getXPos()][karvedys.getYPos()];
			if (location == 0) { // bounds checking
				std::cout << "Pasiekete siaures asigali ir privalote grizti" << std::endl;
				karvedys.setSouthXpos();
				location = map[karvedys.getXPos()][karvedys.getYPos()];
			}
			else if (location == 1) {
				std::cout << "Siose zemese nieko nera.. Keliaukite toliau" << std::endl;
			}
			else if (location == 20 || location == 21 || location == 22 || location == 23 ||
				location == 24 || location == 25 || location == 26 || location == 27 ||
				location == 28 || location == 29 || location == 210 || location == 211 ||
				location == 212 || location == 213 || location == 214) {
				kaimasMenu(location);
			}
			else if (location == 30 || location == 31 || location == 32 || location == 33 ||
				location == 34 || location == 35 || location == 36 || location == 37 ||
				location == 38 || location == 39){
				pilisMenu(location);
			}
			else if (location == 40 || location == 41 || location == 42 || location == 43 ||
				location == 44 || location == 45 || location == 46 || location == 47 ||
				location == 48 || location == 49) {
				banditMenu(location);
			}
			ejimas();

		}
// kelione pietus
		else if (direction == "pietus") {
			karvedys.setSouthXpos();
			location = map[karvedys.getXPos()][karvedys.getYPos()];
			if (location == 0) {
				karvedys.setNorthXpos();
				std::cout << "Pasiekete dykuma ir privalote grizti" << std::endl;
				location = map[karvedys.getXPos()][karvedys.getYPos()];
			}
			else if (location == 1) {
				std::cout << "Siose zemese nieko nera.. Keliaukite toliau" << std::endl;
			}
			else if (location == 20 || location == 21 || location == 22 || location == 23 ||
				location == 24 || location == 25 || location == 26 || location == 27 ||
				location == 28 || location == 29 || location == 210 || location == 211 ||
				location == 212 || location == 213 || location == 214) {
				kaimasMenu(location);
			}
			else if (location == 30 || location == 31 || location == 32 || location == 33 ||
				location == 34 || location == 35 || location == 36 || location == 37 ||
				location == 38 || location == 39)
			{
				pilisMenu(location);
			}
			else if (location == 40 || location == 41 || location == 42 || location == 43 ||
				location == 44 || location == 45 || location == 46 || location == 47 ||
				location == 48 || location == 49) {
				banditMenu(location);
			}
			ejimas();
		}
// kelione rytai
		else if (direction == "rytai") {
			karvedys.setEastYpos();
			location = map[karvedys.getXPos()][karvedys.getYPos()];

			if (location == 0) {
				karvedys.setWestYpos();
				std::cout << "Pasiekete kalnus ir privalote grizti" << std::endl;
				location = map[karvedys.getXPos()][karvedys.getYPos()];
			}
			else if (location == 1) {
				std::cout << "Siose zemese nieko nera.. Keliaukite toliau" << std::endl;
			}
			else if (location == 20 || location == 21 || location == 22 || location == 23 ||
				location == 24 || location == 25 || location == 26 || location == 27 ||
				location == 28 || location == 29 || location == 210 || location == 211 ||
				location == 212 || location == 213 || location == 214) {
				kaimasMenu(location);
			}
			else if (location == 30 || location == 31 || location == 32 || location == 33 ||
				location == 34 || location == 35 || location == 36 || location == 37 ||
				location == 38 || location == 39)
			{
				pilisMenu(location);
			}
			else if (location == 40 || location == 41 || location == 42 || location == 43 ||
				location == 44 || location == 45 || location == 46 || location == 47 ||
				location == 48 || location == 49) {
				banditMenu(location);
			}
			ejimas();
		}
// kelione vakarai
		else if (direction == "vakarai") {
			karvedys.setWestYpos();
			location = map[karvedys.getXPos()][karvedys.getYPos()];
			if (location == 0) {
				karvedys.setEastYpos();
				std::cout << "Pasiekete jura ir privalote grizti" << std::endl;
				location = map[karvedys.getXPos()][karvedys.getYPos()];
			}
			else if (location == 1) {
				std::cout << "Siose zemese nieko nera.. Keliaukite toliau" << std::endl;
			}
			else if (location == 20 || location == 21 || location == 22 || location == 23 ||
				location == 24 || location == 25 || location == 26 || location == 27 ||
				location == 28 || location == 29 || location == 210 || location == 211 ||
				location == 212 || location == 213 || location == 214) {
				kaimasMenu(location);
			}
			else if (location == 30 || location == 31 || location == 32 || location == 33 ||
				location == 34 || location == 35 || location == 36 || location == 37 ||
				location == 38 || location == 39)
			{
				pilisMenu(location);
			}
			else if (location == 40 || location == 41 || location == 42 || location == 43 ||
				location == 44 || location == 45 || location == 46 || location == 47 ||
				location == 48 || location == 49) {
				banditMenu(location);
			}
			ejimas();
		}
	}
	system("cls");
}
