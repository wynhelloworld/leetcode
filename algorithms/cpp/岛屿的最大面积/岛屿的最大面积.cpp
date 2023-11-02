// Source : https://leetcode.cn/problems/max-area-of-island/description/ 
// Author : Yanan Wang
// Date   : 2023-09-15

/* 解法一: DFS */
class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    bool used[50][50];
    int m, n;
    
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

/* 解法二: BFS */
class Solution {
public:
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    bool used[50][50] = { false };
    int m, n;
    int ans = 0;

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && !used[i][j]) {
                    bfs(grid, i, j);
                }
            }
        }
        return ans;
    }

    void bfs(vector<vector<int>> &grid, int i, int j) {
        queue<pair<int, int>> q;
        q.push({i, j});
        used[i][j] = true;
        
        int cnt = 0;
        while (!q.empty()) {
            ++cnt;
            auto [a, b] = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int x = a + dx[i];
                int y = b + dy[i];
                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1 && !used[x][y]) {
                    q.push({x, y});
                    used[x][y] = true;
                }
            }            
        }
        ans = max(ans, cnt);
    }
};