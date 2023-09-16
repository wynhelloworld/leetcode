// Source : https://leetcode.cn/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/description/ 
// Author : Yanan Wang
// Date   : 2023-09-16

class Solution {
private:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    bool used[100][100];
    int m, n, k;
    int ans;
public:
    bool check(int x, int y) {
        int sum = 0;
        while (0 != x) {
            sum += x % 10;
            x /= 10;
        }
        while (0 != y) {
            sum += y % 10;
            y /= 10;
        }
        return sum <= k;
    }
    void dfs(int i, int j) {
        ++ans;
        used[i][j] = true;
        for (int k = 0; k < 4; ++k) {
            int x = i + dx[k], y = j + dy[k];
            if (x >= 0 && x < m && y >= 0 && y < n && !used[x][y] && check(x, y)) {
                dfs(x, y);
            }
        }
    }
    int movingCount(int m_, int n_, int k_) {
        m = m_, n = n_, k = k_;
        dfs(0, 0);
        return ans;
    }
};