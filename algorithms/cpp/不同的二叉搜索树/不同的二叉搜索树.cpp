// Source : https://leetcode.cn/problems/unique-binary-search-trees/
// Author : Yanan Wang
// Date   : 2023-07-22

/**
 * 动态规划类题目的一般步骤：
 *    1. 状态表示
 *         本题通过分析问题的过程中，发现子问题，进而抽象出一个状态来表示，
 *         假设x为根结点，那么左子树有x-1个节点，右子树有n-x个节点，那么此时问题就转变为了给定一个整数x-1求种数、给定一个整数n-x求种数。
 *         所以状态表示为：dp[i]表示节点个数为i的时候，二叉搜索树种类的数量。
 *    2. 状态转移方程
 *         dp[i] = dp[x-1] * dp[n-x];
 *         又由于x是变化的，所以转移方程为：dp[i] = dp[j-1] * dp[i-j];
 *    3. 初始化
 *         dp[0] = 1;
 *    4. 填表顺序
 *         从前往后
 *    5. 返回值
 *         dp[n];
 */

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) 
            for (int j = 1; j <= i; ++j)
                dp[i] += dp[j - 1] * dp[i - j];
        return dp[n];
    }
};