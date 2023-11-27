// Source : https://leetcode.cn/problems/swap-nodes-in-pairs/description/
// Author : Yanan Wang
// Date   : 2023-10-02

/**
 * 做链表类型题目，不能吝啬创建变量
 * 针对本题，首先创建一个dummyHead，否则前面的结点和后面的结点的处理逻辑就不相同了
 *   ---        ---        ---        ---        ---
 *  | d |  ->  | 1 |  ->  | 2 |  ->  | 3 |  ->  | 4 |  
 *   ---        ---        ---        ---        ---
 *   prev       cur        next       nnext     
 *                          
 *                    ⬇    创建四个指针分别指向这四个结点，用这四个指针将前两个有效结点的关系调整完毕
 *
 *   ---        ---        ---        ---        ---
 *  | d |  ->  | 2 |  ->  | 1 |  ->  | 3 |  ->  | 4 |  
 *   ---        ---        ---        ---        ---
 *   prev       next       cur        nnext
 *
 *                    ⬇    调整完毕后，更新这四个指针，开始下一轮循环
 *
 *   ---        ---        ---        ---        ---
 *  | d |  ->  | 2 |  ->  | 1 |  ->  | 3 |  ->  | 4 |  
 *   ---        ---        ---        ---        ---
 *                         prev       cur        next        nnext
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
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode *prev = dummyHead;
        ListNode *cur = head;
        while (cur != nullptr && cur->next != nullptr) {
            ListNode *next = cur->next;
            ListNode *nnext = next->next;
            prev->next = next;
            next->next = cur;
            cur->next = nnext;
            prev = cur;
            cur = nnext;
        }
        return dummyHead->next;
    }
};

/**
 * 新增一种解法：递归法
*/
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *node = swapPairs(head->next->next);
        ListNode *next = head->next;
        next->next = head;
        head->next = node;
        return next; 
    }
};