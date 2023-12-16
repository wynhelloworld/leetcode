# Source : https://leetcode.cn/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/description/
# Author : Yanan Wang
# Date   : 2023-12-16

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def trainingPlan(self, head: Optional[ListNode], cnt: int) -> Optional[ListNode]:
        slow = head
        fast = head
        for _ in range(cnt):
            fast = fast.next
        while fast:
            slow = slow.next
            fast = fast.next
        return slow