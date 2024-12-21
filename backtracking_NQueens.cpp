#include <iostream>
#include <vector>
#include <set>

using namespace std;

template <typename T>

void print(vector<vector<T>> v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

bool checkQ(vector<vector<char>> & chessBoard, int row, int col) {
    bool result = false;
    int n = chessBoard.size();
    //check row
    for (char c : chessBoard[row]) {
        if (c == 'Q') result = true;
    }
    //check column
    for (int i = 0; i < n; i++) {
        if (chessBoard[i][col] == 'Q') result = true;
    }
    //check hypertenuse
    for (int r = row,c = col; r >= 0 && c >= 0; r--, c--) {
        if (chessBoard[r][c] == 'Q') result = true;
    }
    for (int r = row,c = col; r <= n - 1&& c <= n - 1; r++, c++) {
        if (chessBoard[r][c] == 'Q') result = true;
    }
    for (int r = row,c = col; r >= 0 && c <= n - 1; r--, c++) {
        if (chessBoard[r][c] == 'Q') result = true;
    }
    for (int r = row,c = col; r <= n - 1&& c >= 0; r++, c--) {
        if (chessBoard[r][c] == 'Q') result = true;
    }
    return result;
}

vector<vector<vector<char>>> Solutions;

void findS(vector<vector<char>> & chessBoard, int N, int n) {
    //quit condition
    if (N == 0) {
        Solutions.push_back(chessBoard);
        return;
    }

    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) {
            if (!checkQ(chessBoard, i, j)) {
                chessBoard[i][j] = 'Q';
                findS(chessBoard, N-1, n);
                chessBoard[i][j] = '.';
            }
        }
}

int main() {
    int n;
    cin >> n;
    vector<vector<char>> chessBoard(n, vector<char>(n, '.'));
    findS(chessBoard, n, n);
    set<vector<vector<char>>> s(Solutions.begin(), Solutions.end());
    Solutions.assign(s.begin(), s.end());
    for (auto c : Solutions) {
        print(c);
        cout << "\n";
    }
    return 0;
}

//improved version by AI:
// #include <iostream>
// #include <vector>
// #include <set>

// using namespace std;

// template <typename T>
// void print(const vector<vector<T>>& v) {
//     for (const auto& row : v) {
//         for (const auto& elem : row) {
//             cout << elem << " ";
//         }
//         cout << endl;
//     }
// }

// bool checkQ(const vector<vector<char>>& chessBoard, int row, int col) {
//     int n = chessBoard.size();
//     // Check row
//     for (int i = 0; i < n; ++i) {
//         if (chessBoard[row][i] == 'Q') return true;
//     }
//     // Check column
//     for (int i = 0; i < n; ++i) {
//         if (chessBoard[i][col] == 'Q') return true;
//     }
//     // Check main diagonal (top-left to bottom-right)
//     for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
//         if (chessBoard[i][j] == 'Q') return true;
//     }
//     for (int i = row, j = col; i < n && j < n; ++i, ++j) {
//         if (chessBoard[i][j] == 'Q') return true;
//     }
//     // Check anti-diagonal (top-right to bottom-left)
//     for (int i = row, j = col; i >= 0 && j < n; --i, ++j) {
//         if (chessBoard[i][j] == 'Q') return true;
//     }
//     for (int i = row, j = col; i < n && j >= 0; ++i, --j) {
//         if (chessBoard[i][j] == 'Q') return true;
//     }
//     return false;
// }

// vector<vector<vector<char>>> Solutions;

// void findS(vector<vector<char>>& chessBoard, int N, int row) {
//     // Quit condition
//     if (N == 0) {
//         Solutions.push_back(chessBoard);
//         return;
//     }

//     int n = chessBoard.size();
//     for (int col = 0; col < n; ++col) {
//         if (!checkQ(chessBoard, row, col)) {
//             chessBoard[row][col] = 'Q';
//             findS(chessBoard, N - 1, row + 1);
//             chessBoard[row][col] = '.';  // Backtrack
//         }
//     }
// }

// int main() {
//     int n;
//     cin >> n;
//     vector<vector<char>> chessBoard(n, vector<char>(n, '.'));
//     findS(chessBoard, n, 0);
//     set<vector<vector<char>>> s(Solutions.begin(), Solutions.end());
//     Solutions.assign(s.begin(), s.end());
//     for (const auto& c : Solutions) {
//         print(c);
//         cout << "\n";
//     }
//     return 0;
// }


//effifeint answer:
// #include <iostream>
// #include <vector>
// #include <string>
// using namespace std;

// // Function to print the board
// void printBoard(const vector<string>& board) {
//     for (const auto& row : board) {
//         cout << row << endl;
//     }
//     cout << endl;
// }

// // Function to check if a queen can be placed at board[row][col]
// bool isSafe(const vector<string>& board, int row, int col, int N) {
//     // Check this row on left side
//     for (int i = 0; i < col; i++) {
//         if (board[row][i] == 'Q') {
//             return false;
//         }
//     }
//     // Check upper diagonal on left side
//     for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
//         if (board[i][j] == 'Q') {
//             return false;
//         }
//     }
//     // Check lower diagonal on left side
//     for (int i = row, j = col; i < N && j >= 0; i++, j--) {
//         if (board[i][j] == 'Q') {
//             return false;
//         }
//     }
//     return true;
// }

// // Recursive function to solve N-Queens problem
// void solveNQueens(vector<string>& board, int col, int N, vector<vector<string>>& solutions) {
//     // Base case: If all queens are placed, add the board to solutions
//     if (col >= N) {
//         solutions.push_back(board);
//         return;
//     }
//     // Consider this column and try placing this queen in all rows one by one
//     for (int i = 0; i < N; i++) {
//         if (isSafe(board, i, col, N)) {
//             // Place this queen
//             board[i][col] = 'Q';
//             // Recur to place the rest of the queens
//             solveNQueens(board, col + 1, N, solutions);
//             // If placing queen in board[i][col] doesn't lead to a solution,
//             // then remove the queen (backtrack)
//             board[i][col] = '.';
//         }
//     }
// }

// // Function to solve the N-Queens problem
// vector<vector<string>> solveNQueens(int N) {
//     vector<vector<string>> solutions;
//     // Initialize the board
//     vector<string> board(N, string(N, '.'));
//     // Start the backtracking process from the first column
//     solveNQueens(board, 0, N, solutions);
//     return solutions;
// }

// int main() {
//     int N;
//     cout << "Enter the value of N: ";
//     cin >> N;
//     vector<vector<string>> solutions = solveNQueens(N);
//     for (const auto& solution : solutions) {
//         printBoard(solution);
//     }
//     return 0;
// }
