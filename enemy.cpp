#include "enemy.h"

//constructor
enemy::enemy(int level) {

	this->level = level;
	this->kariai = level*5/2;
	this->ginklai = level*3/2;
}

//destructor
enemy::~enemy() {

}

//funkcijos

std::string enemy::getAsString() const {
	return "level:" + std::to_string(this->level) + "\n" +
		"kariai:" + std::to_string(this->kariai) + "\n" +
		"ginklai:" + std::to_string(this->ginklai) + "\n";
}
