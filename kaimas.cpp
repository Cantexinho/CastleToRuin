#include "kaimas.h"
//constructor

kaimas::kaimas ()
	: kariai{ 0 }, ginklai{ 0 }, maistas{ 0 }, auksiniai{ 0 }, pavadinimas{ "None" }{
}

kaimas::kaimas (int kariaiVal, int ginklaiVal, int maistasVal, int auksiniaiVal, std::string pavadinimasVal, int verbuotKariaiVal, int pirktGinklaiVal)
	: kariai{ kariaiVal }, ginklai{ ginklaiVal }, maistas{ maistasVal }, auksiniai{ auksiniaiVal }, pavadinimas{ pavadinimasVal }, verbuotKariai{ verbuotKariaiVal }, pirktGinklai{ pirktGinklaiVal }{
}

//destructor
kaimas::~kaimas() {

}

//funkcijos
void kaimas::kaimasEjimas() {

	int roll{ rand() % 10 + 1 };
	if (roll < 5) {
		if (this->kariai < 50) {
			this->kariai += 1;
		}
		if (this->maistas < 50) {
			this->maistas += 1;
		}
		if (this->ginklai < 10) {
			this->ginklai += 1;
		}
		if (this->auksiniai < 120) {
			this->auksiniai += 1;
		}
		if (this->pirktGinklai < 3) {
			this->pirktGinklai += 1;
		}
		if (this->verbuotKariai < 10) {
			this->verbuotKariai += 1;
		}
	}
}

void kaimas::printInfo() const {

	std::cout << "Kaimo pavadinimas: " << this-> pavadinimas << std::endl;
	std::cout << "Maistas: " << this->maistas << std::endl;
	std::cout << "Kariai: " << this->kariai << std::endl;
	std::cout << "Auksiniai: " << this->auksiniai << std::endl;
	std::cout << "Ginklai: " << this->ginklai << std::endl;

}

void kaimas::setPirktGinklai(int kiekis) {
	this->pirktGinklai += kiekis;
}

void kaimas::setVerbuotKariai(int kiekis) {
	this->verbuotKariai += kiekis;
}

void kaimas::setAuksas(int kiekis, int x) {
	this-> auksiniai += kiekis*x;
}

void kaimas::setGinklai(int kiekis) {
	this->ginklai += kiekis;
}
void kaimas::setKariai(int kiekis){
	this->kariai += kiekis;
}
void kaimas::setMaistas(int kiekis) {
	this->maistas += kiekis;
}

void kaimas::maistasPoMusio(int kiekis) {
	this->maistas = kiekis;
}

void kaimas::auksasPoMusio(int kiekis) {
	this->auksiniai = kiekis;
}

void kaimas::ginklaiPoMusio(int kiekis) {
	this->ginklai = kiekis;
}

void kaimas::kariaiPoMusio(int kiekis) {

	if (kiekis < 0)
		kiekis = 0;
	this->kariai = kiekis;

}