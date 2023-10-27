// Source : https://leetcode.cn/problems/russian-doll-envelopes/description/
// Author : Yanan Wang
// Date   : 2023-10-27

/**
 * 解法一: 动态规划(超时)
 *        将envelopes按照每个数组的第一个元素升序排序后, 那么这个问题就转变成了《300. 最长递增子序列》
 *        动态规划类题目的一般步骤:
 *          1、状态表示:
 *                设dp[i]表示, 以envelopes[i]结尾的最长套娃信封个数.
 *          2、状态转移方程:
 *                dp[i] = max(dp[i], dp[j] + 1)     
 *                0 <= j < i, envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1]
 *          3、初始化:
 *                dp全为1
 *          4、填表顺序:
 *                从左向右
 *          5、返回值:
 *                dp中的最大值
 * 解法二: 重写排序 + 贪心 + 二分查找
 *        若只是针对第一个元素进行升序排序, 并且假设所有的第一个元素都无重复元素时, 本题就可看作《300. 最长递增子序列》, 然后用贪心+二分查找.
 *        但本题的第一个元素是有重复元素的, 所有仅针对第一个元素进行升序排序是不可以的.
 *        重写排序: 若第一个元素不相同, 就按升序排序, 若第一个元素相同, 就按第二个元素降序排序
 *        重写排序之后, 就可以用贪心+二分查找了
 */

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [&](vector<int> &lhs, vector<int> &rhs){
            if (lhs[0] == rhs[0]) {
                return lhs[1] > rhs[1];
            }
            return lhs[0] < rhs[0];
        });
        int n = envelopes.size();
        vector<int> tails;
        tails.push_back(envelopes[0][1]);
        for (int i = 1; i < n; ++i) {
            if (envelopes[i][1] > tails.back()) {
                tails.push_back(envelopes[i][1]);
            } else {
                int left = 0, right = tails.size() - 1;
                while (left < right) {
                    int mid = left + (right - left) / 2;
                    if (tails[mid] < envelopes[i][1]) {
                        left = mid + 1;
                    } else {
                        right = mid;
                    }
                }
                tails[left] = envelopes[i][1];
            }
        }
        return tails.size();
    }
};