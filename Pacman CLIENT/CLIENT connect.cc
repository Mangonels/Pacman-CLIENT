//TCP CLIENT source file

#include "CLIENT connect.hh"

using namespace std;

void GetData()
{
	//WINSOCK STARTUP:
	WSAData wsaData;
	WORD DllVersion = MAKEWORD(2, 1);
	if (WSAStartup(DllVersion, &wsaData) != 0) //WSAStartup should return 0, else, error.
	{
		MessageBoxA(NULL, "Winsock startup failed", "Error", MB_OK | MB_ICONERROR);
		exit(1);
	}

	//SOCKET ADDRESS INFORMATION:
	SOCKADDR_IN addr; //Address that we will bind our listening socket to
	int addrlen = sizeof(addr); //Address length
	addr.sin_addr.s_addr = inet_addr("192.168.1.33"); //IP a la que nos conectamos
	addr.sin_port = htons(1111); //PORT
	addr.sin_family = AF_INET; //IPv4 Socket

	//CREATING SOCKET:
	SOCKET Connection = socket(AF_INET, SOCK_STREAM, NULL); //Set connection socket
	if (connect(Connection, (SOCKADDR*)&addr, addrlen) != 0) //If we are unable to connect...
	{
		MessageBoxA(NULL, "Failed to Connect", "Error", MB_OK | MB_ICONERROR);
	}
	cout << "Connected!" << endl;
	
	//RECIEVING INFO:
	char MESSAGE[256];
	recv(Connection, MESSAGE, sizeof(MESSAGE), NULL); //Recieve message and place into MESSAGE array
	cout << "MESSAGE:" << MESSAGE << endl;
}