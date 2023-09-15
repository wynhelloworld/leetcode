// Source : https://leetcode.cn/problems/surrounded-regions/description/  
// Author : Yanan Wang
// Date   : 2023-09-15

class Solution {
private:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int m, n;
public:
    void dfs(vector<vector<char>> &board, int i, int j) {
        board[i][j] = '.';
        for (int k = 0; k < 4; ++k) {
            int x = i + dx[k], y = j + dy[k];
            if (x >= 0 && x < m && y >= 0 && y < n && 'O' == board[x][y]) {
                dfs(board, x, y);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {
            if ('O' == board[i][0]) dfs(board, i, 0);
            if ('O' == board[i][n - 1]) dfs(board, i, n - 1);
        }
        for (int j = 0; j < n; ++j) {
            if ('O' == board[0][j]) dfs(board, 0, j);
            if ('O' == board[m - 1][j]) dfs(board, m - 1, j);
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if ('O' == board[i][j]) {
                    board[i][j] = 'X';
                } else if ('.' == board[i][j]) {
                    board[i][j] = 'O';
                }
            }
        }
    }
};