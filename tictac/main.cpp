#include <iostream>
using namespace std;

int main()
{

    char board[][] = {{'-', '-', '-'}, {'-', '-', '-'}, {'-', '-', '-'}};

    return 0;
}

int checkForWin(char board[][], char you, char other)
{

    if (board[0][0] == you, board[0][1] == you, board[0][2] == you)
    {
        return true;
    }
    if (board[1][0] == you, board[1][1] == you, board[1][2] == you)
    {
        return true;
    }
    if (board[2][0] == you, board[2][1] == you, board[2][2] == you)
    {
        return true;
    }
    if (board[0][0] == you, board[2][1] == you, board[3][2] == you)
    {
        return true;
    }
    if (board[3][0] == you, board[2][1] == you, board[0][2] == you)
    {
        return true;
    }
    if (board[0][0] == you, board[1][0] == you, board[2][0] == you)
    {
        return true;
    }
    if (board[0][1] == you, board[1][1] == you, board[2][1] == you)
    {
        return true;
    }
    if (board[0][2] == you, board[1][2] == you, board[2][2] == you)
    {
        return true;
    }
    

        if (board[0][0] == other, board[0][1] == other, board[0][2] == other)
    {
        return false;
    }
    if (board[1][0] == other, board[1][1] == other, board[1][2] == other)
    {
        return false;
    }
    if (board[2][0] == other, board[2][1] == other, board[2][2] == other)
    {
        return false;
    }
    if (board[0][0] == other, board[2][1] == other, board[3][2] == other)
    {
        return false;
    }
    if (board[3][0] == other, board[2][1] == other, board[0][2] == other)
    {
        return false;
    }
    if (board[0][0] == other, board[1][0] == other, board[2][0] == other)
    {
        return false;
    }
    if (board[0][1] == other, board[1][1] == other, board[2][1] == other)
    {
        return false;
    }
    if (board[0][2] == other, board[1][2] == other, board[2][2] == other)
    {
        return false;
    }
}










































