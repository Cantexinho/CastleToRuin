#include "game.h"

//constructor
game::game() {
	this->choice = 0;
	this->playing = true;
}

//destructor
game::~game() {

}

//funkcijos
void game::initializeGame() {

	std::string name;
	std::cout << "Iveskite veikejo varda: " << std::endl;
	getline(std::cin, name);

	//kuprine.addItem(item("kardas"));
	//kuprine.addItem(item("lankas"));
	//kuprine.addItem(item("karuna"));
	//kuprine.addItem(item("batai"));

	//enemy baronas(rand()%10);
	//std::cout << baronas.getAsString() << std::endl;

	karvedys.initialize(name);
}


void game::MainMenu() {
	std::cout << std::endl;
	std::cout << "Main Menu\n";
	std::cout << "1. Keliauti \n";
	std::cout << "2. Inventorius \n";
	std::cout << "3. Lygis \n";
	std::cout << "4. Karvedzio informacija \n";
	std::cout << "0. Iseiti \n";

	std::cout << std::endl << "Pasirinkimas: ";
	std::cin >> choice;
	std::cout << std::endl;

	switch (choice) {
	case 0: //quit
		playing = false;
		break;
	case 1: //travel
		zygis.travel();
		break;
	case 2://inventory
		kuprine.printInv();
		break;
	case 3://levelup
		karvedys.levelUp();
		break;
	case 4://characterinfo
		karvedys.printInfo();
		break;
	default:
		break;

	}
}
