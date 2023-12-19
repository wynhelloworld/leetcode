# Source : https://leetcode.cn/problems/corporate-flight-bookings/description/
# Author : Yanan Wang
# Date   : 2023-12-19

class Solution:
    def corpFlightBookings(self, bookings: List[List[int]], n: int) -> List[int]:
        nums = [0] * n
        for first, last, cnt in bookings:
            nums[first - 1] += cnt
            if last < n:
                nums[last] -= cnt

        for i in range(1, n):
            nums[i] += nums[i - 1]
        
        return nums