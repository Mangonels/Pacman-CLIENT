#include <iostream>
#include <list>
#include <string>
#include "pacman.hh"
using namespace std;


void menu() //Funcio que actua com a escena menu
{
	int menuSelection;
	cout << "	   	    _______  _______  _______         __   __  _______  __    _ " << endl;
	cout << "		   |       ||   _   ||       |       |  |_|  ||   _   ||  |  | |" << endl;
	cout << "		   |    _  ||  |_|  ||       | ____  |       ||  |_|  ||   |_| |" << endl;
	cout << "		   |   |_| ||       ||       ||____| |       ||       ||       |" << endl;
	cout << "		   |    ___||       ||      _|       |       ||       ||  _    |" << endl;
	cout << "		   |   |    |   _   ||     |_        | ||_|| ||   _   || | |   |" << endl;
	cout << "		   |___|    |__| |__||_______|       |_|   |_||__| |__||_|  |__|" << endl;
	cout << "\n			           Per Daniel Peco i Dylan Calaf			             \n" << endl;

	cout << "			                     - MENU -" << endl;
	cout << "1 - Jugar" << endl;
	cout << "2 - Consultar Rànking" << endl;
	cout << "3 - Consultar millors puntuacions" << endl;
	cout << "4 - Consultar Achievements" << endl;
	cout << "5 - Sortir" << endl;

	cout << "\nIntrodueix numero:" << endl;

	cin >> menuSelection;

	switch (menuSelection)
	{
	case 1:
		currentGameState = PLAY;
		break;
	case 2:
		currentGameState = RANKING;
		break;
	case 3:
		currentGameState = PERSONALBEST;
		break;
	case 4:
		currentGameState = ACHIEVEMENTS;
		break;
	case 5:
		currentGameState = LEAVE;
		break;
	}
}


void rankings(list<Result> ranking) //Funcio que actua com a escena ranking
{
	std::cout << "TOP 10 idiots:\n\n";

	int i = 1;
	for (list<Result>::const_iterator iterator = ranking.begin(); iterator != ranking.end(); ++iterator) {
		cout << "#" << i << ": " << iterator->name << " " << iterator->score << "\n";
		i++;
	}

	cout << "\n\n\nPress any key to go back";
	system("pause>NULL");
	currentGameState = MENU;
}

void personalbest(int score) //Funcio que actua com a escena millors resultats personals
{
	cout << "Your personal best is: " << score;
	cout << "\n\n\nPress any key to go back";
	system("pause>NULL");
	currentGameState = MENU;
}

void achievements(Player player) //Funcio que actua com a escena achievments
{
	cout << "No fer cap punt i morir: " << player.a1 << "\n";
	cout << "Aconseguir 50 punts: " << player.a2 << "\n";
	cout << "Aconseguir 100 punts: " << player.a3 << "\n";
	cout << "Sobreviure mig minut en una partida: " << player.a4 << "\n";
	cout << "Sobreviure 1 minut en una partida: " << player.a5 << "\n";
	cout << "\n\n\nPress any key to go back";
	system("pause>NULL");
	currentGameState = MENU;
}

int main() {
	bool isRunning = true;
	Player player;

	list<Result> ranking;
	ranking.resize(10);

	std::cout << "Please, enter your user name: ";
	cin >> player.name;

	//aqui va lo de conectar con el servidor y esas cosas

		while (isRunning) {
		switch (currentGameState) //Bootleg "Scene Manager" xD
		{
		case MENU:
			system("cls");
			menu();
			break;
		case PLAY:
			system("cls");
			player = play(player);
			break;
		case RANKING:
			system("cls");
			rankings(ranking);
			break;
		case PERSONALBEST:
			system("cls");
			personalbest(player.score);
			break;
		case ACHIEVEMENTS:
			system("cls");
			achievements(player);
			break;
		case LEAVE:
			isRunning = false;
		}
	}
	return 0;
}