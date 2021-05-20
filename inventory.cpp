#include "inventory.h"

//constructor
inventory::inventory() {

	this->capacity = 5;
	this->nrOfItems = 0;
	this->itemArray = new item* [capacity];
	this->initialize();
}

//destructor
inventory::~inventory() {

	for (size_t i = 0; i < this->nrOfItems; i++){
		delete this->itemArray[i];
	}
	delete[] itemArray;
}

//funkcijos
void inventory::initialize(const int from) {

	for (size_t i = from; i < this->capacity; i++) {
		this->itemArray[i] = nullptr;
	}

}

void inventory::expand() {

	this->capacity *= 2;
	item** tempArr = new item * [this->capacity];

	for (size_t i{ 0 }; i < this->nrOfItems; i++) {
		tempArr[i] = new item(*this->itemArray[i]);
	}
	for (size_t i{ 0 }; i < this->nrOfItems; i++) {
		delete this->itemArray[i];
	}
	delete[] this->itemArray;

	this->itemArray = tempArr;

	this->initialize(this->nrOfItems);
}

void inventory::addItem(const item& Item) {

	if (this->nrOfItems >= this->capacity) {
		expand();
	}
	this->itemArray[this->nrOfItems++] = new item(Item);
}

void inventory::removeItem(int index) {

}

void inventory::printInv() {
	if (this->nrOfItems > 0) {
		for (size_t i = 0; i < this->nrOfItems; i++){
			std::cout << this->itemArray[i]->printInv() << std::endl;
		}
	}
	else{
		std::cout << "Inventorius tuscias" << std::endl;
	}
}