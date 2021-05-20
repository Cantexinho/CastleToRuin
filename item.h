#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

class item {
private:
	std::string name;
	int buyValue;
	int sellValue;
	int level;


public:
	item(std::string name = "None", int level = 0,
		int buyValue = 0, int selValue = 0);
	~item();

	//Funkcijos

	//Getters

	inline const std::string& getName() const { return this->name; }
	inline const int& getLevel() const { return this->level; }
	inline const int& getBuyValue() const { return this->buyValue; }
	inline const int& getSellValue() const { return this->sellValue; }

 	inline std::string printInv()const{
		return this->name;
	}

	//Setters

};

