// Source : https://leetcode.cn/problems/path-with-maximum-gold/description/
// Author : Yanan Wang
// Date   : 2023-09-13

class Solution {
private:
    bool used[15][15];
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int m, n;   
    int ans = 0;
public:
    void dfs(vector<vector<int>> &grid, int i, int j, int path) {
        ans = max(ans, path);
        for (int k = 0; k < 4; ++k) {
            int x = i + dx[k], y = j + dy[k];
            if (x >= 0 && x < m && y >= 0 && y < n && !used[x][y] && 0 != grid[x][y]) {
                used[x][y] = true;
                dfs(grid, x, y, path + grid[x][y]);
                used[x][y] = false;
            }
        } 
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (0 != grid[i][j]) {
                    used[i][j] = true;
                    dfs(grid, i, j, grid[i][j]);
                    used[i][j] = false;
                }
            }
        }
        return ans;
    }
};