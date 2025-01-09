class Solution {
public:
    int count;
    int N;

    bool isValid(vector<string>& board, int row, int col) {
        // Look Upward
        for (int i = row - 1; i >= 0; i--) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }

        // Left diagonal upwards
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        // Right diagonal upwards
        for (int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }

    void solve(vector<string>& board, int row) {
        if (row == N) {
            count++;
            return;
        }

        for (int col = 0; col < N; col++) {
            if (isValid(board, row, col)) {
                board[row][col] = 'Q';
                solve(board, row + 1);
                board[row][col] = '.';
            }
        }
    }
    int totalNQueens(int n) {

        vector<string> board(n, string(n, '.'));
        N = n;
        solve(board, 0);
        return count;
        
    }
};
