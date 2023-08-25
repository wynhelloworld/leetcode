# Source : https://leetcode.cn/problems/reverse-pairs/description/
# Author : Yanan Wang
# Date   : 2023-08-25

# 本题与《剑指 Offer 51. 数组中的逆序对》非常相似，那题求的是nums[i] > nums[j] 的总数，而本题求的是nums[i] > 2 *nums[j]的总数
# 本题仍旧采用《剑指 Offer 51. 数组中的逆序对》中的方法“归并排序”
# 但不同的是，求nums[i] > 2*nums[j]的过程和归并排序中的“两有序数组合并”过程并不一致
# 所以要在求“两有序数组合并”之前，就要求出nums[i] > 2*nums[j]的结果
# 那么问题就又简化成了，给定两有序数组，i和j分别属于两数组，求nums[i] > 2*nums[j]的个数
#    可以用双指针的策略：
#         升序时：
#                 -----*------      ------*-----
#               left   i    mid   mid+1   j   right
#                 若 nums[i] > 2 * nums[j]       则数量为：mid - i + 1
#         降序时：
#                 -----*------      ------*-----
#               left   i    mid   mid+1   j   right
#                 若 nums[i] > 2 * nums[j]       right - j + 1
# 当求出nums[i] > 2*nums[j]的结果之后，再进行归并排序的“两有序数组合并”及之后步骤

class Solution:
    def reversePairs(self, nums: List[int]) -> int:
        tmp = [0] * len(nums)
        def merageSort(left, right):
            if left >= right:
                return 0
            mid = left + (right - left) // 2
            ans = merageSort(left, mid) + merageSort(mid + 1, right)
            # [left, mid]   [mid+1 ,right]
            cur1, cur2 = left, mid + 1
            while cur1 <= mid and cur2 <= right:
                if nums[cur1] > 2 * nums[cur2]:
                    ans += mid - cur1 + 1
                    cur2 += 1
                else:
                    cur1 += 1
            i, cur1, cur2 = left, left, mid + 1
            while cur1 <= mid and cur2 <= right:
                if (nums[cur1] <= nums[cur2]):
                    tmp[i] = nums[cur1]
                    cur1 += 1
                else:
                    tmp[i] = nums[cur2]
                    cur2 += 1
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

        return merageSort(0, len(nums) - 1)