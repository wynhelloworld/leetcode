# Source : https://leetcode.cn/problems/arithmetic-slices-ii-subsequence/description/
# Author : Yanan Wang
# Date   : 2024-01-25

class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        ans = 0
        dp = [collections.defaultdict(lambda: 0) for _ in nums]
        for i, x in enumerate(nums):
            for j in range(i):
                d = x - nums[j]
                cnt = dp[j][d]
                ans += cnt
                dp[i][d] += cnt + 1
        return ans