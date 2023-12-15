# Source : https://leetcode.cn/problems/partition-list/description/
# Author : Yanan Wang
# Date   : 2023-12-15

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        small_dummy = small_cur = ListNode()
        big_dummy = big_cur = ListNode()
        while head:
            if head.val < x:
                small_cur.next = head
                small_cur = small_cur.next
            else:
                big_cur.next = head
                big_cur = big_cur.next
            head = head.next
        small_cur.next = big_dummy.next
        big_cur.next = None
        return small_dummy.next