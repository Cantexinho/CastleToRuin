#include "banditai.h"

//constructor

banditai::banditai()
	: kariai{ 0 }, ginklai{ 0 }, maistas{ 0 }, auksiniai{ 0 }, pavadinimas{ "None" }{
}

banditai::banditai(int kariaiVal, int ginklaiVal, int maistasVal, int auksiniaiVal, std::string pavadinimasVal)
	: kariai{ kariaiVal }, ginklai{ ginklaiVal }, maistas{ maistasVal }, auksiniai{ auksiniaiVal }, pavadinimas{ pavadinimasVal }{
}

//banditai::banditai() {
//
//	this->kariai = 50;
//	this->ginklai = 17;
//	this->maistas = 70;
//	this->auksiniai = 500;
//	this->pavadinimas = "Vandalai";
//
//}

//destructor
banditai::~banditai() {

}

void banditai::printInfo() const {

	std::cout << "Banditu pavadinimas: " << this->pavadinimas << std::endl;
	std::cout << "Maistas: " << this->maistas << std::endl;
	std::cout << "Kariai: " << this->kariai << std::endl;
	std::cout << "Auksiniai: " << this->auksiniai << std::endl;
	std::cout << "Ginklai: " << this->ginklai << std::endl;

}

//funkcijos
void banditai::banditaiEjimas() {

	int roll{ rand() % 10 + 1 };
	if (roll < 4) {
		if (this->kariai < 100) {
			this->kariai += 2;
		}
		if (this->maistas < 100) {
			this->maistas += 1;
		}
		if (this->ginklai < 42) {
			this->ginklai += 1;
		}
		if (this->auksiniai < 550) {
			this->auksiniai += 1;
		}
	}
}

void banditai::setAuksas(int kiekis, int x) {
	this->auksiniai += kiekis * x;
}

void banditai::setGinklai(int kiekis) {
	this->ginklai += kiekis;
}
void banditai::setKariai(int kiekis) {
	this->kariai += kiekis;
}
void banditai::setMaistas(int kiekis) {
	this->maistas += kiekis;
}

void banditai::maistasPoMusio(int kiekis) {
	this->maistas = kiekis;
}

void banditai::auksasPoMusio(int kiekis) {
	this->auksiniai = kiekis;
}

void banditai::ginklaiPoMusio(int kiekis) {
	this->ginklai = kiekis;
}

void banditai::kariaiPoMusio(int kiekis) {

	if (kiekis < 0)
		kiekis = 0;
	this->kariai = kiekis;

}
//void banditai::campMenu() {
//	std::cout << std::endl;
//	std::cout << "Atvykote i banditu stovyklaviete\n";
//	std::cout << "-----------------\n";
//	std::cout << "Bandytu stovyklos Meniu\n";
//	std::cout << "1. Reiduoti \n";
//	std::cout << "0. Keliauti toliau \n";
//
//	std::cout << std::endl << "Pasirinkimas: ";
//	std::cin >> choice;
//	std::cout << std::endl;
//
//	switch (choice) {
//	case 0: //eiti toliau
//		esiCampe = false;
//		break;
//	case 1: //reiduoti
//		break;
//	default:
//		std::cout << "Tokio pasirinkimo nera" << std::endl;
//	}
//}
