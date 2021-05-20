#pragma once

#include "inventory.h"


class character
{
private:
	int distanceTraveled;


	std::string name;
	int level;
	int exp;
	int expNext;
	int maistas;
	int kariai;
	int auksiniai;
	int ginklai;

public:
	character();
	~character();
	//Funkcijos

	void initialize(const std::string name);
	void printInfo() const;
	void levelUp();

	//Getters
	const std::string& getName() const { return this->name; }
	const int& getLevel() const { return this->level; }
	const int& getExp() const { return this->exp; }
	const int& getExpNext() const { return this->expNext; }
	const int& getMaistas() const { return this->maistas; }
	const int& getKariai() const { return this->kariai; }
	const int& getAuksiniai() const { return this->auksiniai; }
	const int& getGinklai() const { return this->ginklai; }

	//Setters



};

