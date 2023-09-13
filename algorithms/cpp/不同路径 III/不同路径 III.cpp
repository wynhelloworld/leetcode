// Source : https://leetcode.cn/problems/unique-paths-iii/description/
// Author : Yanan Wang
// Date   : 2023-09-13

class Solution {
private:
    int m, n;
    int count = 0;
    int ans = 0;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    bool used[20][20];
public:
    void dfs(vector<vector<int>> &grid, int i, int j, int step) {
        if (2 == grid[i][j]) {
            if (step == count) {
                ++ans;
            }
            return;
        }
        for (int k = 0; k < 4; ++k) {
            int x = i + dx[k], y = j + dy[k];
            if (x >= 0 && x < m && y >= 0 && y < n && !used[x][y] && -1 != grid[x][y]) {
                used[x][y] = true;
                dfs(grid, x, y, step + 1);
                used[x][y] = false;
            }
        }
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int x, y;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (0 == grid[i][j]) {
                    ++count;
                } else if (1 == grid[i][j]) {
                    x = i, y = j;
                }
            }
        }
        count += 2;
        used[x][y] = true;
        dfs(grid, x, y, 1);
        return ans;
    }
};