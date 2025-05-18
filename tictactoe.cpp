#include<iostream>
using namespace std;
#include <iostream>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, 
                     {'4', '5', '6'}, 
                     {'7', '8', '9'}};
char currentPlayer = 'X';

void drawBoard() {
    cout << "Tic-Tac-Toe Game\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;
    return false;
}

void playerMove() {
    int choice;
    cout << "Player " << currentPlayer << ", enter position (1-9): ";
    cin >> choice;

    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentPlayer;
    } else {
        cout << "Invalid move! Try again.\n";
        playerMove();
    }
}

void playGame() {
    int moves = 0;
    while (moves < 9) {
        drawBoard();
        playerMove();
        moves++;

        if (checkWin()) {
            drawBoard();
            cout << "Player " << currentPlayer << " wins!\n";
            return;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
    cout << "It's a tie!\n";
}

int main() {
    playGame();
    return 0;
}

