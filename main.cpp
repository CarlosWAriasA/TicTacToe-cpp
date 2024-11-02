#include <iostream>
#include <cstdlib>
using namespace std;

// global variables
const char initialValue = '_';
const char xPlayer = 'X';
const char oPlayer = 'O';
char board[][3] = {{initialValue, initialValue, initialValue}, {initialValue, initialValue, initialValue}, {initialValue, initialValue, initialValue}};
char activePlayer = xPlayer;

// methods
char isWinner()
{
    // horizontal validation
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] != initialValue && board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            return board[i][0];
        }
    }

    // vertical validation
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] != initialValue && board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            return board[0][i];
        }
    }

    // diagonal validation from right to left
    if (board[0][2] != initialValue && board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        return board[0][0];
    }

    // diagonal validation from left to right
    if (board[0][0] != initialValue && board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        return board[0][0];
    }

    return initialValue;
}

bool isDraw()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j])
            {
                return false;
            }
        }
    }

    return true;
}

void showBoard()
{
    int row = 0;
    int column = 0;

    cout << "\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\n";
    cout << "Player " << activePlayer << " play" << endl;
    cout << "Row to Play (1-3): " << endl;
    cin >> row;

    cout << "Column to Play (1-3): " << endl;
    cin >> column;

    board[row - 1][column - 1] = activePlayer;

    char winner = isWinner();
    if (winner != initialValue)
    {
        cout << "Player " << winner << " won" << endl;
        exit(0);
    }

    if (isDraw())
    {
        cout << "Tied, nobody wins" << endl;
        exit(0);
    }

    // changing player
    activePlayer = activePlayer == xPlayer ? oPlayer : xPlayer;
}

int main()
{
    while (true)
    {
        showBoard();
    }
}