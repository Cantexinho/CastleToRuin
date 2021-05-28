#include "pilis.h"

//constructor

pilis::pilis()
	: kariai{ 0 }, ginklai{ 0 }, maistas{ 0 }, auksiniai{ 0 }, pavadinimas{ "None" }{
}

pilis::pilis(int kariaiVal, int ginklaiVal, int maistasVal, int auksiniaiVal, std::string pavadinimasVal, int verbuotKariaiVal, int pirktGinklaiVal)
	: kariai{ kariaiVal }, ginklai{ ginklaiVal }, maistas{ maistasVal }, auksiniai{ auksiniaiVal }, pavadinimas{ pavadinimasVal }, verbuotKariai{ verbuotKariaiVal }, pirktGinklai{ pirktGinklaiVal }{
}

//pilis::pilis() {
//
//	this->kariai = 150;
//	this->ginklai = 100;
//	this->maistas = 200;
//	this->auksiniai = 2000;
//	this->pavadinimas = " ";
//
//}

//destructor
pilis::~pilis() {

}

//funkcijos

void pilis::pilisEjimas() {

	int roll{ rand() % 10 + 1 };
	if (roll < 4) {
		if (this->kariai < 1000) {
			this->kariai += roll;
		}
		if (this->maistas < 500) {
			this->maistas += roll;
		}
		if (this->ginklai < 200) {
			this->ginklai += roll;
		}
		if (this->auksiniai < 5000) {
			this->auksiniai += 2;
		}
		if (this->pirktGinklai < 25) {
			this->pirktGinklai += 1;
		}
		if (this->verbuotKariai < 50) {
			this->verbuotKariai += 1;
		}
	}
}

void pilis::printInfo() const {

	std::cout << "Pilies pavadinimas: " << this->pavadinimas << std::endl;
	std::cout << "Maistas: " << this->maistas << std::endl;
	std::cout << "Kariai: " << this->kariai << std::endl;
	std::cout << "Auksiniai: " << this->auksiniai << std::endl;
	std::cout << "Ginklai: " << this->ginklai << std::endl;

}

void pilis::setPirktGinklai(int kiekis) {
	this->pirktGinklai += kiekis;
}

void pilis::setVerbuotKariai(int kiekis) {
	this->verbuotKariai += kiekis;
}


void pilis::setAuksas(int kiekis, int x) {
	this->auksiniai += kiekis * x;
}

void pilis::setGinklai(int kiekis) {
	this->ginklai += kiekis;
}
void pilis::setKariai(int kiekis) {
	this->kariai += kiekis;
}
void pilis::setMaistas(int kiekis) {
	this->maistas += kiekis;
}

void pilis::maistasPoMusio(int kiekis) {
	this->maistas = kiekis;
}

void pilis::auksasPoMusio(int kiekis) {
	this->auksiniai = kiekis;
}

void pilis::ginklaiPoMusio(int kiekis) {
	this->ginklai = kiekis;
}

void pilis::kariaiPoMusio(int kiekis) {

	if (kiekis < 0)
		kiekis = 0;
	this->kariai = kiekis;

}

//void pilis::pilisMenu() {
//
//	std::cout << std::endl;
//	std::cout << "Atvykote i pili\n";
//	std::cout << "-----------------\n";
//	std::cout << "Pilies Meniu\n";
//	std::cout << "1. Parduotuve \n";
//	std::cout << "2. Verbuoti karius \n";
//	std::cout << "3. Uzkariauti \n";
//	std::cout << "0. Iseiti \n";
//
//	std::cout << std::endl << "Pasirinkimas: ";
//	std::cin >> choice;
//	std::cout << std::endl;
//
//	switch (choice) {
//	case 0: //quit
//		esiPily = false;
//		break;
//	case 1: // parduotuve
//		maxima.menuParduotuve();
//		break;
//	case 2: // verbuoti karius
//		break;
//	case 3: // reiduoti
//		break;
//	default:
//		std::cout << "Tokio pasirinkimo nera" << std::endl;
//	}
//
//}
