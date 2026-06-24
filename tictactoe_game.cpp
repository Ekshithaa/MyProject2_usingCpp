#include <iostream>
using namespace std;

char board[3][3] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};

void displayBoard() {
    cout << "\n";
    for(int i = 0; i < 3; i++) {
        cout << " ";
        for(int j = 0; j < 3; j++) {
            cout << board[i][j];
            if(j < 2)
                cout << " | ";
        }
        cout << endl;
        if(i < 2)
            cout << "---|---|---" << endl;
    }
    cout << endl;
}

bool checkWinner() {
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] &&
           board[i][1] == board[i][2])
            return true;
    }

    for(int i = 0; i < 3; i++) {
        if(board[0][i] == board[1][i] &&
           board[1][i] == board[2][i])
            return true;
    }

    if(board[0][0] == board[1][1] &&
       board[1][1] == board[2][2])
        return true;

    if(board[0][2] == board[1][1] &&
       board[1][1] == board[2][0])
        return true;

    return false;
}

int main() {
    char player = 'X';
    int choice, row, col;

    for(int turn = 0; turn < 9; turn++) {
        displayBoard();

        cout << "Player " << player
             << ", enter position (1-9): ";
        cin >> choice;

        row = (choice - 1) / 3;
        col = (choice - 1) % 3;

        if(choice < 1 || choice > 9 ||
           board[row][col] == 'X' ||
           board[row][col] == 'O') {

            cout << "Invalid move! Try again.\n";
            turn--;
            continue;
        }

        board[row][col] = player;
        if(checkWinner()) {
            displayBoard();
            cout << "Player "
                 << player
                 << " wins!\n";
            return 0;
        }
        player = (player == 'X') ? 'O' : 'X';
    }

    displayBoard();
    cout << "Game Draw!\n";

    return 0;
}