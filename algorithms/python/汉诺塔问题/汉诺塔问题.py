# Source : https://leetcode.cn/problems/hanota-lcci/description/
# Author : Yanan Wang
# Date   : 2023-08-26

# 对本题先进行几步宏观模拟：
#    当n == 1时，直接将A柱上的盘子移动到C柱上
#    当n == 2时，将A柱最上面1个盘子放到B柱上，再将A柱剩的一个放到C柱上，最后将B柱上的一个放到C柱上。（将A柱上的盘子移动到了C柱上，借助了B柱）
#    当n == 3时，将A柱最上面2个盘子放到B柱上，再将A柱剩的一个放到C柱上，最后将B柱上的一个放到C柱上。（将A柱上的盘子移动到了C柱上，借助了B柱）
#    当n == 4时，将A柱最上面3个盘子放到B柱上，再将A柱剩的一个放到C柱上，最后将B柱上的一个放到C柱上。（将A柱上的盘子移动到了C柱上，借助了B柱）
#    其中当n==4时，中间有一步是“将A柱最上面3个盘子放到B柱上”，那么这一步完全与“n==3时的步骤”一样，只是移动的柱子变了
# 那么重复子问题就是：将x柱上的n个盘子，借助y柱，放到c柱上  ->函数头 dfs(x, y, z, n)
# 函数体：
#         先将A柱上的n-1个盘子，借助C柱，放到B柱上       ->dfs(A, C, B, n - 1)
#         然后将A柱上仅剩的1个盘子，直接放到C柱上        ->C.append(A[-1])   A.pop()
#         最后将B柱上的盘子借助A柱，放到C柱上           ->dfs(B, A, C, n - 1)
# 递归出口：
#         当n == 1，即只有一个盘子时，无需借助其它柱子，直接移动即可。
class Solution:
    def dfs(self, A, B, C, n):
        if n == 1:
            C.append(A[-1])
            A.pop()
            return
        self.dfs(A, C, B, n - 1)
        C.append(A[-1])
        A.pop()
        self.dfs(B, A, C, n - 1)

    def hanota(self, A: List[int], B: List[int], C: List[int]) -> None:
        self.dfs(A, B, C, len(A))