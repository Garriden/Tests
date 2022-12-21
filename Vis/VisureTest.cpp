/*
Codifique en C++ (sin usar llamadas al API de Windows) una aplicación cliente-servidor,
    para la siguiente funcionalidad:
V- Ambas aplicaciones son aplicaciones de consola Windows
V- El servidor asigna un nombre a cada cliente cuando se conectan
v- El cliente envía cada segundo peticiones de inserción de un Usuario con los datos: 
    Id y Name. El identificador es un valor aleatorio entre 1 y 248 y que no se 
    repite en cada ejecución. El cliente muestra por consola el usuario enviado, 
    el tiempo que ha tardado en recibir la respuesta y la respuesta que le ha 
    dado el servidor.
V- El servidor tiene que almacenar en RAM todos los usuarios que le envíen 
    todos los clientes. (map)
V- El servidor tiene que rechazar un usuario si ya tiene almacenado otro 
    con el mismo identificador. (el map.insert ya se encarga de eso)
v- El servidor devuelve un valor que indica si ha realizado o no la inserción.
V- La ejecución del cliente termina cuando no tiene más identificadores libres.
V- La ejecución del servidor termina cuando hace más de 1 minuto que ningún 
    cliente le ha realizado ninguna petición. Antes de finalizar escribe en 
    un archivo de texto la lista de usuarios recibidos con el identificador 
    del cliente que lo ha insertado.

Se valorarán los siguientes aspectos:
 - Claridad del código
 - Eficiencia
 - Idoneidad de las estructuras de datos utilizadas
 - Utilización de librerías de código libre (STL, Boost, etc.)
*/

#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <ctime>
#include <afunix.h>
#include <vector>
#include <algorithm>
#include <string>

#include "Names.h"

using namespace std;

#pragma comment(lib, "Ws2_32.lib")

#define DEFAULT_PORT "27015"
#define DEFAULT_BUFLEN 512
#define SECOND 1000

struct User {
    int id;
    string name;
};

vector<User> NonRepeteableRandom()
{
	vector<User> v(MAX_USERS_NUMBER);

	for(int ii = 0; ii < MAX_USERS_NUMBER; ii++) {
		v[ii].id = ii;
		v[ii].name = Names[ii];
	}

	random_shuffle( v.begin(), v.end() );

    return v;
}

int main() 
{
	int iResult;

	// Initialize Winsock
	WSADATA wsaData;
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0) { // Error handling
		printf("WSAStartup failed: %d\n", iResult);
		return 1;
	}

	struct addrinfo* result = NULL,
		* ptr = NULL,
		hints;

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_DGRAM;
	hints.ai_protocol = IPPROTO_UDP;

	// Resolve the server address and port
	iResult = getaddrinfo("127.0.0.1", DEFAULT_PORT, &hints, &result);
	if (iResult != 0) { // Error handling
		printf("getaddrinfo failed: %d\n", iResult);
		WSACleanup();
		return 1;
	}
	SOCKET ConnectSocket = INVALID_SOCKET;
	// Attempt to connect to the first address returned by
	// the call to getaddrinfo
	ptr = result;

	// Create a SOCKET for connecting to server
	ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
	if (ConnectSocket == INVALID_SOCKET) { // Error handling
		printf("Error at socket(): %ld\n", WSAGetLastError());
		freeaddrinfo(result);
		WSACleanup();
		return 1;
	}

	// Connect to server.
	iResult = connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
	if (iResult == SOCKET_ERROR) {  // Error handling
		closesocket(ConnectSocket);
		ConnectSocket = INVALID_SOCKET;
	}

	freeaddrinfo(result);

	if (ConnectSocket == INVALID_SOCKET) { // Error handling
		printf("Unable to connect to server!\n");
		WSACleanup();
		return 1;
	}
	int recvbuflen = DEFAULT_BUFLEN;

	const char* sendbuf = "this is a test";
	char recvbuf[DEFAULT_BUFLEN];

	vector<User> randomVector = NonRepeteableRandom();
	int randomVectorPosition = 0;


	while(randomVectorPosition < MAX_USERS_NUMBER) {
		//std::string s;
		//std::cin >> s;

		User user = randomVector[randomVectorPosition++];
		string message = std::to_string(user.id) + "," + user.name;

		clock_t begin = clock();

		// Send the string
		iResult = send(ConnectSocket, message.c_str(), (int)strlen(message.c_str()), 0);
		if (iResult == SOCKET_ERROR) {
			printf("send failed: %d\n", WSAGetLastError());
			closesocket(ConnectSocket);
			WSACleanup();
			return 1;
		}

		std::cout << "Message sent: " << message << std::endl;

		//printf("Bytes Sent: %ld, message: %ld\n", iResult, s);

		Sleep(1000);
	}

	std::cout << "Shutting the socket down!" << std::endl;

	// shutdown the connection for sending since no more data will be sent
	// the client can still use the ConnectSocket for receiving data
	iResult = shutdown(ConnectSocket, SD_SEND);
	if (iResult == SOCKET_ERROR) { // Error handling
		printf("shutdown failed: %d\n", WSAGetLastError());
		closesocket(ConnectSocket);
		WSACleanup();
		return 1;
	}

	// Receive data until the server closes the connection
/*
	begin = clock();
	do {
		iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);
		if (iResult > 0)
			printf("Bytes received: %d\n", iResult);
		else if (iResult == 0)
			printf("Connection closed\n");
		else
			printf("recv failed: %d\n", WSAGetLastError());
	} while (iResult > 0);
	end = clock();
	elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout << "Elapsed time: " << elapsed_secs << endl;
*/
	return 0;
}