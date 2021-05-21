#pragma once

#include <string>
#include <iostream>
#include "character.h"
#include "parduotuve.h"

class kaimas {
private:

	bool esiKaime;
	bool esiPadruotuveje;
	int choice;
	int kariai;
	int ginklai;
	int maistas;
	int auksiniai;
	parduotuve pirklys;

public:

	kaimas();
	~kaimas();

	//Funkcijos
	void kaimasMenu();
	//Getters
	inline bool kiekKariu() { return this->kariai > 0; }
	std::string getAsString() const;
	bool getEsiKaime() const { return this->esiKaime; }
	const int& getMaistas() const { return this->maistas; }
	const int& getKariai() const { return this->kariai; }
	const int& getAuksiniai() const { return this->auksiniai; }
	const int& getGinklai() const { return this->ginklai; }


	//Setters
	void setEsiKaime();
};



