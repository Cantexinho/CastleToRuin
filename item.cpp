#include "item.h"

//constructor
item::item(std::string name, int buyValue, int sellValue, int level) {

	this->name = name;
	this->buyValue = buyValue;
	this->sellValue = sellValue;
	this->level = level;
}

//destructor
item::~item() {

}

//funkcijos
