// Source : https://leetcode.cn/problems/nearest-exit-from-entrance-in-maze/description/
// Author : Yanan Wang
// Date   : 2023-11-04

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {-1, 1, 0, 0};
        int m = maze.size();
        int n = maze[0].size();
        vector<vector<bool>> used(100, vector<bool>(100));

        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        used[entrance[0]][entrance[1]] = true;

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
                    if (x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == '.' && !used[x][y]) {
                        if (x == 0 || x == m - 1 || y == 0 || y == n - 1) {
                            return ans;
                        }
                        q.push({x, y});
                        used[x][y] = true;
                    }
                }
            }
        }
        return -1;
    }
};