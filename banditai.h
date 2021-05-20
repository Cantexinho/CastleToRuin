#pragma once

#include "character.h"
#include <string>
#include <iostream>

class banditai
{
private:

	int esiCampe;
	int choice;
	int kariai;
	int ginklai;
	int maistas;
	int auksiniai;


public:

	banditai();
	~banditai();

	//Funkcijos
	void campMenu();
	//Getters
	bool getEsiCampe() const { return this->esiCampe; }

	//Setters
	void setEsiCampe();
};

