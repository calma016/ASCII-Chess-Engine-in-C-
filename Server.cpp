#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "include/bitMap.hpp"
#include "include/movement.hpp"
#include <iostream>
#include <string>

int main()
{

    bitMap bitmap = bitMap();
    std::string board[8][8];
    bitmap.fillBitBoard(board);
    Movement movement = Movement();
    bitmap.printBitBoard(board);

    int sockfd, newSock;
    int opt = 1;
    unsigned int PORT = 8080;
    int valread = 0;
    struct sockaddr_in address;
    socklen_t addrlen = sizeof(address);
    char buffer[1024] = {0};

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        std::cout << "Error creating the server" << std::endl;
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR,
                   &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    if (bind(sockfd, (struct sockaddr *)&address, addrlen) == -1)
    {
        std::cout << "server couldn't bind" << std::endl;
    }

    if (listen(sockfd, 5) == -1)
    {
        std::cout << "server couldn't listen" << std::endl;
    }
    std::cout << "Finding client" << std::endl;
    if ((newSock = accept(sockfd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) == -1)
    {
        std::cout << "server couldn't accept" << std::endl;
    }
    std::cout << "Client Found!" << std::endl;
    char hello[1024] = "Hello World";

    movement.selectPieceSocket(board, newSock, "white", 1);
    bitmap.printBitBoard(board);

    return 0;
}
