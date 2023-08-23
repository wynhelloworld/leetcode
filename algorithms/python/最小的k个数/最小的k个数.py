# Source : https://leetcode.cn/problems/zui-xiao-de-kge-shu-lcof/description/
# Author : Yanan Wang
# Date   : 2023-08-23

# 本题与《215. 数组中的第K个最大元素》非常相似，不同之处是本题要返回前k个数，
# 那么就只需要在分区之后，改变一下动作即可
#      -----------------------
#      ^          ^          ^ 
#     <key      ==key       >key  
#      a个        b个        c个
# 当 a < k时：去左边区域寻找k个最小元素
# 当 a + b <= k时：直接返回即可，因为此时已经找到了k个最小的数，只需在递归整体完成之后返回arr[:k]
# 当上面两个条件都不成立时：说明还有k-a-b个元素落在右边区域，那么就去右边区域寻找k-a-b个最小元素

class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        def quickSelect(arr, low, high, k):
            if low >= high:
                return
            key = arr[random.randint(low, high)]
            left, right = low, high
            i = low
            while i <= right:
                if arr[i] < key:
                    arr[left], arr[i] = arr[i], arr[left]
                    left += 1
                    i += 1
                elif arr[i] == key:
                    i += 1
                else:
                    arr[i], arr[right] = arr[right], arr[i]
                    right -= 1
            # [low, left)  [left, right]  (right, high]
            leftNums = left - low
            midNums = right - left + 1
            rightNums = high - right
            if leftNums > k:
                quickSelect(arr, low, left - 1, k)
            elif leftNums + midNums >= k:
                return
            else:
                quickSelect(arr, right + 1, high, k - leftNums - midNums)


        quickSelect(arr, 0, len(arr) - 1, k)
        return arr[:k]
