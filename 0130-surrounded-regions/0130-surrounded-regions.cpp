class Solution {
public:

    void fill (vector<vector<char>> &board, int i, int j) {
        if (i < 0 || j < 0 || i >= board.size () || j >= board[i].size () || board[i][j] != 'O')
            return;

        board[i][j] = '1';

        fill (board, i + 1, j);
        fill (board, i - 1, j);
        fill (board, i, j + 1);
        fill (board, i, j - 1);
    }

    void solve(vector<vector<char>>& board) {
        for (int i = 0; i < board[0].size (); i++) {
            if (board[0][i] == 'O') fill (board, 0, i);
            if (board[board.size () - 1][i] == 'O') fill (board, board.size () - 1, i);
        }

        for (int i = 1; i < board.size () - 1; i++) {
            if (board[i][0] == 'O') fill (board, i, 0);
            if (board[i][board[0].size () - 1] == 'O') fill (board, i, board[0].size () - 1);
        }

        for (int i = 0; i < board.size (); i++) {
            for (int j = 0; j < board[i].size (); j++) {
                if (board[i][j] != '1') board[i][j] = 'X';
                if (board[i][j] == '1') board[i][j] = 'O';
            }
        }
    }
};