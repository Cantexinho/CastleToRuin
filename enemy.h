#pragma once

#include "character.h"
#include <stdlib.h>
#include <string>

class enemy {
private:

	int level;
	int kariai;
	int ginklai;

public:

	enemy(int level=0);
	~enemy();
	//Funkcijos
	inline void takeDmg(int damage) { this->kariai -= damage; };
	inline int getExp()const { return this->level * 33; }; // xp uz enemy
	
	//Getters
	inline bool hasTroops() { return this->kariai > 0; }
	std::string getAsString() const; // info apie enemy
	inline int getDmg()const { return rand() % this->kariai + this->ginklai; }; // enemy dmg


	//Setters
};