#include <iostream>
#include <cstdlib> // For rand()
#include <ctime>   // For seeding random numbers
using namespace std;

char board[3][3]; // Tic-Tac-Toe boards

void displayBoard() {
    cout << "  0   1   2\n"; // Column numbers
    for (int i = 0; i < 3; ++i) {
        if (i > 0) cout << " ----+---+----\n"; // Horizontal divider
        cout << i << " "; // Row numbers
        for (int j = 0; j < 3; ++j) {
            if (j > 0) cout << "|"; // Vertical divider
            cout << " " << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool isValidMove(int row, int col) {
    return row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ';
}

void computerMove() {
    int row, col;
    do {
        row = rand() % 3;
        col = rand() % 3;
    } while (!isValidMove(row, col));
    board[row][col] = 'O'; // Computer uses 'O'
    cout << "Computer chose row " << row << " and column " << col << endl;
}

void userMove() {
    int row, col;
    do {
        cout << "Enter row (0-2) and column (0-2): ";
        cin >> row >> col;
        if (!isValidMove(row, col)) {
            cout << "Invalid move. Try again.\n";
        }
    } while (!isValidMove(row, col));
    board[row][col] = 'X'; // User uses 'X'
}

bool checkWinner(char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
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

bool isBoardFull() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') return false;
        }
    }
    return true;
}

int main() {
    srand(time(0)); // Seed random number generator
    // Initialize board with spaces
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }

    cout << "Welcome to Tic-Tac-Toe!\n";
    displayBoard();

    bool userTurn = true; // User starts the game
    while (true) {
        if (userTurn) {
            cout << "\nUser's turn:\n";
            userMove();
        } else {
            cout << "\nComputer's turn:\n";
            computerMove();
        }
        displayBoard();

        // Check for winner
        if (checkWinner(userTurn ? 'X' : 'O')) {
            cout << (userTurn ? "User" : "Computer") << " wins!\n";
            break;
        }

        // Check for a draw
        if (isBoardFull()) {
            cout << "It's a draw!\n";
            break;
        }

        // Switch turns
        userTurn = !userTurn;
    }

    return 0;
}


