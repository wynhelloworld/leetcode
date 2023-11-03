// Source : https://leetcode.cn/problems/surrounded-regions/description/  
// Author : Yanan Wang
// Date   : 2023-09-15

/* 解法一: DFS */
class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int m, n;

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

    void dfs(vector<vector<char>> &board, int i, int j) {
        board[i][j] = '.';
        for (int k = 0; k < 4; ++k) {
            int x = i + dx[k]; 
            int y = j + dy[k];
            if (x >= 0 && x < m && y >= 0 && y < n && 'O' == board[x][y]) {
                dfs(board, x, y);
            }
        }
    }
};


/* 解法二: BFS */
class Solution {
public:
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    int m, n;

    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();

        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O') {
                bfs(board, i, 0);
            }
            if (board[i][n - 1] == 'O') {
                bfs(board, i, n - 1);
            }
        }
        for (int j = 0; j < n; ++j) {
            if (board[0][j] == 'O') {
                bfs(board, 0, j);
            }
            if (board[m - 1][j] == 'O') {
                bfs(board, m - 1, j);
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == '.') {
                    board[i][j] = 'O';
                }
            }
        }
    }

    void bfs(vector<vector<char>> &board, int i, int j) {
        queue<pair<int, int>> q;
        q.push({i, j});
        board[i][j] = '.';
        while(!q.empty()) {
            auto [a, b] = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int x = a + dx[i];
                int y = b + dy[i];
                if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'O') {
                    q.push({x, y});
                    board[x][y] = '.';
                }
            }
        }
    }
};