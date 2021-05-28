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
	int pasirinkimasMenu;
	int pasirinkParduotuve;
	int pasirinkParduot;
	int pasirinkPirkt;
	


public:
	game();
	~game();
	//character
	character karvedys;
	//kuprine
	inventory kuprine;
	//kaimai
	kaimas Truviskes{ 20, 3, 42, 10, "Truviskes", 5 , 1 }; // 20
	kaimas Barteliskes{ 30, 15, 60, 25, "Barteliskes", 7, 2 }; // 21
	kaimas Teviskes{ 20, 7, 50, 20, "Tevikses" , 3, 3 }; // 22
	kaimas Triogalai{ 25, 2, 40, 12, "Triogalai", 5, 0 }; // 23
	kaimas Turipai{ 40, 15, 70, 33, "Turipai", 10, 3}; // 24
	kaimas Karoliskes{ 55, 20, 100, 77, "Karoliskes", 15, 5 }; // 25
	kaimas Pakalniskes{ 60, 22, 100, 42, "Pakalniskes" , 12, 8 }; // 26
	kaimas Genininkai{ 42, 33, 80, 100, "Genininkai" , 20, 10}; //27
	kaimas Ariogala{ 30, 5, 30, 10, "Ariogal" , 5 , 0}; //28
	kaimas Zemzeniai{ 12, 1, 15, 2, "Zemzeniai", 2, 0 };//29
	kaimas Dumbirdai{ 25, 7, 35, 40, "Dumbirdai", 10, 3 };//210
	kaimas Likoniai{ 42, 30, 100, 200, "Likoniai", 19, 5 }; //211
	kaimas Ceckes{ 17, 5, 27, 20, "Ceckes" , 5, 2 };//212
	kaimas Grazdionys{ 70, 33, 150, 100, "Grazdionys", 20, 10 }; // 213
	kaimas Programintai{ 50, 25, 100, 33, "Programintai" , 10, 7 }; //214
	//pilys
	pilis Frankite{ 350, 250, 400, 10000, "Frankite", 50, 20 }; //30
	pilis Germanite{ 550, 350, 600, 15000, "Germanite", 70, 35 }; //31
	pilis Svedite{ 250, 150, 300, 7000, "Svedite" , 30, 10 }; //32
	pilis Italiano{ 650, 450, 800, 20000, "Italiano", 42, 33 };//33
	pilis Galiano{ 750, 120, 800, 6000, "Galiano", 70, 10 };//34
	pilis Vikingaites{ 450, 450, 450, 8000, "Vikingaites", 50, 25 };//35
	pilis Lituanica{ 1000, 500, 2000, 2000, "Lituanica", 100, 25 };//36
	pilis Zemaiteskai{ 700, 700, 800, 7000, "Zemaiteskai", 70, 70 };//37
	pilis Ruskiai{ 1500, 10, 800, 1000, "Ruskiai" , 120, 5 };//38
	pilis Otomanijai{ 1000, 450, 10000, 20000, "Otomanijai", 100, 50 };//39

	//banditai
	banditai Vandalai{ 50, 17, 70, 500, "Vandalai" };//40
	banditai Daktarai{ 100, 70, 100, 1000, "Daktarai" };//41
	banditai Tulpiniai{ 80, 42, 120, 900, "Tulpiniai" };//42
	banditai Princai{ 52, 40, 70, 1200, "Princai" };//43
	banditai Daskiniai{ 120, 50, 200, 1500, "Daskiniai" };//44
	banditai Caponiai{ 150, 80, 180, 2000, "Caponiai" };//45
	banditai Vutangai{ 42, 42, 70, 880, "Vutangai" };//46
	banditai Kursiai{ 77, 77, 177, 500, "Kursiai" };//47
	banditai Garbetroskos{ 99, 11, 150, 3500, "Garbetroskos" };//48
	banditai Kobros{ 10, 1, 70, 100, "Kobros" };//49

	//Operators

	//Funkcijos
	void MainMenu();
	void initializeGame();
	void travel();
	void parduotuveMenu(int);
	void kaimasMenu(int);
	void pilisMenu(int);
	void banditMenu(int);
	int battle(int priesai, int ginklai, double multiplier);
	void ejimas();
	//void poMusio(banditai);


	//Getters
	bool getPlaying() const { return this->playing; }
	//Setters

};

