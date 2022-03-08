#include "bitMap.hpp"
#include <iostream>
//START OF FILLBITBOARD FUNCTION
int bitMap::fillBitBoard(std::string board[8][8])
{
    //Our bottom part of the array will be the starting cooridnates such as (0,0)
    for (int i = H - 1; i >= 0; i--)
    {
        
        for (int j = 0; j < V; j++)
        {
            //piece initilization
            //WHITE PIECES
            if (i == 1 && j < 8){board[i][j] = " \u265F ";}  //WHITE PAWN
            else if ((i == 0 && j == 0) || (i == 0 && j == 7)){board[i][j] = " \u265c ";} // WHITE TOWER
            else if ((i == 0 && j == 1) || (i == 0 && j == 6)){board[i][j] = " \u265e ";} // WHITE KNIGHT
            else if ((i == 0 && j == 2) || (i == 0 && j == 5)){board[i][j] = " \u265d ";} // WHITE BISHOP
            else if ((i == 0 && j == 4)){board[i][j] = " \u265a ";} //WHITE KING
            else if ((i == 0 && j == 3)){board[i][j] = " \u265b ";} //WHITE QUEEN
           
            //BLACK PIECES
            else if (i == 6 && j < 8){board[i][j] = " \u2659 ";} //BLACK PAWN
            else if ((i == 7 && j == 0) || (i == 7 && j == 7)){board[i][j] = " \u2656 ";} //BLACKTOWER
            else if ((i == 7 && j == 1) || (i == 7 && j == 6)){board[i][j] = " \u2658 ";} //BLACK KNIGHT
            else if ((i == 7 && j == 2) || (i == 7 && j == 5)){board[i][j] = " \u2657 ";} //BLACK BISHOP
            else if ((i == 7 && j == 4)){board[i][j] = " \u2654 ";} //BLACK KING
            else if ((i == 7 && j == 3)){board[i][j] = " \u2655 ";} //BLACK QUEEN

            else{board[i][j] = tile;} //TILES
           
        }
        /* code */
    }
    return 0;
}
//END OF FILLBITBOARD FUNCTION
//START OF PRINTBITBOARD FUNCTION
int bitMap::printBitBoard(std::string board[8][8])
{
    for (int i = H - 1; i >= 0 ; i--) //reiterate through each item in the array and print them in order
    {
        for (int j = 0; j < V; j++)
        {
            std::cout << board[i][j];
        }
        std::cout << std::endl; //skip a line once done with one row
    }
    return 0;
}
//END OF PRINTBOARD FUNCTION