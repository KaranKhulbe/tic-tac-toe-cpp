#include <iostream>
#include <vector>
using namespace std;

// Function to draw the Tic-Tac-Toe board
void drawBoard(const vector<vector<char>>& board) {
    cout << "\n";
    for (int i = 0; i < 3; ++i) {
        cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << " \n";
        if (i < 2) cout << "-----------\n";
    }
    cout << "\n";
}

// Function to check if a player has won
bool checkWin(const vector<vector<char>>& board, char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true; // Rows
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true; // Columns
    }
    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
    return false;
}

// Function to check if the board is full (tie)
bool checkTie(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') return false;
        }
    }
    return true;
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' ')); // 3x3 board initialized with spaces
    char currentPlayer = 'X';
    int row, col;
    bool gameOver = false;

    cout << "=== Tic-Tac-Toe Game ===\n";
    cout << "Player 1: X | Player 2: O\n\n";

    while (!gameOver) {
        drawBoard(board);

        // Get player input
        cout << "Player " << currentPlayer << ", enter row (1-3) and column (1-3): ";
        cin >> row >> col;
        row--; // Convert to 0-based index
        col--;

        // Validate input
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            cout << "Invalid move! Try again.\n";
            continue;
        }

        // Update board
        board[row][col] = currentPlayer;

        // Check for win
        if (checkWin(board, currentPlayer)) {
            drawBoard(board);
            cout << "Player " << currentPlayer << " wins!\n";
            gameOver = true;
        }
        // Check for tie
        else if (checkTie(board)) {
            drawBoard(board);
            cout << "It's a tie!\n";
            gameOver = true;
        }
        // Switch player
        else {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    cout << "Game Over!\n";
    return 0;
}