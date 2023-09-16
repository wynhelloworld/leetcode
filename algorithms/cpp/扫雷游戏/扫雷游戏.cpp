// Source : https://leetcode.cn/problems/minesweeper/description/ 
// Author : Yanan Wang
// Date   : 2023-09-16

class Solution {
private:
    int m, n;
    int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
    int dy[8] = {1, -1, 0, 0, -1, 1, 1, -1};
public:
    void dfs(vector<vector<char>> &board, int i, int j) {
        int count = 0;
        for (int k = 0; k < 8; ++k) {
            int x = i + dx[k], y = j + dy[k];
            if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'M') {
                ++count;
            }
        }
        if (count == 0) {
            board[i][j] = 'B';
            for (int k = 0; k < 8; ++k) {
                int x = i + dx[k], y = j + dy[k];
                if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'E') {
                    dfs(board, x, y);
                }
            }
        } else {
            board[i][j] = count + '0';
        }
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        m = board.size(), n = board[0].size();
        dfs(board, click[0], click[1]);
        return board;
    }
};