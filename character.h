#pragma once

#include "inventory.h"
#include <windows.h>


class character
{
private:
	int distanceTraveled;
	int xPos;
	int yPos;


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
	void ejimas();

	//Getters
	const int& getXPos() const { return this->xPos; }
	const int& getYPos() const { return this->yPos; }
	const std::string& getName() const { return this->name; }
	const int& getLevel() const { return this->level; }
	const int& getExp() const { return this->exp; }
	const int& getExpNext() const { return this->expNext; }
	const int& getMaistas() const { return this->maistas; }
	const int& getKariai() const { return this->kariai; }
	const int& getAuksiniai() const { return this->auksiniai; }
	const int& getGinklai() const { return this->ginklai; }

	//Setters
	void setKariai(int kariuKiekis);
	void setMaistas(int maistoKiekis);
	void setGinklai(int ginkluKiekis);
	void setExp(int kiekis, int x);
	//void parduotMaista(int maistoKiekis);
	void parduotiGinklus(int maistoKiekis);
	void setAuksiniai(int kiekis, int x);
	//set x position
	void setNorthXpos();
	void setSouthXpos();
	//set y position
	void setEastYpos();
	void setWestYpos();

};

