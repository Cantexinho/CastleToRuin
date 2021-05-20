#include "banditai.h"

//constructor
banditai::banditai() {

	this->esiCampe = true;
	this->choice = 0;
	this->kariai = 50;
	this->ginklai = 17;
	this->maistas = 70;
	this->auksiniai = 500;
}

//destructor
banditai::~banditai() {

}

//funkcijos
void banditai::setEsiCampe() {
	esiCampe = true;
}

void banditai::campMenu() {
	std::cout << std::endl;
	std::cout << "Atvykote i banditu stovyklaviete\n";
	std::cout << "-----------------\n";
	std::cout << "Bandytu stovyklos Meniu\n";
	std::cout << "1. Reiduoti \n";
	std::cout << "0. Keliauti toliau \n";

	std::cout << std::endl << "Pasirinkimas: ";
	std::cin >> choice;
	std::cout << std::endl;

	switch (choice) {
	case 0: //eiti toliau
		esiCampe = false;
		break;
	case 1: //reiduoti
		break;
	default:
		std::cout << "Tokio pasirinkimo nera" << std::endl;
	}
}
