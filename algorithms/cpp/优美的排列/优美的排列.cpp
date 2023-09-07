// Source : https://leetcode.cn/problems/beautiful-arrangement/description/
// Author : Yanan Wang
// Date   : 2023-09-07

// 本题采用递归回溯解法：
// 先画一颗决策树：根据下标[1, n]，然后1-n的数字往下标里填
//        需要剪枝的地方：
//                      1、 用过的数字不能再使用了
//                      2、 不能被整除的不能进行递归

class Solution {
private:
    int ans;
    vector<bool> used;
public:
    void dfs(int n, int index) {
        if (n + 1 == index) {
            ++ans;
            return;
        }
        for (int i = 1; i <= n; ++i) {
            if (!used[i] && (i % index == 0 || index % i == 0)) {
                used[i] = true;
                dfs(n, index + 1);
                used[i] = false;
            }
        }
    }
    int countArrangement(int n) {
        ans = 0;
        used = vector<bool>(n + 1, false);
        dfs(n, 1);
        return ans;
    }
};
