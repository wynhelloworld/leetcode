// Source : https://leetcode.cn/problems/max-area-of-island/description/ 
// Author : Yanan Wang
// Date   : 2023-09-15

class Solution {
private:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    bool used[50][50];
    int m, n;
public:
    int dfs(vector<vector<int>> &grid, int i, int j) {
        int sum = 1;
        used[i][j] = true;
        for (int k = 0; k < 4; ++k) {
            int x = i + dx[k], y = j + dy[k];
            if (x >= 0 && x < m && y >= 0 && y < n && !used[x][y] && 1 == grid[x][y]) {
                sum += dfs(grid, x, y);
            }
        }
        return sum;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!used[i][j] && 1 == grid[i][j]) {
                    ans = max(ans, dfs(grid, i, j));
                }
            }
        }
        return ans;
    }
};