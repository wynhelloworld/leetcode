// Source : https://leetcode.cn/problems/number-of-enclaves/description/
// Author : Yanan Wang
// Date   : 2023-11-10

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n));

        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            if (grid[i][0] == 1) {
                q.emplace(i, 0);
                vis[i][0] = true;
            }            
            if (grid[i][n - 1] == 1) {
                q.emplace(i, n - 1);
                vis[i][n - 1] = true;
            }
        }
        for (int j = 0; j < n; ++j) {
            if (grid[0][j] == 1) {
                q.emplace(0, j);
                vis[0][j] = true;
            }
            if (grid[m - 1][j] == 1) {
                q.emplace(m - 1, j);
                vis[m - 1][j] = true;
            }
        }
        
        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {-1, 1, 0, 0};
        while(!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (int k = 0; k < 4; ++k) {
                int x = i + dx[k];
                int y = j + dy[k];
                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1 && !vis[x][y]) {
                    q.emplace(x, y);
                    vis[x][y] = true;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    ++ans;
                }
            }
        }
        return ans;
    }
    
};