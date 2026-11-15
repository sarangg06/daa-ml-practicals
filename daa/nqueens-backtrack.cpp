#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void printBoard(const vector<vector<int>> &board, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << (board[i][j] ? "Q " : ". ");
        }
        cout << "\n";
    }
}

// Function to check if it's safe to place a queen at board[row][col]
bool isSafe(const vector<vector<int>> &board, int row, int col, int n)
{
    // Check the same column
    for (int i = 0; i < n; i++)
    {
        if (board[i][col] && i != row)
            return false;
    }
    // Check the same row
    for (int j = 0; j < n; j++)
    {
        if (board[row][j] && j != col)
            return false;
    }
    // Check all diagonals
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j])
            {
                if (i == row && j == col)
                    continue;
                if (abs(i - row) == abs(j - col))
                    return false;
            }
        }
    }
    return true;
}

// Backtracking function
bool solveNQueens(vector<vector<int>> &board, int row, int n, int firstRow)
{
    // If all queens are placed
    if (row == n)
        return true;

    // Skip the row where the first queen is already manually placed
    if (row == firstRow)
    {
        return solveNQueens(board, row + 1, n, firstRow);
    }

    // Try placing a queen in all columns of the current row
    for (int col = 0; col < n; col++)
    {
        if (isSafe(board, row, col, n))
        {
            board[row][col] = 1;

            if (solveNQueens(board, row + 1, n, firstRow))
                return true;

            board[row][col] = 0; // Backtrack
        }
    }
    return false; // Triggers backtracking
}

int main()
{
    int n = 8;
    vector<vector<int>> board(n, vector<int>(n, 0));

    // Condition: First Queen is already placed at a specific position
    int firstQ_row = 0;
    int firstQ_col = 3;
    board[firstQ_row][firstQ_col] = 1;

    cout << "Placing remaining queens around Queen at (" << firstQ_row << ", " << firstQ_col << ")...\n\n";

    if (solveNQueens(board, 0, n, firstQ_row))
    {
        printBoard(board, n);
    }
    else
    {
        cout << "No solution exists for this initial placement." << endl;
    }

    return 0;
}