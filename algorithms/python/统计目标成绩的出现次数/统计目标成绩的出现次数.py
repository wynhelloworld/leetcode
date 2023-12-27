# Source : https://leetcode.cn/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof/description/
# Author : Yanan Wang
# Date   : 2023-12-27

class Solution:
    def countTarget(self, scores: List[int], target: int) -> int:
        if not scores:
            return 0
        n = len(scores)

        # 找左端点
        left = 0
        right = n - 1
        while left < right:
            mid = left + (right - left) // 2
            if scores[mid] < target:
                left = mid + 1
            else:
                right = mid
        if scores[left] != target:
            return 0
        lhs = left

        # 找右端点
        left = 0
        right = n - 1
        while left < right:
            mid = left + (right - left + 1) // 2
            if scores[mid] > target:
                right = mid - 1
            else:
                left = mid
        rhs = left

        # 返回左右端点之间的距离
        return rhs - lhs + 1         