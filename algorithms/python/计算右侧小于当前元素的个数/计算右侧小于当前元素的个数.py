# Source : https://leetcode.cn/problems/count-of-smaller-numbers-after-self/description/
# Author : Yanan Wang
# Date   : 2023-08-24

# 该题与《剑指 Offer 51. 数组中的逆序对》非常相似，不同之处就是：
#                                            那题求的是“一个数前面有多少个大于它的数”，返回总的和
#                                            本题求的是“一个数后面有多少个小于它的数”，将答案写到一个列表中，返回列表
# 相比于《剑指 Offer 51. 数组中的逆序对》而言，本题的归并排序用降序更简单
# 本题真正的一个难点是：如何将每个数求出的结果写进列表中，因为归并排序的过程中会打乱nums元素原来的位置
#    办法：用一个index列表，记录下原始的每个元素的下标，然后在归并排序的过程中，index与nums进行一模一样的操作（同步）
#         这样，即使nums中元素的位置被打乱，但index仍保存着该元素最初的下标
#        nums [2, 5,| 1, 6]               
#       index [0, 1,| 2, 3]     
#                   ⬇
#        nums [5, 2,| 6, 1]               
#       index [1, 0,| 3, 2]     

class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        n = len(nums)
        index = [i for i in range(0, n)]
        ans, tmp1, tmp2 = [0] * n, [0] * n, [0] * n
        def merageSort(left, right):
            if left >= right:
                return
            mid = left + (right - left) // 2
            merageSort(left, mid)
            merageSort(mid + 1, right)
            # [left, mid]   [mid+1, right]
            i, cur1, cur2 = left, left, mid + 1
            while cur1 <= mid and cur2 <= right:
                if nums[cur1] <= nums[cur2]:
                    tmp1[i] = nums[cur2]
                    tmp2[i] = index[cur2]
                    cur2 += 1
                else:
                    ans[index[cur1]] += right - cur2 + 1
                    tmp1[i] = nums[cur1]
                    tmp2[i] = index[cur1]
                    cur1 += 1
                i += 1
            while cur1 <= mid:
                tmp1[i] = nums[cur1]
                tmp2[i] = index[cur1]
                cur1 += 1
                i += 1
            while cur2 <= right:
                tmp1[i] = nums[cur2]
                tmp2[i] = index[cur2]
                cur2 += 1
                i += 1
            nums[left:right + 1] = tmp1[left:right + 1]
            index[left:right + 1] = tmp2[left:right + 1]

        merageSort(0, n - 1)
        return ans