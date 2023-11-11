// Source : https://leetcode.cn/problems/map-of-highest-peak/description/
// Author : Yanan Wang
// Date   : 2023-11-11

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>> ans(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isWater[i][j] == 1) {
                    ans[i][j] = 0;
                    q.emplace(i, j);
                }
            }
        }
        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {-1, 1, 0, 0};
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (int k = 0; k < 4; ++k) {
                int x = i + dx[k];
                int y = j + dy[k];
                if (x >= 0 && x < m && y >= 0 && y < n && ans[x][y] == -1) {
                    q.emplace(x, y);
                    ans[x][y] = ans[i][j] + 1;
                }
            }
        }
        return ans;
    }
};