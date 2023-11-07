// Source : https://leetcode.cn/problems/cut-off-trees-for-golf-event/description/
// Author : Yanan Wang
// Date   : 2023-11-07

class Solution {
public:
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    int m, n;

    int cutOffTree(vector<vector<int>>& forest) {
        m = forest.size();
        n = forest[0].size();
        vector<pair<int, int>> indices;       
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (forest[i][j] > 1) {
                    indices.emplace_back(i, j);
                }
            }
        }
        sort(indices.begin(), indices.end(), [&](const pair<int, int> &lhs, const  pair<int, int> &rhs){
            return forest[lhs.first][lhs.second] < forest[rhs.first][rhs.second];
        });

        int ans = 0;
        pair<int, int> in(0, 0);
        for (int i = 0; i < indices.size(); ++i) {
            int n = bfs(forest, in, indices[i]);
            if (n == -1) {
                return -1;
            }
            ans += n;
            in = indices[i];
        }
        return ans;
    }

    int bfs(vector<vector<int>> &forest, const pair<int, int> &in, const pair<int, int> &out) {
        if (in == out) {
            return 0;
        }
        vector<vector<bool>> vis(m, vector<bool>(n));

        queue<pair<int, int>> q;
        q.emplace(in.first, in.second);
        vis[in.first][in.second] = true;
        int ans = 0;
        while (!q.empty()) {
            ++ans;
            int size = q.size();
            while (size--) {
                auto [a, b] = q.front();
                q.pop();
                for (int i = 0; i < 4; ++i) {
                    int x = a + dx[i];
                    int y = b + dy[i];
                    if (x >= 0 && x < m && y >= 0 && y < n && forest[x][y] != 0 && !vis[x][y]) {
                        if (x == out.first && y == out.second) {
                            return ans;
                        }
                        q.emplace(x, y);
                        vis[x][y] = true;
                    }
                }
            }
        }
        return -1;
    }
};