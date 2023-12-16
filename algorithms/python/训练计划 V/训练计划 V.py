# Source : https://leetcode.cn/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof/description/
# Author : Yanan Wang
# Date   : 2023-12-16

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        lenA = 0
        lenB = 0
        curA = headA
        curB = headB
        while curA or curB:
            if curA:
                curA = curA.next
                lenA += 1
            if curB:
                curB = curB.next
                lenB += 1

        curA = headA
        curB = headB
        if lenA < lenB:
            while lenA != lenB:
                curB = curB.next
                lenB -= 1
        elif lenA > lenB:
            while lenA != lenB:
                curA = curA.next
                lenA -= 1
        
        while curA and curB:
            if curA is curB:
                return curA
            curA = curA.next
            curB = curB.next
        return None