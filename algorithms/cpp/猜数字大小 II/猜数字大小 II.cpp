// Source : https://leetcode.cn/problems/guess-number-higher-or-lower-ii/description/
// Author : Yanan Wang
// Date   : 2023-09-19

class Solution {
public:
    int dfs(int left, int right, vector<vector<int>> &memory) {
        if (left >= right) return 0; 
        if (memory[left][right] != -1) return memory[left][right];
        int ans = INT_MAX;
        for (int head = left; head <= right; ++head) {
            int x = dfs(left, head - 1, memory);
            int y = dfs(head + 1, right, memory);
            ans = min(ans, head + max(x, y));
        }
        memory[left][right] = ans;
        return ans;
    }
    int getMoneyAmount(int n) {
        vector<vector<int>> memory(n + 1, vector<int>(n + 1, -1));
        return dfs(1, n, memory);
    }
};