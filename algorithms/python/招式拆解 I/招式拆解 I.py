# Source : https://leetcode.cn/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof/description/
# Author : Yanan Wang
# Date   : 2023-12-22

class Solution:
    def dismantlingAction(self, arr: str) -> int:
        ans = 0
        cnt = [0] * 128
        left = 0
        right = 0
        while right < len(arr):
            x = ord(arr[right]) - ord('a')
            cnt[x] += 1
            while cnt[x] > 1:
                y = ord(arr[left]) - ord('a')
                cnt[y] -= 1
                left += 1
            ans = max(ans, right - left + 1)
            right += 1
        return ans
