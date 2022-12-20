#include <iostream>
#include <winsock2.h>
#include <map>
#include <string>


#pragma comment(lib,"ws2_32.lib") // Winsock Library
#pragma warning(disable:4996) 

#define BUFLEN 512
#define PORT 27015

std::map<int, std::string> User;

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
        
        // Decompress the message
        std::string s = message;
        int pos = s.find(",");
        int id = std::stoi(s.substr(0, pos));
        std::string name = s.substr(pos+1, s.size());
        

        // Print the data received
        std::cout << "Received packet from client num:: " << ntohs(client.sin_port) << std::endl;
        std::cout << "Message received: " << id << " / " << name << std::endl;

        // Map structure dones't allow duplicates. It does not insert if it already exists.
         // But, if we want to check if the user.id it is already stored:
         // std::map::contains(id) in C++ 20
        if (User.count(id) != 0) { // It is repeated
            std::cout << "Repeated user!" << std::endl;
        }

        // Save in RAM
        User.insert(std::pair<int, std::string>(id, name));

 

        /*
        std::map<int, std::string>::iterator itr;
        for (itr = User.begin(); itr != User.end(); ++itr) {
            std::cout << '\t' << itr->first << '\t' << itr->second << std::endl;
        }
        std::cout << std::endl;
        */
    }

    closesocket(server_socket);
    WSACleanup();
}