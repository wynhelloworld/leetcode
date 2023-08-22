# Source : https://leetcode.cn/problems/sort-an-array/description/
# Author : Yanan Wang
# Date   : 2023-08-21

# 自从leetcode加了特殊测试用例之后，经典的快速排序（分区分两块）解法已经会超时了
# 原因是：当所有元素均相同时，O(nlgn)会退化成O(n^2)
# 所以，本题采用"分区分三块"的快速排序：
#      -----------------------
#      ^          ^          ^ 
#     <key      ==key       >key     
# 当所以元素均相同时，nums会变成一个分区(==key)，然后就退出递归。
# 分三区的做法采用《75. 颜色分类》题目中的三指针思想:
#   在遍历nums时，用left, i, right将其划分为四个区域:
#       [0, left)     < key
#       [left, i)    == key
#       [i, right]    待检测区域
#       (right, n-1]  > key 
#   当遍历完成时，nums会变成三个区域：
#       [0, left)     < key
#       [left, right] == key
#       (right, n-1]  > key 
# 选key的方法采用等概率随机法（算法导论中已证明，该方法的渐进时间复杂度最接近于O(nlgn)）

class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        def quickSort(nums, low, high):
            if low >= high:
                return
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
            quickSort(nums, low, left - 1)
            quickSort(nums, right + 1, high)


        quickSort(nums, 0, len(nums) - 1)
        return nums