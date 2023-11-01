// Source : https://leetcode.cn/problems/flood-fill/description/ 
// Author : Yanan Wang
// Date   : 2023-09-14

/* 解法一: DFS */
class Solution {
public:
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    bool used[300][300] = { false };
    int m, n;

    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1' && !used[i][j]) {
                    dfs(grid, i, j);
                    ++ans;
                }
            }
        }
        return ans;
    }

    void dfs(vector<vector<char>> &grid, int i, int j) {
        used[i][j] = true;
        for (int k = 0; k < 4; ++k) {
            int x = i + dx[k], y = j + dy[k];
            if (x >= 0 && x < m && y >= 0 && y < n && !used[x][y] && '1' == grid[x][y]) {
                dfs(grid, x, y);
            }
        }
    }
};


/* 解法二: BFS */
class Solution {
public:
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    bool used[300][300] = { false };
    int m, n;

    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1' && !used[i][j]) {
                    bfs(grid, i, j);
                    ++ans;
                }
            }
        }  
        return ans;
    }

    void bfs(vector<vector<char>> &grid, int i, int j) {
        queue<pair<int, int>> q;
        q.push({i, j});
        used[i][j] = true;
        
        while (!q.empty()) {
            auto [a, b] = q.front();
            q.pop();
            for (int k = 0; k < 4; ++k) {
                int x = a + dx[k];
                int y = b + dy[k];
                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == '1' && !used[x][y]) {
                    q.push({x, y});
                    used[x][y] = true;
                }
            }
        }
    }
};