//TCP CLIENT source file

#include "CLIENT connect.hh"
#include <list>

using namespace std;

struct Player {
	string name = "";
	int score = 0;
	bool a1 = false;
	bool a2 = false;
	bool a3 = false;
	bool a4 = false;
	bool a5 = false;
};

struct Result {
	int score = 0;
	string name = "EMPTY";
};

//GETTING NECESARY STARTUP DATA:
//Recieves playername, and modifies "Pacman.cc" player and ranking data structures
void GetData(string playername, Player &player, list<Result> &address_book)
{
	//Necesary variables:
	long SUCCESSFUL;
	WSAData WinSockData;
	WORD DLLVersion;
	DLLVersion = MAKEWORD(2, 1);
	SUCCESSFUL = WSAStartup(DLLVersion, &WinSockData);

	//Player struct constructing:
//	string CONVERTER; // <-- AQUI LLEGA EL MENSAJE!! XD
	char MESSAGE[200];

	SOCKADDR_IN ADDRESS;

	SOCKET sock;
	sock = socket(AF_INET, SOCK_STREAM, NULL);

	ADDRESS.sin_addr.s_addr = inet_addr("192.168.1.33");
	ADDRESS.sin_family = AF_INET;
	ADDRESS.sin_port = htons(444);

	connect(sock, (SOCKADDR*)&ADDRESS, sizeof(ADDRESS));



	SUCCESSFUL = recv(sock, MESSAGE, sizeof(MESSAGE), NULL);

	player.name = MESSAGE;
//	player.score = stoi(MESSAGE);

	cout << "\n\tRecieved from SERVER:\n\n\t" << player.name << endl;
}