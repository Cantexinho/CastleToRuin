#include "pilis.h"

//constructor
pilis::pilis() {

	this->esiPily = true;
	this->choice = 0;
	this->kariai = 150;
	this->ginklai = 100;
	this->maistas = 200;
	this->auksiniai = 2000;

}

//destructor
pilis::~pilis() {

}

//funkcijos
void pilis::setEsiPily() {
	esiPily = true;
}

void pilis::pilisMenu() {

	std::cout << std::endl;
	std::cout << "Atvykote i pili\n";
	std::cout << "-----------------\n";
	std::cout << "Pilies Meniu\n";
	std::cout << "1. Parduotuve \n";
	std::cout << "2. Verbuoti karius \n";
	std::cout << "3. Uzkariauti \n";
	std::cout << "0. Iseiti \n";

	std::cout << std::endl << "Pasirinkimas: ";
	std::cin >> choice;
	std::cout << std::endl;

	switch (choice) {
	case 0: //quit
		esiPily = false;
		break;
	case 1: // parduotuve
		maxima.menuParduotuve();
		break;
	case 2: // verbuoti karius
		break;
	case 3: // reiduoti
		break;
	default:
		std::cout << "Tokio pasirinkimo nera" << std::endl;
	}

}
