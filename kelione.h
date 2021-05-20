#pragma once

#include "character.h"
#include "banditai.h"
#include "pilis.h"
#include "kaimas.h"
#include <iostream>


class kelione
{
private:
	int xPos;
	int yPos;

	kaimas Truviskes;
	pilis Frankai;
	banditai vandalai;

public:
	kelione();
	~kelione();

	const int& getXPos() const { return this->xPos; }
	const int& getYPos() const { return this->yPos; }

	//funkc
	void travel();
};

