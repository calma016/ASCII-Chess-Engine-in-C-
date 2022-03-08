#include <iostream>
#include <vector>
#include <map>
class Rules
{
private:
    std::vector<std::string> blackPieces{
        " \u265F ",
        " \u265E ",
        " \u265D ",
        " \u265C ",
        " \u265B ",
        " \u265A ",
    };
    std::vector<std::string> whitePieces{
        " \u2659 ",
        " \u2658 ",
        " \u2657 ",
        " \u2656 ",
        " \u2655 ",
        " \u2654 ",
    };
    

public:
    bool referee(std::string board[8][8], std::string color, std::string piece, int x, int y, int pX, int pY); // this controls the rules of the game
    bool pawnRule(std::string board[8][8], std::string color, int x, int y, int pX, int pY);                                            // Rules that pertain to the pawn
    bool towerRule(std::string board[8][8], std::string color, int x, int y, int pX, int pY);                                     // Rules that pertain to the tower
    bool horseRule(std::string board[8][8], int x, int y, int pX, int pY);                                     // Rules that pertain to the  horse
    bool bishopRule(std::string board[8][8], std::string color, int x, int y, int pX, int pY);                                    // Rules that pertain to the bishop
    bool queenRule(std::string board[8][8], std::string color, int x, int y, int pX, int pY);                  // Rules that pertain to the queen
    bool kingRule(std::string board[8][8], std::string color, int x, int y, int pX, int pY);                                      // Rules that pertain to the king/
    int kingCheck(std::string color, int wx, int wy, int bx, int by, std::string board[8][8]);
    bool checkAttack(int x, int y, std::string color, std::string board[8][8]);
    std::vector<std::string> whiteTaken;
    std::vector<std::string> blackTaken;
    
};