# Source : https://leetcode.cn/problems/kth-largest-element-in-an-array/description/
# Author : Yanan Wang
# Date   : 2023-08-22

# 本题采用快速选择算法（时间复杂度为O(N)，证明自《算法导论》）：基于快速排序（分区分三块）
# 当快速排序完成一次时，nums会分成三个区域：
#      -----------------------
#      ^          ^          ^ 
#     <key      ==key       >key  
#      a个        b个        c个
# 本题求的是第K个最大元素，那么就根据这三个分区的数量来选择下次递归的范围
# 当 c >= k时：去右边区域寻找第k个最大元素
# 当 b + c >= k时：直接返回key即可，因为此时第k个元素肯定落在中间区域
# 当上面两个条件都不成立时：说明第k个元素落在左边区域，那么就去左边区域寻找第k-b-c个最大元素

class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        def quickSelect(nums, low, high, k):
            if low == high:
                return nums[low]
            key = nums[random.randint(low, high)]
            left, right = low, high
            i = low
            while i <= right:
                if nums[i] < key:
                    nums[left], nums[i] = nums[i], nums[left]
                    left += 1
                    i += 1
                elif nums[i] == key:
                    i += 1
                else:
                    nums[i], nums[right] = nums[right], nums[i]
                    right -= 1
            # [low, left)  [left, right]  (right, high]
            # left - low   right-left+1    high - right  
            leftNums = left - low
            midNums = right - left + 1
            rightNums = high - right
            if rightNums >= k:
                return quickSelect(nums, right + 1, high, k)
            elif midNums + rightNums >= k:
                return key
            else:
                return quickSelect(nums, low, left - 1, k - midNums - rightNums)


        return quickSelect(nums, 0, len(nums) - 1, k)