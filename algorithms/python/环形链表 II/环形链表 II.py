# Source : https://leetcode.cn/problems/linked-list-cycle-ii/description/
# Author : Yanan Wang
# Date   : 2023-12-15

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return None
        slow = head
        fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow is fast:
                break
        if slow is not fast:
            return None
        while head is not slow:
            head = head.next
            slow = slow.next
        return head 