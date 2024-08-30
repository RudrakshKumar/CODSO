#include <iostream>
using namespace std;

// Function to display the Tic-Tac-Toe board
void displayBoard(char board[3][3]) {
    cout << "Current board state:" << endl << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << "   |   ";
        }
        cout << endl<< endl;
        if (i < 2) cout << "- - | - - - | - -" << endl << endl;
    }
}

// Function to check if the current player has won
bool checkWin(char board[3][3], char player) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

// Function to check if the game is a draw
bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

// Function to switch players
char switchPlayer(char currentPlayer) {
    return (currentPlayer == 'X') ? 'O' : 'X';
}

// Main function
int main() {
    char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    char currentPlayer = 'X';
    bool gameOver = false;

    cout << "Welcome to Tic-Tac-Toe!" << endl << endl;

    while (!gameOver) {
        displayBoard(board);

        // Get player input
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        // Validate input
        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            cout << "Invalid move. Try again." << endl << endl;
            continue;
        }

        // Update board with player's move
        board[row - 1][col - 1] = currentPlayer;

        // Check for a win or a draw
        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl << endl;
            gameOver = true;
        } else if (checkDraw(board)) {
            displayBoard(board);
            cout << "The game is a draw!" << endl << endl;
            gameOver = true;
        } else {
            // Switch to the next player
            currentPlayer = switchPlayer(currentPlayer);
        }
    }

    // Ask if players want to play again
    char playAgain;
    cout << "Do you want to play again? (y/n): ";
    cin >> playAgain;

    if (playAgain == 'y' || playAgain == 'Y') {
        main(); // Restart the game
    }

    return 0;
}
