// tic_tac_toe.cpp
// Console Tic-Tac-Toe for two players with replay option

#include <iostream>
#include <vector>
#include <limits>
using namespace std;

void drawBoard(const vector<char>& b) {
    cout << "\n";
    cout << " " << b[0] << " | " << b[1] << " | " << b[2] << "\n";
    cout << "---+---+---\n";
    cout << " " << b[3] << " | " << b[4] << " | " << b[5] << "\n";
    cout << "---+---+---\n";
    cout << " " << b[6] << " | " << b[7] << " | " << b[8] << "\n\n";
}

bool checkWin(const vector<char>& b, char p) {
    const int wins[8][3] = {
        {0,1,2}, {3,4,5}, {6,7,8}, // rows
        {0,3,6}, {1,4,7}, {2,5,8}, // cols
        {0,4,8}, {2,4,6}           // diagonals
    };
    for (auto &w : wins) {
        if (b[w[0]] == p && b[w[1]] == p && b[w[2]] == p) return true;
    }
    return false;
}

bool isDraw(const vector<char>& b) {
    for (char c : b) if (c == ' ') return false;
    return true;
}

int getMove(const vector<char>& b, char player) {
    int cell;
    while (true) {
        cout << "Player " << player << ", enter cell (1-9): ";
        if (!(cin >> cell)) {
            cout << "❌ Invalid input. Enter a number 1-9.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (cell < 1 || cell > 9) {
            cout << "❌ Choose between 1 and 9.\n";
            continue;
        }
        if (b[cell-1] != ' ') {
            cout << "❌ Cell already taken. Choose another.\n";
            continue;
        }
        return cell-1; // zero-based index
    }
}

int main() {
    cout << "=== Tic-Tac-Toe ===\n";
    bool playAgain = true;
    while (playAgain) {
        vector<char> board(9, ' '); // 3x3 board stored as 0..8
        char player = 'X';
        bool finished = false;

        cout << "\nCells are numbered 1 to 9 like this:\n";
        cout << " 1 | 2 | 3\n";
        cout << "---+---+---\n";
        cout << " 4 | 5 | 6\n";
        cout << "---+---+---\n";
        cout << " 7 | 8 | 9\n";

        while (!finished) {
            drawBoard(board);
            int move = getMove(board, player);
            board[move] = player;

            if (checkWin(board, player)) {
                drawBoard(board);
                cout << "🎉 Player " << player << " wins!\n";
                finished = true;
            } else if (isDraw(board)) {
                drawBoard(board);
                cout << "🤝 It's a draw!\n";
                finished = true;
            } else {
                // switch player
                player = (player == 'X') ? 'O' : 'X';
            }
        }

        cout << "\nPlay again? (y/n): ";
        char ans; cin >> ans;
        playAgain = (ans == 'y' || ans == 'Y');
        cout << '\n';
    }

    cout << "Thanks for playing Tic-Tac-Toe! 👋\n";
    return 0;
}
