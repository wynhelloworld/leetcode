// Source : https://leetcode.cn/problems/01-matrix/description/
// Author : Yanan Wang
// Date   : 2023-11-09

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 1) {
                    dist[i][j] = -1;
                } else {
                    q.emplace(i, j);
                }
            }
        }
        
        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {-1, 1, 0, 0};
        while(!q.empty()) {
            auto [a, b] = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int x = a + dx[i];
                int y = b + dy[i];
                if (x >= 0 && x < m && y >= 0 && y < n && dist[x][y] == -1) {
                    dist[x][y] = dist[a][b] + 1;
                    q.emplace(x, y);
                }
            } 
        }
        return dist;
    }
};