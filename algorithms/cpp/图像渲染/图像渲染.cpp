// Source : https://leetcode.cn/problems/number-of-islands/description/ 
// Author : Yanan Wang
// Date   : 2023-09-14

class Solution {
private:
    bool used[300][300];
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int m, n;
public:
    void dfs(vector<vector<char>> &grid, int i, int j) {
        used[i][j] = true;
        for (int k = 0; k < 4; ++k) {
            int x = i + dx[k], y = j + dy[k];
            if (x >= 0 && x < m && y >= 0 && y < n && !used[x][y] && '1' == grid[x][y]) {
                dfs(grid, x, y);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!used[i][j] && '1' == grid[i][j]) {
                    ++ans;
                    used[i][j] = true;
                    dfs(grid, i, j);
                }
            }
        }
        return ans;
    }
};