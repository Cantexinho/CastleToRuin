#pragma once

#include "character.h"
#include <string>
#include <iostream>

class parduotuve
{
private:

	int choice;
	bool esiParduotuveje;
	int maistas;
	int ginklai;
	inventory kuprine;

public:

	parduotuve();
	~parduotuve();

	//funkc
	void menuParduotuve();

	//getters
	bool getEsiParduotuveje() const { return this->esiParduotuveje; }

	//setters
	void setEsiParduotuveje();

};

