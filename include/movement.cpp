#include <iostream>
#include "movement.hpp"
#include "rules.hpp"
#include "bitMap.hpp"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string>

//START OF SELECT PIECE FUNCTION
int Movement::selectPiece(std::string board[8][8])
{
    //OBJECTS IN USE
    Rules rule = Rules();
    bitMap bitmap = bitMap();
    //VARIABLES
    std::string pieceName = turn == 1 ? "white" : "black"; // variable stores the turns either if it's black or whites turn
    bool rightWay = false; //a boolean statment to see if the position chosen is for the right piece


    int prevX = 0; // variable takes the coordinate of the current x coordinate
    int prevY = 0; // variable takes the coordinate of the current y coordinate

    bool rightPiece = false; // boolean statement to see if the position chosen is the for the right piece
    std::cout << pieceName << "'s turn" << std::endl;

    //CHECK MATE FUNCTION PART OF THE RULES OBJECT
    //check if the white king is in check
    if (rule.kingCheck(pieceName, whiteKing[0], whiteKing[1], blackKing[0], blackKing[1], board) == 1)
    {
        std::cout << "White is in check" << std::endl;
    }
    //check if the black king is in check
    else if (rule.kingCheck(pieceName, whiteKing[0], whiteKing[1], blackKing[0], blackKing[1], board) == 2)
    {
        std::cout << "Black is in check" << std::endl;
    }

    //while loop to test out if the piece they chose is theirs
    while (rightPiece != true)
    {
        //Taking in users input
        std::string prev;
        std::cout << "Please enter the coordinate of the piece you are trying to move: ";
        std::cin >> prev;
        std::cout << std::endl;


        //From here find the coordinates based on the strings given to us 
        prevX = horiz[prev[0]];
        prevY = vert[prev[1]];
        std::cout << "prevX: " << prevX << std::endl;
        std::cout << "prevY: " << prevY << std::endl;

        //Check if the piece chosen is the white piece
        if (pieceName == "white")
        {

            for (int i = 0; i < whitePieces.size(); i++)
            {
                if (blackPieces[i] == board[prevY][prevX])
                {

                    rightPiece = true;
                }
            }
            if (rightPiece == false)
            {
                bitmap.printBitBoard(board);
                std::cout << "It's white's turn" << std::endl;
            }
        }
        //check if the piece chosen is the black piece
        else
        {
            std::cout << "blc" << std::endl;
            for (int i = 0; i < blackPieces.size(); i++)
            {
                if (whitePieces[i] == board[prevY][prevX])
                {
                    rightPiece = true;
                }
            }
            if (rightPiece == false)
            {
                bitmap.printBitBoard(board);
                std::cout << "It's white's turn" << std::endl;
            }
        }
    }
    //user input -> for the current position

    //user input -> for the next position
    std::string coord;
    std::cout << "Please enter the new coordinate of the piece: ";
    std::cin >> coord;
    std::cout << std::endl;

    //take in the new coord
    int coordX = horiz[coord[0]];
    int coordY = vert[coord[1]];
    std::cout << "coordX: " << coordX << std::endl;
    std::cout << "coordY: " << coordY << std::endl;
    //sotre the piece they want to move

    std::string piece = board[prevY][prevX];
    std::cout << "PIECE: " << piece << std::endl;
    //check if the desired position is valid
    if (rule.referee(board, pieceName, piece, coordX, coordY, prevX, prevY) == true)
    {
        turn = turn == 1 ? 0 : 1;
        //check if the position is a king piece and store their new position
        if (board[prevY][prevX] == " \u2654 ")
        {
            blackKing[0] = coordY;
            blackKing[1] = coordX;
        }
        else if (board[prevY][prevX] == " \u265a ")
        {
            whiteKing[0] = coordY;
            whiteKing[1] = coordX;
        }
        //make the previous coordinate a tile since they left their tile

        board[prevY][prevX] = " * ";

        //make the coordinate the desired piece we wanted to move
        board[coordY][coordX] = piece;
        //if a pawn reaches the end of the board turn it into a queen
        if (coordY == 7 && board[coordY][coordX] == " \u265F ")
        {
            std::cout << "worked" << std::endl;
            board[coordY][coordX] = " \u265b ";
        }
    }

    return 0;
}
//END OF SELECTPIECE FUNCTION

