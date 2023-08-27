# Source : https://leetcode.cn/problems/swap-nodes-in-pairs/description/
# Author : Yanan Wang
# Date   : 2023-08-27

# 本题采用递归解法：
#    1 -> 2 -> 3 -> 4 -> 5 -> 6
#    对于以上1-6链表，我们可以先将3-6反转完毕，返回新的头节点 --- 1 -> 2 -> 4 -> 3 -> 6 -> 5 最后反转前两个结点，返回结果
#    对于以上3-6链表，我们可以先将4-6反转完毕，返回新的头节点 --- 3 -> 4 -> 6 -> 5 最后反转前两个结点，返回结果
#    那么重复子问题就是：给定n个结点的链表，先反转后面n-2个结点，最后反转前两个结点，返回结果
#    递归出口：当题目给的head为空时，返回空；当递归过程中发现当前节点的next为空时，返回当前节点。

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head
        newHead = head.next
        head.next = self.swapPairs(newHead.next)
        newHead.next = head
        return newHead