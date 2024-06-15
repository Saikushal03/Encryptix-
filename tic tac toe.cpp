#include <iostream>
#include <vector>

using namespace std;

class TicTacToe {
public:
    TicTacToe() {
        board = vector<vector<char>>(3, vector<char>(3, ' '));
        currentPlayer = 'X';
        gameStatus = "ongoing";
    }

    void displayBoard() {
        cout << "  0 1 2\n";
        for (int i = 0; i < 3; ++i) {
            cout << i << " ";
            for (int j = 0; j < 3; ++j) {
                cout << board[i][j];
                if (j < 2) cout << "|";
            }
            cout << "\n";
            if (i < 2) cout << "  -----\n";
        }
    }

    void playGame() {
        while (gameStatus == "ongoing") {
            displayBoard();
            playerMove();
            updateGameStatus();
            switchPlayers();
        }
        displayBoard();
        displayResult();
    }

    void resetGame() {
        board = vector<vector<char>>(3, vector<char>(3, ' '));
        currentPlayer = 'X';
        gameStatus = "ongoing";
    }

private:
    vector<vector<char>> board;
    char currentPlayer;
    string gameStatus;

    void playerMove() {
        int row, col;
        while (true) {
            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            cin >> row >> col;
            if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
                board[row][col] = currentPlayer;
                break;
            } else {
                cout << "Invalid move. Try again.\n";
            }
        }
    }

    void updateGameStatus() {
        if (checkWin()) {
            gameStatus = currentPlayer == 'X' ? "X wins" : "O wins";
        } else if (checkDraw()) {
            gameStatus = "draw";
        }
    }

    bool checkWin() {
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
                return true;
            if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
                return true;
        }
        if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
            return true;
        if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
            return true;
        return false;
    }

    bool checkDraw() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == ' ')
                    return false;
            }
        }
        return true;
    }

    void switchPlayers() {
        if (gameStatus == "ongoing") {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    void displayResult() {
        if (gameStatus == "X wins") {
            cout << "Player X wins!\n";
        } else if (gameStatus == "O wins") {
            cout << "Player O wins!\n";
        } else if (gameStatus == "draw") {
            cout << "The game is a draw!\n";
        }
    }
};

int main() {
    TicTacToe game;
    char playAgain = 'y';
    while (playAgain == 'y' || playAgain == 'Y') {
        game.playGame();
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
        if (playAgain == 'y' || playAgain == 'Y') {
            game.resetGame();
        }
    }
    return 0;
}
