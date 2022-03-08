#include <iostream>
#include <map>
#include <vector>
/*
    Movement class is basically contains functions to help with logic and movement of the game
    By Carlos M. Almagro, FIU Computer Engineering 
*/
//START OF MOVMENT CLASS
class Movement
{

private:
    //hashmap to convert the characters into integers
    std::map<char, int> horiz{
        {'a', 0},
        {'b', 1},
        {'c', 2},
        {'d', 3},
        {'e', 4},
        {'f', 5},
        {'g', 6},
        {'h', 7},
    };
    //hashmap to convert the characters into integers
    std::map<char, int> vert{
        {'1', 0},
        {'2', 1},
        {'3', 2},
        {'4', 3},
        {'5', 4},
        {'6', 5},
        {'7', 6},
        {'8', 7}
    };
    //An array of the blackpieces on the board
    std::vector<std::string> blackPieces {
        " \u265F ",
        " \u265E ",
        " \u265D ",
        " \u265C ",
        " \u265B ",
        " \u265A ",
    };
    //An array of the whitepieces on the board
    std::vector<std::string> whitePieces {
        " \u2659 ",
        " \u2658 ",
        " \u2657 ",
        " \u2656 ",
        " \u2655 ",
        " \u2654 ",
    };
    //coordinates for the black king in order to test if the king is in check
    std::vector<int> blackKing = {4, 7};
    //coordinates for the white king in order to test if the king is in check
    std::vector<int> whiteKing = {4,0};

    //the turn variable for same computer play
    int turn = 1;

public:
    //This function is for the logic and movement of pieces on a network
    int selectPieceSocket(std::string board[8][8], int sockfd, std::string color, int turns);
    //This function is for the logic and movment of pieces on the same computer play
    int selectPiece(std::string board[8][8]); 
    
    
};
//END OF MOVEMENT CLASS