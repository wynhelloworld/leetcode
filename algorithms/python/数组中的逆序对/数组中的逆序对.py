# Source : https://leetcode.cn/problems/shu-zu-zhong-de-ni-xu-dui-lcof/
# Author : Yanan Wang
# Date   : 2023-08-23

# 思想进度一：
#   把nums分为两个区域
#   ----- ------
#    A区    B区
#   求逆序对数量的话，可以先求出A区中逆序对数量，然后求出B区中逆序对数量，最后再求一个逆序对数量（A区、B区都要出）
#        eg：         7 5 6 4
#               A区 7 5     B区 6 4
#              A区逆序对：(7, 5)
#              B区逆序对：(6, 4)
#           另外的逆序对：(7, 6) (7, 4) (5, 4)
#      把这三种逆序对的数量加起来，就能求出总的逆序对数量
# 思想进度二：
#   若是在分A、B区的基础上，分别给A、B两区进行排序，是不影响求总的逆序对数量的
#   但是能够加快求“另外的逆序对”的速度（下面解释）
# 思想进度三：
#   结合上面，就能够发现，此场景非常适合用归并排序。
#   针对“另外的逆序对”：
#       归并排序中，两有序(升序)数组合并时，
#       -----------      -----------
#     left   ^   mid   mid+1   ^  right
#           cur1             cur2
#   当cur1 > cur2时，说明[cur1, mid]中的元素都大于cur2，那么就有mid-cur1+1个逆序对，此时cur2 += 1
#   此过程与归并排序完美契合，只需要在cur1 > cur2时，多添加一条语句用来计算个数即可。

class Solution:
    def merageSort(self, nums, tmp, left, right):
        if left >= right:
            return 0
        mid = left + (right - left) // 2
        ans = self.merageSort(nums, tmp, left, mid) + self.merageSort(nums, tmp, mid + 1, right)
        i, cur1, cur2 = left, left, mid + 1
        # [left, mid]    [mid+1, right]
        #  cur1           cur2
        while cur1 <= mid and cur2 <= right:
            if nums[cur1] <= nums[cur2]:
                tmp[i] = nums[cur1]
                cur1 += 1
            else:
                tmp[i] = nums[cur2]
                cur2 += 1
                ans += mid - cur1 + 1
            i += 1
        while cur1 <= mid:
            tmp[i] = nums[cur1]
            cur1 += 1
            i += 1
        while cur2 <= right:
            tmp[i] = nums[cur2]
            cur2 += 1
            i += 1
        nums[left:right + 1] = tmp[left:right + 1]
        return ans


    def reversePairs(self, nums: List[int]) -> int:
        tmp = [0] * len(nums)
        return self.merageSort(nums, tmp, 0, len(nums) - 1)