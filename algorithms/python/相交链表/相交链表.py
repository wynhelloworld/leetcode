# Source : https://leetcode.cn/problems/intersection-of-two-linked-lists/description/
# Author : Yanan Wang
# Date   : 2023-12-15

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        if not headA or not headB:
            return None

        cur1 = headA
        cur2 = headB
        len1 = 0
        len2 = 0
        while cur1 or cur2:
            if cur1:
                len1 += 1
                cur1 = cur1.next
            if cur2:
                len2 += 1
                cur2 = cur2.next

        cur1 = headA
        cur2 = headB 
        if len1 < len2:
            while len1 != len2:
                cur2 = cur2.next
                len2 -= 1
        elif len2 < len1:
            while len1 != len2:
                cur1 = cur1.next
                len1 -= 1

        while cur1 and cur2:
            if cur1 is cur2:
                return cur1
            cur1 = cur1.next
            cur2 = cur2.next
        
        return None
        
        
