#include <iostream>
#include <vector>
using namespace std;
const int SIZE = 3;
vector<vector<char>> board(SIZE, vector<char>(SIZE, ' '));
char currentPlayer = 'X';
void displayBoard()
{
    cout << "Current Board:\n";
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            cout << board[i][j];
            if (j < SIZE - 1)
                cout << " | ";
        }
        cout << endl;
        if (i < SIZE - 1)
            cout << "--|---|--\n";
    }
}
bool isWin()
{
    // Check rows and columns
    for (int i = 0; i < SIZE; ++i)
    {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
            return true;
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
            return true;
    }
    // Check diagonals
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
        return true;
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
        return true;
    return false;
}
bool isDraw()
{
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}
void switchPlayer()
{
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}
void makeMove()
{
    int row, col;
    while (true)
    {
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;
        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ')
        {
            board[row][col] = currentPlayer;
            break;
        }
        else
        {
            cout << "Invalid move. Try again.\n";
        }
    }
}
void playGame()
{
    while (true)
    {
        displayBoard();
        makeMove();
        if (isWin())
        {
            displayBoard();
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }
        if (isDraw())
        {
            displayBoard();
            cout << "The game is a draw!\n";
            break;
        }
        switchPlayer();
    }
}
int main()
{
    char playAgain;
    do
    {
        board = vector<vector<char>>(SIZE, vector<char>(SIZE, ' '));
        currentPlayer = 'X';
        playGame();
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y');

    return 0;
}
