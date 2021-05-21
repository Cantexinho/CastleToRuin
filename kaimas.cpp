#include "kaimas.h"
//constructor
kaimas::kaimas() {

	this->esiKaime = true;
	this->esiPadruotuveje = true;
	this->choice = 0;
	this->kariai = 20;
	this->ginklai = 3;
	this->maistas = 42;
	this->auksiniai = 250;
}

//destructor
kaimas::~kaimas() {

}

//funkcijos
void kaimas::setEsiKaime() {
	esiKaime = true;
}

void kaimas::kaimasMenu() {
	pirklys.getEsiParduotuveje();
	std::cout << std::endl;
	std::cout << "Atvykote i kaima\n";
	std::cout << "-----------------\n";
	std::cout << "Kaimo Meniu\n";
	std::cout << "1. Parduotuve \n";
	std::cout << "2. Verbuoti karius \n";
	std::cout << "3. Reiduoti \n";
	std::cout << "0. Iseiti \n";

	std::cout << std::endl << "Pasirinkimas: ";
	std::cin >> choice;
	std::cout << std::endl;

	switch (choice) {
	case 0: //quit
		esiKaime = false;
		break;
	case 1: // parduotuve
		pirklys.menuParduotuve();
		break;
	case 2: // verbuoti karius
		std::cout << getKariai() << std::endl;
		break;
	case 3: // reiduoti
		break;
	default:
		std::cout << "Tokio pasirinkimo nera" << std::endl;
	}
}
