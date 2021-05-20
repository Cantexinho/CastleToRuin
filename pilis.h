#pragma once

#include "character.h"
#include "parduotuve.h"
#include <string>
#include <iostream>

class pilis {
private:

	int esiPily;
	int choice;
	int kariai;
	int ginklai;
	int maistas;
	int auksiniai;
	parduotuve maxima;


public:

	pilis();
	~pilis();

	//Funkcijos
	void pilisMenu();
	//Getters
	bool getEsiPily() const { return this->esiPily; }

	//Setters
	void setEsiPily();
};