//START OF SELECTPIECESOCKET FUNCTION
//In this function we incorporate libraries used in networking socket in order to have on concise abstraction
int Movement::selectPieceSocket(std::string board[8][8], int sockfd, std::string color, int turns)
{

    std::string pieceName = turns == 1 ? "white" : "black";
    bool rightWay = false;
    //declare the rules
    Rules rule = Rules();
    bitMap bitmap = bitMap();
    //Declare the pieces turn
    int prevX = 0;
    int prevY = 0;
    int coordX = 0;
    int coordY = 0;
    std::string piece;
    std::string prev;
    std::string coord;
    bool rightPiece = false;
    std::cout << pieceName << "'s turn" << std::endl;
    if (rule.kingCheck(pieceName, whiteKing[0], whiteKing[1], blackKing[0], blackKing[1], board) == 1)
    {
        std::cout << "White is in check" << std::endl;
    }
    else if (rule.kingCheck(pieceName, blackKing[0], whiteKing[1], blackKing[0], blackKing[1], board) == 2)
    {
        std::cout << "Black is in check" << std::endl;
    }
    if (color == pieceName)
    {
        while (rightPiece != true)
        {

            std::cout << "Please enter the coordinate of the piece you are trying to move: ";
            std::cin >> prev;
            std::cout << std::endl;
            //take in the prevX
            prevX = horiz[prev[0]];
            prevY = vert[prev[1]];
            std::cout << "prevX: " << prevX << std::endl;
            std::cout << "prevY: " << prevY << std::endl;
            if (pieceName == "white")
            {

                for (int i = 0; i < whitePieces.size(); i++)
                {
                    if (blackPieces[i] == board[prevY][prevX])
                    {

                        rightPiece = true;
                    }
                }
                if (rightPiece == false)
                {
                    bitmap.printBitBoard(board);
                    std::cout << "It's white's turn" << std::endl;
                }
            }
            else
            {
                std::cout << "blc" << std::endl;
                for (int i = 0; i < blackPieces.size(); i++)
                {
                    if (whitePieces[i] == board[prevY][prevX])
                    {
                        rightPiece = true;
                    }
                }
                if (rightPiece == false)
                {
                    bitmap.printBitBoard(board);
                    std::cout << "It's white's turn" << std::endl;
                }
            }
        }
        //user input -> for the current position

        //user input -> for the next position
        
        std::cout << "Please enter the new coordinate of the piece: ";
        std::cin >> coord;
        std::cout << std::endl;
        //take in the new coord
        coordX = horiz[coord[0]];
        coordY = vert[coord[1]];
        std::cout << "coordX: " << coordX << std::endl;
        std::cout << "coordY: " << coordY << std::endl;
        //get the piece that you want to move
        piece = board[prevY][prevX];
        std::cout << "PIECE: " << piece << std::endl;
        if (rule.referee(board, pieceName, piece, coordX, coordY, prevX, prevY) == true)
        {
            turns = turns == 1 ? 0 : 1;
            if (board[prevY][prevX] == " \u2654 ")
            {
               
                blackKing[0] = coordY;
                blackKing[1] = coordX;
            }
            else if (board[prevY][prevX] == " \u265a ")
            {
                whiteKing[0] = coordY;
                whiteKing[1] = coordX;
            }

            board[prevY][prevX] = " * ";

            board[coordY][coordX] = piece;
            if (coordY == 7 && board[coordY][coordX] == " \u265F ")
            {
                std::cout << "worked" << std::endl;
                board[coordY][coordX] = " \u265b ";
            }
            std::string sentCoord = prev + coord + "0";
            send(sockfd, (char *)&sentCoord, sizeof(coord), 0);
            system("CLEAR");
            selectPieceSocket(board, sockfd, color, turns);
        }
    }
    else
    {
        char buffer[5] = {0};
        int valread = 0;
        bitmap.printBitBoard(board);
        std::cout << "waiting for response" << std::endl;
        while (valread == 0)
        {
            
           
            
            valread = read(sockfd, buffer, 1024);
        }
        
        turns = turns == 1?0:1;
        
        prevX = horiz[buffer[0]];
        prevY = vert[buffer[1]];
        piece = board[prevY][prevX];
        coordX = horiz[buffer[2]];
        coordY = vert[buffer[3]];
        
        board[prevY][prevX] = " * ";
        board[coordY][coordX] = piece;
        system("CLEAR");
        bitmap.printBitBoard(board);
        selectPieceSocket(board,sockfd, color, turns);
    }
    return 0;
}
//END OF SELECTPIECESOCKET FUNCTION
