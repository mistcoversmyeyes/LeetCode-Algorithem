/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// @lc code=start
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto* dummy = new ListNode(0, head);
        ListNode* pre = dummy;
        ListNode* cur = head;
        ListNode* fast = head;

        while (n > 0) {
            fast = fast->next;
            n--;
        }

        while (fast) {
            fast = fast->next;
            cur = cur->next;
            pre = pre->next;
        }

        pre->next = cur->next;
        return dummy->next;
    }
};
// @lc code=end

