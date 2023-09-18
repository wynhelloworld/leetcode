// Source : https://leetcode.cn/problems/longest-increasing-subsequence/
// Author : Yanan Wang
// Date   : 2023-06-07

/**
 * 动态规划类题目的一般步骤：
 *   1. 状态表示
 *        设dp[i]表示以nums[i]结尾的子序列中的最长严格递增长度。
 *   2. 状态转移方程
 *        以nums[i]结尾的子序列有很多种情况，但可以分为：1、只有nums[i]构成子序列；
 *                                                 2、nums[i]加上前面的元素构成子序列。
 *        [a, b, c, d, e]
 *                     i
 *                     |- 只有nums[i], dp[i]=1
 *        dp[i] = max -|
 *                     |- nums[i]+前面的元素, 即dp[i]=dp[j]+1, j属于[0,i-1]  
 *                                          并且nums[i]>nums[j], dp[j]是i前面中dp最大的
 *            
 *   3. 初始化
 *        初始化dp[0]=1
 *   4. 填表顺序
 *        从前往后
 *   5. 返回值
 *        返回dp中的最大值
 */

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int result = 1;
        for (int i = 1; i < n; ++i) {
            int dp_max = 0;
            for (int j = i - 1; j >= 0; --j) {
                if (nums[i] > nums[j]) {
                    dp_max = max(dp_max, dp[j]);
                }
            }
            dp[i] = dp_max + 1;
            result = max(result, dp[i]);
        }
        return result;
    }
};

// 新增了一种记忆化搜索方法和动态规划方法

class Solution {
public:
    int memorySearch(vector<int> &nums, int pos, vector<int> &memory) {
        if (memory[pos] != -1) return memory[pos];
        int ans = 0;
        for (int i = pos + 1; i < nums.size(); ++i) 
            if (nums[i] > nums[pos]) 
                ans = max(ans, memorySearch(nums, i, memory));
        memory[pos] = ans + 1;
        return memory[pos]; 
    }
    int lengthOfLIS(vector<int>& nums) {
        // 记忆化搜索
        // vector<int> memory(nums.size(), -1);
        // int ans = 0;
        // for (int i = 0; i < nums.size(); ++i) {
        //     ans = max(ans, memorySearch(nums, i, memory));
        // }
        // return ans;

        // 记忆化搜索改递归
        vector<int> dp(nums.size(), 1);
        int ans = 0;
        for (int i = nums.size() - 1; i >= 0; --i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] < nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};