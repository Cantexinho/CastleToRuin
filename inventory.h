#pragma once

#include "item.h"

class inventory {
private:
	int capacity;
	int nrOfItems;
	item** itemArray;
	void initialize(const int from = 0);
	void expand();


public:
	inventory();
	~inventory();
	//Funkcijos
	void addItem(const item& Item);
	void removeItem(int index);

	//Getters
	void printInv();
	//Setters

};


