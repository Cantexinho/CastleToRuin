#pragma once

#include "character.h"
#include "functions.h"
#include <stdlib.h>
#include <windows.h>
#include <ctime>
#include "kelione.h"

class game{
private:
	int choice;
	bool playing;

public:
	game();
	~game();
	//character
	character karvedys;
	//kuprine
	inventory kuprine;
	//kelione
	kelione zygis;

	//Operators

	//Funkcijos
	void MainMenu();
	void initializeGame();


	//Getters
	bool getPlaying() const { return this->playing; }
	void printKuprine();
	//Setters

};

