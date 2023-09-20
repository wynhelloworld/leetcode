// Source : https://leetcode.cn/problems/longest-increasing-path-in-a-matrix/description/ 
// Author : Yanan Wang
// Date   : 2023-09-20

class Solution {
private:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int m, n;
    int memory[200][200];
public:
    int dfs(vector<vector<int>> &matrix, int i, int j) {
        if (memory[i][j] != 0) {
            return memory[i][j];
        }
        int cnt = 0;
        for (int k = 0; k < 4; ++k) {
            int x = i + dx[k], y = j + dy[k];
            if (x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > matrix[i][j]) {
                cnt = max(cnt, dfs(matrix, x, y)); 
            }
        }
        memory[i][j] = cnt + 1;
        return memory[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans = 0;
        m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans = max(ans, dfs(matrix, i, j));
            }
        }
        return ans;
    }
};