# Source : https://leetcode.cn/problems/remove-duplicates-from-sorted-list/description/
# Author : Yanan Wang
# Date   : 2023-12-19

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return None
        slow = fast = head
        while fast:
            if slow.val != fast.val:
                slow = slow.next
                slow.val = fast.val
            fast = fast.next 
        
        slow.next = None
        return head