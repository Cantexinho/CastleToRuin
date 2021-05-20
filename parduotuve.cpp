#include "parduotuve.h"

parduotuve::parduotuve() {

	this->choice=0;
	this->esiParduotuveje=true;
	this->maistas=0;
	this->ginklai=0;

}
parduotuve::~parduotuve() {


}

//funkc
void parduotuve::setEsiParduotuveje() {
	esiParduotuveje = true;
}


void parduotuve::menuParduotuve() {
	std::cout << std::endl;
	std::cout << "Parduotuve\n";
	std::cout << "-----------------\n";
	std::cout << "1. Pirkti \n";
	std::cout << "2. Parduoti \n";
	std::cout << "0. Iseiti \n";
	std::cout << "-----------------\n";
	std::cout << std::endl << "Pasirinkimas: ";
	std::cin >> choice;
	std::cout << std::endl;

	switch (choice) {
	case 0: //quit
		esiParduotuveje = false;
		break;
	case 1: // pirkti
		std::cout << "Ka norite pirkti\n";
		std::cout << "-----------------\n";
		std::cout << "1. Maista \n";
		std::cout << "2. Ginklus \n";
		std::cout << "0. Iseiti \n";
		std::cout << "-----------------\n";
		std::cout << std::endl << "Pasirinkimas: ";
		std::cin >> choice;
		std::cout << std::endl;
		if (choice == 1) {
			std::cout << "Nusipirkote maisto" << std::endl;
		}
		else if (choice == 2) {
			std::cout << "Nusipirkote ginklu" << std::endl;
		}
		else if (choice == 0) {
			break;
		}
		break;
	case 2: // parduoti
		std::cout << "Ka norite parduoti\n";
		std::cout << "-----------------\n";
		kuprine.printInv();
		std::cout << "-----------------\n";
		std::cout << std::endl << "Pasirinkimas: ";
		std::cin >> choice;
		std::cout << std::endl;
		if (choice == 1) {
			std::cout << "Pardavete" << std::endl;
		}
		else if (choice == 2) {
			std::cout << "Pardavete" << std::endl;
		}
		else if (choice == 0) {
			break;
		}
		break;
	default:
		std::cout << "Tokio pasirinkimo nera" << std::endl;
	}
}