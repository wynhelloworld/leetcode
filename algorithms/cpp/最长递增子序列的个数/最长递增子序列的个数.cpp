// Source : https://leetcode.cn/problems/number-of-longest-increasing-subsequence/
// Author : Yanan Wang
// Date   : 2023-06-27

/**
 * 动态规划类题目的一般步骤：
 *    1. 状态表示
 *         设cnt[i]表示以nums[i]结尾的子序列中的最长递增子序列的个数
 *         设len[i]表示以nums[i]结尾的子序列中的最长递增子序列的长度
 *    2. 状态转移方程
 *         if (len[j] + 1 == len[i]) cnt[i] += cnt[j];
 *         if (len[j] + 1 > len[i]) len[i] = len[j] + 1; cnt[i] = cnt[j];
 *    3. 初始化
 *         cnt和len全初始化为1
 *    4. 填表顺序
 *         从左向右
 *    5. 返回值
 *         返回len_max时的cnt
 */

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> cnt(n, 1);
        vector<int> len(n, 1);
        int ret_len = 1;
        int ret_cnt = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    if (len[j] + 1 == len[i]) {
                        cnt[i] += cnt[j];
                    } else if (len[j] + 1 > len[i]) {
                        len[i] = len[j] + 1;
                        cnt[i] = cnt[j];
                    }
                }
            }
            if (ret_len == len[i]) {
                ret_cnt += cnt[i];
            } else if (ret_len < len[i]) {
                ret_len = len[i];
                ret_cnt = cnt[i];
            }
        }
        return ret_cnt;
    }
};