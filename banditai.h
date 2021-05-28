#pragma once

#include "character.h"
#include <string>
#include <iostream>

class banditai
{
private:

	std::string pavadinimas;
	int kariai;
	int ginklai;
	int maistas;
	int auksiniai;


public:

	banditai();
	banditai(int kariaiVal, int ginklaiVal, int maistasVal, int auksiniaiVal, std::string pavadinimasVal);

	~banditai();

	//Funkcijos
	void banditaiEjimas();
	//Getters
	const int& getMaistas() const { return this->maistas; }
	const int& getKariai() const { return this->kariai; }
	const int& getAuksiniai() const { return this->auksiniai; }
	const int& getGinklai() const { return this->ginklai; }
	void printInfo() const;
	//Setters
	void setKariai(int);
	void setMaistas(int);
	void setGinklai(int);
	void setAuksas(int kiekis, int x);
	void kariaiPoMusio(int);
	void ginklaiPoMusio(int);
	void auksasPoMusio(int);
	void maistasPoMusio(int);
};

