#include "game.h"

//constructor
game::game() {
	this->choice = 0;
	this->playing = true;
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
	std::cout << "Main Menu\n";
	std::cout << "1. Keliauti \n";
	std::cout << "2. Inventorius \n";
	std::cout << "3. Lygis \n";
	std::cout << "4. Karvedzio informacija \n";
	std::cout << "0. Iseiti \n";

	std::cout << std::endl << "Pasirinkimas: ";
	std::cin >> choice;
	std::cout << std::endl;

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
	case 4://characterinfo
		karvedys.printInfo();
		break;
	default:
		break;

	}
}
void game::travel() {
	std::string direction{};
	int map[11][11]{ // 0-siena, 1-kelias, 2-kaimas, 3-pilis, 4-bandits
		0,0,0,0,0,0,0,0,0,0,0,
		0,1,2,4,2,1,3,1,4,1,0,
		0,3,1,2,1,1,2,1,4,1,0,
		0,1,2,1,3,1,4,1,2,1,0,
		0,2,1,4,1,2,1,3,1,1,0,
		0,2,3,1,1,4,1,2,1,1,0,
		0,1,2,4,1,1,3,1,1,2,0,
		0,3,1,1,4,2,3,1,2,1,0,
		0,1,1,1,1,1,1,4,2,3,0,
		0,1,1,1,1,3,1,2,1,4,0,
		0,0,0,0,0,0,0,0,0,0,0
	};
	int location{ map[karvedys.getXPos()][karvedys.getYPos()] }; // veikejo vieta
	while (direction != "atgal") {
		vandalai.setEsiCampe(); // semaforas
		Frankai.setEsiPily(); // semaforas
		Truviskes.setEsiKaime(); // semaforas
		std::cout << "--------------------------------------------------" << std::endl; //meniu
		std::cout << "Jusu vieta " << location << std::endl;
		std::cout << "Keliavimas!" << std::endl;
		std::cout << "Iveskite krypti (siaure, pietus , rytai, vakarai)" << std::endl;
		std::cout << "Jei norite grizti iveskite zodi: atgal" << std::endl;
		std::cout << "--------------------------------------------------" << std::endl;
		std::cin >> direction;
		std::cout << "--------------------------------------------------" << std::endl;
		if (direction == "siaure") { // kelione siauren
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
			else if (location == 2) {
				while (Truviskes.getEsiKaime()) {
					Truviskes.kaimasMenu();
				}
			}
			else if (location == 3) {
				while (Frankai.getEsiPily()) {
					Frankai.pilisMenu();
				}
			}
			else if (location == 4) {
				while (vandalai.getEsiCampe()) {
					vandalai.campMenu();
				}
			}
		}
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
			else if (location == 2) {
				while (Truviskes.getEsiKaime()) {
					Truviskes.kaimasMenu();
				}
			}
			else if (location == 3) {
				while (Frankai.getEsiPily()) {
					Frankai.pilisMenu();
				}
			}
			else if (location == 4) {
				while (vandalai.getEsiCampe()) {
					vandalai.campMenu();
				}
			}
		}
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
			else if (location == 2) {
				while (Truviskes.getEsiKaime()) {
					Truviskes.kaimasMenu();
				}
			}
			else if (location == 3) {
				while (Frankai.getEsiPily()) {
					Frankai.pilisMenu();
				}
			}
			else if (location == 4) {
				while (vandalai.getEsiCampe()) {
					vandalai.campMenu();
				}
			}
		}
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
			else if (location == 2) {
				while (Truviskes.getEsiKaime()) {
					Truviskes.kaimasMenu();
				}
			}
			else if (location == 3) {
				while (Frankai.getEsiPily()) {
					Frankai.pilisMenu();
				}
			}
			else if (location == 4) {
				while (vandalai.getEsiCampe()) {
					vandalai.campMenu();
				}
			}
		}
	}
}
