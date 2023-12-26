# Source : https://leetcode.cn/problems/vvXgSW/description/
# Author : Yanan Wang
# Date   : 2023-12-26

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

''' 遍历逐个排序 '''
# class Solution:
#     def sortLists(self, lists1, lists2):
#         cur = dummy = ListNode()
#         while lists1 and lists2:
#             if lists1.val < lists2.val:
#                 cur.next = lists1
#                 lists1 = lists1.next
#             else:
#                 cur.next = lists2
#                 lists2 = lists2.next
#             cur = cur.next
#         if lists1:
#             cur.next = lists1
#         elif lists2:
#             cur.next = lists2
#         return dummy.next
# 
# 
#     def mergeKLists(self, lists: List[ListNode]) -> ListNode:
#         x = None
#         for l in lists:
#             x = self.sortLists(x, l)
#         return x     



''' 归并排序 '''
class Solution:
    def sortLists(self, lists1, lists2):        
        cur = dummy = ListNode()
        while lists1 and lists2:
            if lists1.val < lists2.val:
                cur.next = lists1
                lists1 = lists1.next
            else:
                cur.next = lists2
                lists2 = lists2.next
            cur = cur.next
        if lists1:
            cur.next = lists1
        elif lists2:
            cur.next = lists2
        return dummy.next 


    def mergeSort(self, lists, left, right):
        if left == right:
            return lists[left]
        mid = left + (right - left) // 2
        lists1 = self.mergeSort(lists, left, mid)
        lists2 = self.mergeSort(lists, mid + 1, right)
        return self.sortLists(lists1, lists2)
        
        
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        if not lists:
            return None
        return self.mergeSort(lists, 0, len(lists) - 1)
