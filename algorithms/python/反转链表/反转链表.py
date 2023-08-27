# Source : https://leetcode.cn/problems/reverse-linked-list/description/
# Author : Yanan Wang
# Date   : 2023-08-27

# 本题采用递归解法：
#    1 -> 2 -> 3 -> 4 -> 5                                                    
#    对于以上1-5链表，我们可以先将2--5反转完毕，返回新的头节点 --- 1 -> 2 <- 3 <- 4 <- 5(newHead)   然后再反转1--2，最后返回新的头节点
#    对于以上2-5链表，我们可以先将3--5反转完毕，返回新的头节点 --- 2 -> 3 <- 4 <- 5(newHead)   然后再反转2--3，最后返回新的头节点
#    对于以上3-5链表，我们可以先将4--5反转完毕，返回新的头节点 --- 3 -> 4 <- 5(newHead)   然后再反转3--4，最后返回新的头节点
#    那么重复子问题就是：给定n个结点的链表，先反转后面n-1个结点，返回新的头节点，最后再反转前面两个结点，返回结果
#    递归出口：当题目给的head为空时，返回空；当递归过程中发现当前节点的next为空时，返回当前节点。

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head
        newHead = self.reverseList(head.next)
        head.next.next = head
        head.next = None
        return newHead