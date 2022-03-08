#include "rules.hpp"

//PAWN RULE FUNCTION
bool Rules::pawnRule(std::string board[8][8], std::string color, int x, int y, int pX, int pY)
{
    
    //White Movement
    if (color == "white") //check for color of the pawn
    {
        if (pY == 1 && pX == x ) //if the pawn is at it's starting position it has two possible move
        {
            if ((pY - y == -2)) //either move up by two
            {
                return true;
            }
            else if(pY - y == -1)// or move up by one
            {
                return true;
            }
        }
        else if ((pY - y == -1) && pX == x) // if the pawn isn't at the original y location then the pawn could only move by one
        {
            
            return true;
        }
        else
        {
               
                if(((pY - y == -1 && pX - x == -1) || (pY - y == -1 && pX - x == 1)) ) //These are the attacking moves that each pawn could execute in a game
                {
                    return checkAttack(x, y, color, board); //check if the attack is valid using the checkAttack functin

                }   
        }
    }
    else if(color == "black")
    {
        std::cout << "color" << std::endl;
         if (pY == 6 && pX == x )
        {
            std::cout << "working" << std::endl;
            if ((pY - y == 2))
            {
                return true;
            }
            else if(pY - y == 1)
            {
                return true;
            }
        }
        else if ((pY - y == 1) && pX == x)
        {
            return true;
        }
        else
        {
                
                if(((pY - y == -1 && pX - x == -1) || (pY - y == -1 && pX - x == 1)) )
                {
                    return checkAttack(x, y, color, board);

                }   
        }
    }

    return false;
} //END OF PAWN RULE FUNCTION
//TOWER RULE FUNCTION
//TOWER RULE FUNCTION START
bool Rules::towerRule(std::string board[8][8], std::string color, int x, int y, int pX, int pY)
{
    //The function start by checking if the x coordinate is the same
    if (x == pX)
    {
        //check if the current coordinate is greater than or less than the y coordinate 
        //based on this we could find out the possible position both ways (left and right or up and down)
        int mult = pY > y ? -1 : 1;
        
        for (int i = 1; i <= 8; i++)//reiterate through each possible position
        {
            // checks if one of the paths are empty and if it is and one of our desired positions are in their then return true
            if (board[pY + mult * i][x] == " * ")
            {
                if (pY + mult * i == y)
                {
                    return true;
                }
            }
            //if the path is occupied then return false and the desired position isn't possible
            else
            {
                return false;
            }
        }
    }
    //Then we start to check if the y cooridnates are the same and we basically proceed with the same concept above
    else if (y == pY)
    {
        int mult = pX > x ? -1 : 1;
        for (int j = 1; j <= 8; j++)
        {
            if (board[pY][pX + mult * j] == " * ")
            {
                if (pX + mult * j == x)
                {
                    return true;
                }
            }
            else
            {
                return checkAttack(x, y, color, board);
            }
        }
    }
    return false;
} //END TOWER RULE FUNCTION
//START QUEEN RULE FUNCTION
bool Rules::queenRule(std::string board[8][8], std::string color, int x, int y, int pX, int pY)
{
    //reiterate through each possible path 
    for (int i = 1; i <= 8; i++)
    {
        //check if the desired y or x coordinate are the same, larger or smaller than the current x or y coordinate
        int multX = pX == x ? 0 : pX < x ? 1 //These logical inputs determine the direction the queen will go depending on user's desired input
                                         : -1;
        int multY = pY == y ? 0 : pY < y ? 1
                                         : -1;
        
        if (board[pY + i * multY][pX + i * multX] == " * ") // check if there is an open space
        {
            
            if (pY + i * multY == y && pX + i * multX == x)
            {
                return true;
            }
        }
        else//if there isn't an open space check if an attack is possible
        {   
            return checkAttack(x, y, color, board);
        }
    }
    return false;
} //END QUEEN RULE FUNCTION
//START OF THE BISHIOP FUNCTION
bool Rules::bishopRule(std::string board[8][8], std::string color, int x, int y, int pX, int pY)
{
    //reiterate through each possible path
    for (int i = 1; i <= 8; i++)
    {
        // find out if the coordinate selected is larger than the current in order to see the path's direction for both the y and the x
        int multY = pY < y ? 1 : -1; 
        int multX = pX < x ? 1 : -1;

        //if a tile is empty proceed to see if the desired input is one of those empty spots
        if (board[pY + multY * i][pX + multX * i] == " * ")
        {

            if (pY + multY * i == y && pX + multX * i == x)
            {
                return true;
            }
        }
        // if the path selected is not empty return false
        else
        {
            return checkAttack(x, y, color, board);
        }
    }
    return false;
}
//END OF THE BISHOP FUNCTION
bool Rules::kingRule(std::string board[8][8], std::string color, int x, int y, int pX, int pY)
{
    int multY = pY == y ? 0 : pY < y ? 1 : -1;
    int multX = pX == x ? 0 : pX < x ? 1 : -1;
    
    if (board[pY + 1 * multY ][pX + 1 * multX ] == " * ")
    {
        
        if (pY + 1 * multY == y && pX + 1 * multX == x)
        {
            
            if(color == "white")
            {
                if(kingCheck(color, x, y, 0, 0, board) == 1)
                {
                    
                    return false;
                }
                else
                {
                    return true;
                }
            }
            else if(color == "black")
            {
                if(kingCheck(color, 0, 0, x, y, board) == 2)
                {
                    std::cout << "Chec2k" << std::endl;
                    return false;
                }
                else
                {
                    
                    return true;
                }
            }
            
        }
    }
    else
    {
        
        if(checkAttack(x, y, color, board) == true)
        {
            if(color == "white")
            {
                if(kingCheck(color, x, y, 0, 0, board) == 1)
                {
                    
                    return false;
                }
                else
                {
                    return true;
                }
            }
            
        }
        return false;
    }
    return false;
}
//START OF HORSE/KNIGHT FUNCTION 
bool Rules::horseRule(std::string board[8][8], int x, int y, int pX, int pY)
{

    //here since the horse can jump over pieces we are basically checking for each single path if the horse can go the path
    if ((x == pX - 2 && y == pY + 1) ||
        ((x == pX - 2 && y == pY - 1)))
    {
        return true;
    }
    else if ((x == pX + 2 && y == pY + 1) ||
             ((x == pX + 2 && y == pY - 1)))
    {
        return true;
    }
    else if ((x == pX + 1 && y == pY + 2) ||
             ((x == pX - 1 && y == pY + 2)))
    {
        return true;
    }
    else if ((x == pX - 1 && y == pY - 2) ||
             ((x == pX + 1 && y == pY - 2)))
    {
        return true;
    }
    return false;
}
//END OF HORSE/KNIGHT FUNCTION
//START OF THE REFEREE FUNCTION
bool Rules::referee(std::string board[8][8], std::string color, std::string piece, int x, int y, int pX, int pY)
{

    //Initilizing my white pieces in the board
    if (piece == " \u265F " || piece == " \u2659 ")
    {
        return pawnRule(board,color, x, y, pX, pY); //white pawn rule
    }
    else if (piece == " \u265C " || piece == " \u2656 ")
    {
        return towerRule(board, color, x, y, pX, pY); //tower rule
    }
    else if (piece == " \u265D " || piece == " \u2657 ")
    {
        return bishopRule(board, color, x, y, pX, pY); // bishop rule
    }
    else if (piece == " \u265B " || piece == " \u2655 ")
    {
        return queenRule(board, color, x, y, pX, pY); // queen rule
    }
    else if (piece == " \u265E " || piece == " \u2658 ")
    {
        return horseRule(board, x, y, pX, pY); // horse rule
    }
    else if (piece == " \u265A " || piece == " \u2654 ")
    {
        return kingRule(board, color, x, y, pX, pY); // king rule
    }

    return false;
}
//END OF THE REFEREE FUNCTION
//START OF THE CHECKATTACK FUNCTION
bool Rules::checkAttack(int x, int y, std::string color, std::string board[8][8])
{
    //check if the piece attacking is white
    if (color == "white")
    {
        //go through each black piece to check if the attacking piece is going to attack the right piece
        for (int j = 0; j < whitePieces.size(); j++)
        {
            //return true if it is
            if (board[y][x] == whitePieces[j])
            {
                return true;
            }
        }
    }
    //DO THE SAME ABOVE FOR BLACK ATTACKING
    else if(color == "black")
    {
        for(int j = 0; j < blackPieces.size(); j++)
        {
            if(board[y][x] == blackPieces[j])
            {
                return true;
            }
        }
    }
    return false;
}//RETURN OF THE CHCEKATTACK FUNCTION
int Rules::kingCheck(std::string color, int wx, int wy, int bx, int by, std::string board[8][8])
{
    bool check = false;
    
    int count = 0;
    
    //Pawn Check Mate for white
    if(board[(wy + 1)][(wx + 1)] ==  " \u2659 " || board[(wy + 1)][(wx - 1)] ==  " \u2659 ")
    {
        return 1;
    }
    //Pawn Check Mate for black
    else if(board[(by - 1)][(bx + 1)] ==  " \u265F " || board[(by - 1)][(bx - 1)] ==  " \u265F ")
    {
        return 2;
    }
    //QUEEN AND TWOER CHECK MAKE  FOR WHITE
    for(int i = 1; i <= 8; i++)
    {
        if(wy + i * 1 > 7  || wx + i * 0 > 7)
        {
            break;
        }
        if(((board[(wy + i * 1)][(wx + i * 0)] !=  " \u2655 ") && (board[(wy + i * 1)][(wx + i * 0)] !=  " \u2656 "))  &&  board[(wy + i * 1)][(wx + i * 0)] !=  " * ")
        {
            
           
            break;
        }else if(((board[(wy + i * 1)][(wx + i * 0)] ==  " \u2655 ") || (board[(wy + i * 1)][(wx + i * 0)] ==  " \u2656 "))  )
        {
            
           
            return 1; 
        }
    }
    for(int i = 1; i <= 8; i++)
    {
        if(wy + i * 0 > 7  || wx + i * 1 > 7)
        {
            break;
        }
        if(((board[(wy + i * 0)][(wx + i * 1)] !=  " \u2655 ") &&(board[(wy + i * 0)][(wx + i * 1)] !=  " \u2656 ")  &&  board[(wy + i * 0)][(wx + i * 1)] !=  " * "))
        {
            
    
            break;
        }
        else if(((board[(wy + i * 0)][(wx + i * 1)] ==  " \u2655 ") ||(board[(wy + i * 0)][(wx + i * 1)] ==  " \u2656 "))  )
        {
            
            
            return 1; 
        }
    }
    for(int i = 1; i <= 8; i++)
    {
        if(wy + i * -1 > 7  || wx + i * 0 > 7)
        {
            break;
        }
        if(((board[(wy + i * -1)][(wx + i * 0)] !=  " \u2655 ") &&(board[(wy + i * -1)][(wx + i * 0)] !=  " \u2656 "))  &&  board[(wy + i * -1)][(wx + i * 0)] !=  " * ")
        {
            
            break;
        }
        else if(((board[(wy + i * -1)][(wx + i * 0)] ==  " \u2655 ") ||(board[(wy + i * -1)][(wx + i * 0)] ==  " \u2656 "))  )
        {
            
            return 1; 
        }
    }
    for(int i = 1; i <= 8; i++)
    {
        if(wy + i * 0 > 7  || wx + i * -1 > 7)
        {
            break;
        }
        if(((board[(wy + i * 0)][(wx + i * -1)] !=  " \u2655 ") &&(board[(wy + i * 0)][(wx + i * -1)] !=  " \u2656 ")  &&  board[(wy + i * 0)][(wx + i * -1)] !=  " * "))
        {
            
            break;
        }
        else if(((board[(wy + i * 0)][(wx + i * -1)] ==  " \u2655 ") ||(board[(wy + i * 0)][(wx + i * -1)] ==  " \u2656 "))  )
        {
             
            return 1; 
        }
    }
    //BISHOP AND QUEEN CHECKMATE
    for(int i = 1; i <= 8; i++)
    {   if(wy + i * 1 > 7  || wx + i * 1 > 7)
        {
            break;
        }
        
        if(((board[(wy + i * 1)][(wx + i * 1)] !=  " \u2655 ") && (board[(wy + i * 1)][(wx + i * 1)] !=  " \u2657 ")  &&  board[(wy + i * 1)][(wx + i * 1)] !=  " * "))
        {
          
            break;
        }
        else if(((board[(wy + i * 1)][(wx + i * 1)] ==  " \u2655 ") ||(board[(wy + i * 1)][(wx + i * 1)] ==  " \u2657 "))  )
        {
           
            
             
            return 1; 
        }
    }
    for(int i = 1; i <= 8; i++)
    {
        if(wy + i * -1 > 7  || wx + i * -1 > 7)
        {
            break;
        }
        if(((board[(wy + i * -1)][(wx + i * -1)] !=  " \u2655 ") && (board[(wy + i * -1)][(wx + i * -1)] !=  " \u2657 ")  &&  board[(wy + i * -1)][(wx + i * -1)] !=  " * "))
        {
           
            break;
        }
        else if(((board[(wy + i * -1)][(wx + i * -1)] ==  " \u2655 ") ||(board[(wy + i * -1)][(wx + i * -1)] ==  " \u2657 ")))
        {
           
             
            return 1; 
        }
    }
    for(int i = 1; i <= 8; i++)
    {
        if(wy + i * -1 > 7  || wx + i * 1 > 7)
        {
            break;
        }
        if(((board[(wy + i * -1)][(wx + i * 1)] !=  " \u2655 ") && (board[(wy + i * -1)][(wx + i * 1)] !=  " \u2657 ")  &&  board[(wy + i * -1)][(wx + i * 1)] !=  " * "))
        {
            
            break;
        }
        else if(((board[(wy + i * -1)][(wx + i * 1)] ==  " \u2655 ") ||(board[(wy + i * -1)][(wx + i * 1)] ==  " \u2657 "))  )
        {
           
            return 1; 
        }
    }
    for(int i = 1; i <= 8; i++)
    {
        if(wy + i * 1 > 7  || wx + i * -1 > 7)
        {
            break;
        }
        if(((board[(wy + i * 1)][(wx + i * -1)] !=  " \u2655 ") && (board[(wy + i * 1)][(wx + i * -1)] !=  " \u2657 ")  &&  board[(wy + i * 1)][(wx + i * -1)] !=  " * "))
        {
           
            break;
        }
        else if(((board[(wy + i * 1)][(wx + i * -1)] ==  " \u2655 ") ||(board[(wy + i * 1)][(wx + i * -1)] ==  " \u2657 "))  )
        {
            
            return 1; 
        }
    }
    //QUEEN AND TWOER CHECK MAKE  FOR BLACK
    for(int i = 1; i <= 8; i++)
    {
        if(by + i * 1 > 7  || bx + i * 0 > 7)
        {
            break;
        }
        if(((board[(by + i * 1)][(bx + i * 0)] !=  " \u265b ") && (board[(by + i * 1)][(bx + i * 0)] !=  " \u265c "))  &&  board[(by + i * 1)][(bx + i * 0)] !=  " * ")
        {
            
           
            break;
        }else if(((board[(by + i * 1)][(bx + i * 0)] ==  " \u265b ") || (board[(by + i * 1)][(bx + i * 0)] ==  " \u265c "))  )
        {
            
           
            return 2; 
        }
    }
    for(int i = 1; i <= 8; i++)
    {
        if(by + i * 0 > 7  || bx + i * 1 > 7)
        {
            break;
        }
        if(((board[(by + i * 0)][(bx + i * 1)] !=  " \u265b ") &&(board[(by + i * 0)][(bx + i * 1)] !=  " \u265c ")  &&  board[(by + i * 0)][(bx + i * 1)] !=  " * "))
        {
            
    
            break;
        }
        else if(((board[(by + i * 0)][(bx + i * 1)] ==  " \u265b ") ||(board[(by + i * 0)][(bx + i * 1)] ==  " \u265c "))  )
        {
            
           
            return 2; 
        }
    }
    for(int i = 1; i <= 8; i++)
    {
        
        if(by + i * -1 > 7  || bx + i * 0 > 7)
        {
            break;
        }
        if(((board[(by + i * -1)][(bx + i * 0)] !=  " \u265b ") &&(board[(by + i * -1)][(bx + i * 0)] !=  " \u265c "))  &&  board[(by + i * -1)][(bx + i * 0)] !=  " * ")
        {
            
            break;
        }
        else if(((board[(by + i * -1)][(bx + i * 0)] ==  " \u265b ") || (board[(by + i * -1)][(bx + i * 0)] ==  " \u265c ")))
        {
            
            return 2; 
        }
    }
    for(int i = 1; i <= 8; i++)
    {
        
        if(by + i * 0 > 7  || bx + i * -1 > 7)
        {
            break;
        }
        if(((board[(by + i * 0)][(bx + i * -1)] !=  " \u265b ") &&(board[(by + i * 0)][(bx + i * -1)] !=  " \u265c ")  &&  board[(by + i * 0)][(bx + i * -1)] !=  " * "))
        {
            break;
        }
        else if(((board[(by + i * 0)][(bx + i * -1)] ==  " \u265b ") ||(board[(by + i * 0)][(bx + i * -1)] ==  " \u265c "))  )
        {
            
            return 2; 
        }
    }
    //BISHOP AND QUEEN CHECKMATE FOR BLACK
    for(int i = 1; i <= 8; i++)
    {   if(by + i * 1 > 7  || bx + i * 1 > 7)
        {
            break;
        }
        
        if(((board[(by + i * 1)][(bx + i * 1)] !=  " \u265b ") && (board[(by + i * 1)][(bx + i * 1)] !=  " \u265d ")  &&  board[(by + i * 1)][(bx + i * 1)] !=  " * "))
        {
          
            break;
        }
        else if(((board[(by + i * 1)][(bx + i * 1)] ==  " \u265b ") ||(board[(by + i * 1)][(bx + i * 1)] ==  " \u265d "))  )
        {
           
           
            return 2; 
        }
    }
    for(int i = 1; i <= 8; i++)
    {
        if(by + i * -1 > 7  || bx + i * -1 > 7)
        {
            break;
        }
        if(((board[(by + i * -1)][(bx + i * -1)] !=  " \u265b ") && (board[(by + i * -1)][(bx + i * -1)] !=  " \u265d ")  &&  board[(by + i * -1)][(bx + i * -1)] !=  " * "))
        {
           
            break;
        }
        else if(((board[(by + i * -1)][(bx + i * -1)] ==  " \u265b ") ||(board[(by + i * -1)][(bx + i * -1)] ==  " \u265d ")))
        {
           
             
            return 2; 
        }
    }
    for(int i = 1; i <= 8; i++)
    {
        
        
        if(((board[(by + i * -1)][(bx + i * 1)] !=  " \u265b ") && (board[(by + i * -1)][(bx + i * 1)] !=  " \u265d ")  &&  board[(by + i * -1)][(bx + i * 1)] !=  " * "))
        {
            
            break;
        }
        else if(((board[(by + i * -1)][(bx + i * 1)] ==  " \u265b ") || (board[(by + i * - 1)][(bx + i * 1)] ==  " \u265d "))  )
        {
            
          
            return 2; 
        }
    }
    for(int i = 1; i <= 8; i++)
    {
        
        if(by + i * 1 > 7  || bx + i * -1 > 7)
        {

            break;
        }
        if(((board[(by + i * 1)][(bx + i * -1)] !=  " \u265b ") && (board[(by + i * 1)][(bx + i * -1)] !=  " \u265d ")  &&  board[(by + i * 1)][(bx + i * -1)] !=  " * "))
        {
           
            break;
        }
        else if(((board[(by + i * 1)][(bx + i * -1)] ==  " \u265b ") ||(board[(by + i * 1)][(bx + i * -1)] ==  " \u265d "))  )
        {
            
            
            return 2; 
        }
    }

    //Horse check for white king
    if(board[wy - 1][wx - 2] == " \u2658 ")
    {
        return 1;
    }
    else if(board[wy + 1][wx - 2] == " \u2658 ")
    {
        return 1;
    }
    else if(board[wy + 1][wx + 2] == " \u2658 ")
    {
        return 1;

    }
    else if(board[wy - 1][wx + 2] == " \u2658 ")
    {
        return 1;

    }
    else if(board[wy + 2][wx - 1] == " \u2658 ")
    {
        return 1;

    }
    else if(board[wy + 2][wx + 1] == " \u2658 ")
    {
        return 1;

    }
    else if(board[wy - 2][wx - 1] == " \u2658 ")
    {
        return 1;

    }
    else if(board[wy - 2][wx + 1] == " \u2658 ")
    {
        return 1;

    }
    //horse check mate for black king
    else if(board[by - 1][bx - 2] == " \u265e ")
    {
        return 2;
    }
    else if(board[by + 1][bx - 2] == " \u265e ")
    {
        return 2;
    }
    else if(board[by + 1][bx + 2] == " \u265e ")
    {
        return 2;

    }
    else if(board[by - 1][bx + 2] == " \u265e ")
    {
        return 2;

    }
    else if(board[by + 2][bx - 1] == " \u265e ")
    {
        return 2;

    }
    else if(board[by + 2][bx + 1] == " \u265e ")
    {
        return 2;

    }
    else if(board[by - 2][bx - 1] == " \u265e ")
    {
        return 2;

    }
    else if(board[by - 2][bx + 1] == " \u265e ")
    {
        return 2;

    }
    
    
    
    
    
    
    return 0;
}