#include "kelione.h"

kelione::kelione() {

	this->xPos=1;
	this->yPos=1;
}

kelione::~kelione() {

}
void kelione::travel() {
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
	int location{ map[xPos][yPos] };
	while (direction != "atgal") {
		vandalai.setEsiCampe();
		Frankai.setEsiPily();
		Truviskes.setEsiKaime();
		std::cout << "--------------------------------------------------" << std::endl;
		std::cout << "Iveskite krypti (siaure, pietus , rytai, vakarai)" << std::endl;
		std::cout << "Jei norite grizti iveskite zodi: atgal" << std::endl;
		std::cout << "--------------------------------------------------" << std::endl;
		std::cin >> direction;
		std::cout << "--------------------------------------------------" << std::endl;
		if (direction == "siaure") {
			location = map[--xPos][yPos];
			if (location == 0) {
				std::cout << "Pasiekete siaures asigali ir privalote grizti" << std::endl;
				location = map[++xPos][yPos];
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
			location = map[++xPos][yPos];
			if (location == 0) {
				std::cout << "Pasiekete dykuma ir privalote grizti" << std::endl;
				location = map[--xPos][yPos];
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
			location = map[xPos][++yPos];
			if (location == 0) {
				std::cout << "Pasiekete kalnus ir privalote grizti" << std::endl;
				location = map[xPos][--yPos];
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
			location = map[xPos][--yPos];
			if (location == 0) {
				std::cout << "Pasiekete jura ir privalote grizti" << std::endl;
				location = map[xPos][++yPos];
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
