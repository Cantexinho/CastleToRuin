#pragma once

#include "character.h"
#include <string>
#include <iostream>

class pilis {
private:

	int kariai;
	int ginklai;
	int maistas;
	int auksiniai;
	std::string pavadinimas;
	int verbuotKariai;
	int pirktGinklai;



public:

	pilis();
	pilis(int kariaiVal, int ginklaiVal, int maistasVal, int auksiniaiVal, std::string pavadinimasVal, int verbuotKariaiVal, int pirktGinklaiVal);

	~pilis();

	//Funkcijos
	void pilisEjimas();
	//Getters
	const int& getMaistas() const { return this->maistas; }
	const int& getKariai() const { return this->kariai; }
	const int& getAuksiniai() const { return this->auksiniai; }
	const int& getGinklai() const { return this->ginklai; }
	const int& getPirktGinklai() const { return this->pirktGinklai; }
	const int& getVerbuotKariai() const { return this->verbuotKariai; }
	void printInfo() const;

	//Setters
	void setPirktGinklai(int);
	void setVerbuotKariai(int);
	void setKariai(int);
	void setMaistas(int);
	void setGinklai(int);
	void setAuksas(int kiekis, int x);
	void kariaiPoMusio(int);
	void auksasPoMusio(int);
	void maistasPoMusio(int);
	void ginklaiPoMusio(int);
};



