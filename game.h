#pragma once

#include "character.h"
#include "banditai.h"
#include "pilis.h"
#include "kaimas.h"
#include <stdlib.h>
#include <windows.h>
#include <ctime>

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
	//kaimai
	kaimas Truviskes;
	//pilys
	pilis Frankai;
	//banditu stovyklos
	banditai vandalai;

	//Operators

	//Funkcijos
	void MainMenu();
	void initializeGame();
	void travel();


	//Getters
	bool getPlaying() const { return this->playing; }
	void printKuprine();
	//Setters

};

