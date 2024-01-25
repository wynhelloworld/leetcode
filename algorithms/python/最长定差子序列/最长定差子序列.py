# Source : https://leetcode.cn/problems/longest-arithmetic-subsequence-of-given-difference/description/
# Author : Yanan Wang
# Date   : 2024-01-25

class Solution:
    def longestSubsequence(self, arr: List[int], difference: int) -> int:
        mapper = collections.defaultdict(lambda: 0)
        for i in range(len(arr)):
            mapper[arr[i]] = mapper[arr[i] - difference] + 1
        return max(mapper.values())