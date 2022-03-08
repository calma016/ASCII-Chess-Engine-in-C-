#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
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
    std::string buffer;
    int sockfd;
    unsigned int PORT = 8080;
    int valread = 0;
    struct sockaddr_in address;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        std::cout << "Client couldn't create socket" << std::endl;
    }
    address.sin_family = AF_INET;
    address.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *)&address, sizeof(address)) == -1)
    {
        std::cout << "Clinet couldn't connect" << std::endl;
    }
    
    
    
    system("CLEAR");
    char ipadd [INET_ADDRSTRLEN] = "";
    socklen_t len = sizeof(address);
    if(getpeername(sockfd, (struct sockaddr*)&address, &len))
    {
        std::cout << "peerName not working" << std::endl;
    }
    else{
        inet_ntop(AF_INET, &address.sin_addr,ipadd, sizeof(ipadd));
        std::cout << "IP Address of server: " << ipadd << std::endl;
    }
    movement.selectPieceSocket(board, sockfd, "black", 1);
   
        
    
    return 0;
}