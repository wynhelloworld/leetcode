// Source : https://leetcode.cn/problems/reorder-list/description/
// Author : Yanan Wang
// Date   : 2023-10-03

/**
 * 本题其实就是链表题目中经典的三道题目的合并题目
 *    《876. 链表的中间节点》
 *    《206. 反转链表》
 *    《143. 重排链表》
 * 按顺序根据这三道题目的思路，就能够做出本题
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *prev = nullptr; // 找到链表中间节点的前驱，使该前驱的next为nullptr，为了将链表断开
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr;
        return slow;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr;
        ListNode *cur = head;
        while (cur != nullptr) {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head = list1;
        ListNode *cur1 = list1;
        ListNode *cur2 = list2;
        while (cur1 != nullptr && cur2 != nullptr) {
            ListNode *next1 = cur1->next;
            ListNode *next2 = cur2->next;
            cur1->next = cur2;
            if (next1 != nullptr) {
                cur2->next = next1;
            }
            cur1 = next1;
            cur2 = next2;
        }
        return head;
    }
    void reorderList(ListNode* head) {
        if (head->next == nullptr) {
            return;
        }
        mergeTwoLists(head, reverseList(middleNode(head)));
    }
};