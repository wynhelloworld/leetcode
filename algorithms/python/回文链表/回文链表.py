# Source : https://leetcode.cn/problems/palindrome-linked-list/description/
# Author : Yanan Wang
# Date   : 2023-12-16

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        slow = head
        fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        
        if fast:
            slow = slow.next

        prev = None
        curr = slow
        while curr:
            next = curr.next
            curr.next = prev
            prev = curr
            curr = next
        
        head2 = prev
        while head2:
            if head.val != head2.val:
                return False
            head = head.next
            head2 = head2.next
    
        return True
