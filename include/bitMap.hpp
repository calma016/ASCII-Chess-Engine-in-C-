#include <vector>
#include <string>
#define H 8
#define V 8
class bitMap
{
    //only variables accessable by initizilations inside the class
private:
    
    std::string tile = " * ";            //physical representation of the board tiles
      // how many tiles there are vertically

public:
    
    
    //functions that help build the board
    int fillBitBoard(std::string board[8][8]);
    int printBitBoard(std::string board[8][8]);
};
