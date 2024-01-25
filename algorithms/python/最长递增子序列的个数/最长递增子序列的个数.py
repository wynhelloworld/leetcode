# Source : https://leetcode.cn/problems/number-of-longest-increasing-subsequence/description/
# Author : Yanan Wang
# Date   : 2024-01-25

class Solution:
    def findNumberOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        dp_len = [1] * n
        dp_cnt = [1] * n
        ans_len = 1
        ans_cnt = 1
        for i in range(1, n):
            for j in range(i):
                if nums[j] < nums[i]:
                    if dp_len[j] + 1 == dp_len[i]:
                        dp_cnt[i] += dp_cnt[j]
                    elif dp_len[j] + 1 > dp_len[i]:
                        dp_len[i] = dp_len[j] + 1
                        dp_cnt[i] = dp_cnt[j]
            if ans_len < dp_len[i]:
                ans_len = dp_len[i]
                ans_cnt = dp_cnt[i]
            elif ans_len == dp_len[i]:
                ans_cnt += dp_cnt[i]
        return ans_cnt
            
