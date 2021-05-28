#include "game.h"

kaimas Truviskes;
pilis Frankai;
banditai vandalai;

int main() {

    srand(time(NULL));
    system("cls");
    std::cout << "Castle\n";
    Sleep(800);
    system("cls");
    std::cout << "Castle To\n";
    Sleep(800);
    system("cls");
    std::cout << "Castle To Ruin\n";
    Sleep(800);
    system("cls");

    game Game;
    Game.initializeGame();

    while (Game.getPlaying()) {

        Game.MainMenu();

    }

	return 0;
}