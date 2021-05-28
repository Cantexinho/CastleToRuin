#include "character.h"

//constructor

character::character() {

	this->distanceTraveled = 0;
	this->xPos = 0;
	this->yPos = 0;
	this->name = " ";
	this->level = 0;
	this->exp = 0;
	this->expNext = 0;
	this->maistas = 0;
	this->kariai = 0;
	this->auksiniai = 0;
	this->ginklai = 0;

}
//destructor
character::~character() {

}

//funkcijos

void character::ejimas() {

	this->maistas -= static_cast<int>(kariai / 10);
	this->auksiniai -= static_cast<int>(kariai / 10);

}

void character::initialize(std::string name) {

	this->distanceTraveled = 0;
	this->xPos = 1;
	this->yPos = 1;

	this->name = name;
	this->level = 1;
	this->exp = 10000;
	this->expNext = static_cast <int>
		((50 * pow(level, 3)) -
			(150 * pow(level, 2)) +
			(400 * level)) / 3;
	this->maistas = 1000;
	this->kariai = 300;
	this->auksiniai = 10000;
	this->ginklai = 300;

}


void character::printInfo() const {

	std::cout << "*************************" << std::endl;
	std::cout << "Karvedzio informacija: " << std::endl;
	std::cout << "Vardas: " << this->name << std::endl;
	std::cout << "Lygis: " << this->level << std::endl;
	std::cout << "Patirties taskai: " << this->exp << std::endl;
	std::cout << "Patirties taskai iki kito lygio: " << this->expNext - this->exp << std::endl;
	std::cout << "*************************" << std::endl;
	std::cout << "Maistas: " << this->maistas << std::endl;
	std::cout << "Kariai: " << this->kariai << std::endl;
	std::cout << "Auksiniai: " << this->auksiniai << std::endl;
	std::cout << "Ginklai: " << this->ginklai << std::endl;
	std::cout << "*************************" << std::endl;

}

void character::levelUp() {
	if (this->exp < this->expNext) {
		std::cout << "Neturite pakankamai patirties tasku pasikelti lygi" << std::endl;
	}
	else {
		while (this->exp >= this->expNext) {
			this->exp -= this->expNext;
			std::cout << "Pasiekete: " << level + 1 << " lygi!" << std::endl;
			std::cout << "Jusu pasiekimai pritrauke kariu: " << level * 3 / 2  << std::endl;
			std::cout << "Nauji kariai su savimi atsinese ginklu: " << level + 2  << std::endl;
			this->kariai += this->level * 3 / 2;
			this->ginklai += this->level + 2;
			level++;
			this->expNext = static_cast <int>
				((50 * pow(level, 3)) -
					(150 * pow(level, 2)) +
					(400 * level)) / 3;
			Sleep(100);
		}
	}
	Sleep(2000);
	system("cls");
}

void character::setExp(int kiekis, int x) {

	this->exp += kiekis*x;

}

void character::setMaistas(int maistoKiekis) {

	this->maistas += maistoKiekis;

}
void character::setAuksiniai(int kiekis, int x) {

	this->auksiniai += kiekis * x;

}

void character::parduotiGinklus(int ginkluKiekis) {

	this->ginklai -= ginkluKiekis;
	this->auksiniai += ginkluKiekis * 3;

}
void character::setGinklai(int ginkluKiekis) {

	this->ginklai += ginkluKiekis;

}

void character::setKariai(int kariuKiekis) {

	this->kariai += kariuKiekis;

}

//void character::pirktiMaista(int maistoKiekis) {
//
//	this->maistas += maistoKiekis;
//
//}

void character::setNorthXpos() {
	--xPos;
}
void character::setSouthXpos() {
	++xPos;
}
void character::setEastYpos() {
	++yPos;
}
void character::setWestYpos() {
	--yPos;
}