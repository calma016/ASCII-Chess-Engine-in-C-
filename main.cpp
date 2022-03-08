#include <iostream>

#include "include/bitMap.hpp"
#include "include/movement.hpp"
int main()
{
    //Declare our objects
    bitMap bitmap = bitMap();
    Movement movement = Movement();

    //initilize variables > bo
    std::string board[8][8];

    //start our initilization
    bitmap.fillBitBoard(board);
    bitmap.printBitBoard(board);
    for(;;)
    {
        movement.selectPiece(board);
    //system("CLEAR");
    bitmap.printBitBoard(board);

    }
    

    return 0;
}
