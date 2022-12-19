#include <iostream>
#include <winsock2.h>
using namespace std;

#pragma comment(lib,"ws2_32.lib") // Winsock Library
#pragma warning(disable:4996) 

#define BUFLEN 512
#define PORT 27015

int main()
{
    int res = 0;
    sockaddr_in server, client;

    // initialise winsock
    WSADATA wsa;
    res = WSAStartup(MAKEWORD(2, 2), &wsa);
    if(res != 0) { // Error handling
        printf("Failed. Error Code: %d", WSAGetLastError());
        exit(0);
    }

    // create an UDP socket
    SOCKET server_socket = socket(AF_INET, SOCK_DGRAM, 0);
    if(server_socket == INVALID_SOCKET) { // Error handling
        printf("Could not create socket: %d", WSAGetLastError());
    }

    // prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    // bind
    res = bind(server_socket, (sockaddr*)&server, sizeof(server));
    if(res == SOCKET_ERROR) { // Error handling
        printf("Bind failed with error code: %d", WSAGetLastError());
        exit(EXIT_FAILURE);
    }

    res = 1; // force to enter the while
    while(res > 0) {
        printf("Waiting...");
        fflush(stdout);
        char message[BUFLEN] = {};

        // try to receive some data, this is a blocking call
        int message_len;
        int slen = sizeof(sockaddr_in);
        message_len = recvfrom(server_socket, message, BUFLEN, 0, (sockaddr*)&client, &slen);
        if (message_len == SOCKET_ERROR) { // Error handling
            printf("recvfrom() failed with error code: %d", WSAGetLastError());
            exit(0);
        }

        // print details of the client/peer and the data received
        printf("Received packet from %s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));
        printf("Data: %s\n", message);

    }

    closesocket(server_socket);
    WSACleanup();
}