// Source : https://leetcode.cn/problems/reverse-nodes-in-k-group/description/
// Author : Yanan Wang
// Date   : 2023-10-06

/**
 * 本题先计算出结点总个数，然后根据k，求出需要翻转的组数
 * 每组进行链表逆序即可
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = 0;
        ListNode *cur = head;
        while (cur != nullptr) {
            cur = cur->next;
            ++n;
        }
        n /= k;
        
        ListNode *dummyHead = new ListNode();
        ListNode *prev = dummyHead;
        cur = head;
        for (int i = 0; i < n; ++i) {
            ListNode *tmp = cur;
            for (int j = 0; j < k; ++j) {
                ListNode *next = cur->next;
                cur->next = prev->next;
                prev->next = cur;
                cur = next;
            }
            prev = tmp;
        }
        prev->next = cur;
        return dummyHead->next;
    }
};