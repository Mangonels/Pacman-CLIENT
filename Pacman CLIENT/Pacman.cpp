#include <iostream>
#include <list>
#include <string>
#include "pacman.hh"
using namespace std;


enum gameStates { MENU, PLAY, RANKING, PERSONALBEST, ACHIEVMENTS, LEAVE }; //Estats en els quals es pot trobar el joc
gameStates currentGameState = MENU; //Estat actual del joc, marca en quina escena ens trobem

struct Result {
	int score = 0;
	string name = "EMPTY";
};

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
		currentGameState = ACHIEVMENTS;
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

void achievements(bool a1, bool a2, bool a3, bool a4, bool a5) //Funcio que actua com a escena achievments
{
	cout << "No fer cap punt i morir: " << a1 << "\n";
	cout << "Aconseguir 50 punts: " << a2 << "\n";
	cout << "Aconseguir 100 punts: " << a3 << "\n";
	cout << "Sobreviure mig minut en una partida: " << a4 << "\n";
	cout << "Sobreviure 1 minut en una partida: " << a5 << "\n";
	cout << "\n\n\nPress any key to go back";
	system("pause>NULL");
	currentGameState = MENU;
}


int main() {
	int score = 0;
	bool a1 = false;
	bool a2 = false;
	bool a3 = false;
	bool a4 = false;
	bool a5 = false;

	list<Result> ranking;
	ranking.resize(10);

	for (;;) {
		switch (currentGameState) //Bootleg "Scene Manager" xD
		{
		case MENU:
			system("cls");
			menu();
			break;
		case PLAY:
			system("cls");
			play();
			break;
		case RANKING:
			system("cls");
			rankings(ranking);
			break;
		case PERSONALBEST:
			system("cls");
			personalbest(score);
			break;
		case ACHIEVMENTS:
			system("cls");
			achievements(a1,a2,a3,a4,a5);
			break;
		case LEAVE:
			exit(0);
		}
	}

	system("pause>NULL");
	return 0;

}