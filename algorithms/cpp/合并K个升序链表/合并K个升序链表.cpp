// Source : https://leetcode.cn/problems/merge-k-sorted-lists/description/
// Author : Yanan Wang
// Date   : 2023-10-06

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

/**
 * 法一：优先级队列（小根堆）法
 *      将这k个升序链表的头结点分别都push到heap中，然后依次取出top元素即可，并且把top的next结点push到heap中
 */
// class Solution {
// public:
//     class Cmp {
//     public:
//         bool operator()(ListNode *l1, ListNode *l2) {
//             return l1->val > l2->val;
//         }
//     };
// public:
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         if (lists.size() == 0) {
//             return nullptr;
//         }
//         priority_queue<ListNode *, vector<ListNode *>, Cmp> heap;
//         for (auto &list : lists) {
//             if (list != nullptr) {
//                 heap.push(list);
//             }
//         }
//         ListNode *dummyHead = new ListNode();
//         ListNode *prev = dummyHead;
//         while (!heap.empty()) {
//             ListNode *list = heap.top();
//             heap.pop();
//             prev->next = list;
//             prev = list;
//             if (prev->next != nullptr) {
//                 heap.push(prev->next);
//             }
//         }
//         return dummyHead->next;
//     }
// };

/**
 * 法二：归并法
 *      将k个链表转化为两个链表，然后对这两个链表进行有序合并
 */
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        ListNode dummyHead;
        ListNode *prev = &dummyHead;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                prev->next = list1;
                list1 = list1->next;                
            } else {
                prev->next = list2;
                list2 = list2->next;
            }
            prev = prev->next;
        }
        if (list1 != nullptr) {
            prev->next = list1;
        } else {
            prev->next = list2;
        }
        return dummyHead.next;
    }
    ListNode *dfs(vector<ListNode *> &lists, int left, int right) {
        if (left == right) {
            return lists[left];
        }
        if (left > right) {
            return nullptr;
        }
        int mid = left + (right - left) / 2;
        ListNode *list1 = dfs(lists, left, mid);
        ListNode *list2 = dfs(lists, mid + 1, right);
        return mergeTwoLists(list1, list2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return dfs(lists, 0, lists.size() - 1);
    }
};