# Source : https://leetcode.cn/problems/remove-nth-node-from-end-of-list/description/
# Author : Yanan Wang
# Date   : 2023-12-15

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        dummy = slow = fast = ListNode(next=head)
        for _ in range(n):
            fast = fast.next
        while fast.next:
            slow = slow.next
            fast = fast.next
        slow.next = slow.next.next
        return dummy.next
