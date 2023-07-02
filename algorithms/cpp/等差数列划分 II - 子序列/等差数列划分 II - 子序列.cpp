// Source : https://leetcode.cn/problems/arithmetic-slices-ii-subsequence/
// Author : Yanan Wang
// Date   : 2023-07-02

/**
 * 动态规划类题目的一般步骤：
 *    1. 状态表示
 *         设dp[i][j]表示已nums[i]和nums[j]结尾的子序列的等差数列数目
 *    2. 状态转移方程
 *         dp[i][j] += dp[k][i] + 1;      (0 <= k < i)
 *         本题目求的是总的个数，所以根据后两个数求出的前一个数tmp，无论tmp有几个，都应该算上，所以i、j、k是三层循环，但时间复杂度太高
 *         但可以选择，将所有的数和下标放入hash，用tmp时取之即可。但又因为nums中会有重复的数，所以可以存一个key--vector<int> 
 *    3. 初始化
 *         全部初始化为0
 *    4. 填表顺序
 *         从左向右
 *    5. 返回值
 *         dp所有的和
 */

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n));
        unordered_map<long long, vector<int>> hash;
        for (int i = 0; i < n; ++i) {
            hash[nums[i]].push_back(i);
        }
        int result = 0;
        for (int j = 2; j < n; ++j) {
            for (int i = 1; i < j; ++i) {
                long long tmp = (long long)2 * nums[i] - nums[j];
                if (hash.count(tmp)) {
                    for (auto k : hash[tmp]) {
                        if (k < i) {
                            dp[i][j] += dp[k][i] + 1;
                        } else {
                            break;
                        }
                    }
                }    
                result += dp[i][j];
            }
        }
        return result;
    }
};