/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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

#include <cstddef>
#include <iostream>
 
 
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(-1, head);
        // 记录已经反转的链表的尾节点
        ListNode* before = dummy;
        // 记录将要变为尾节点的当前反转的一组链表的头节点
        ListNode* after = head;


        ListNode* pre = nullptr;
        ListNode* cur = head; 
        while (true){
            ListNode* cursor = after;
            // 检查是否满足 k 个一组翻转的条件
            for (int i = 0; i < k; i++) {
                if (cursor == nullptr) {
                    return dummy->next;
                }
                cursor = cursor->next;
            }
            // 执行翻转
            cur = after;
            pre = before;
            for (int i = 0; i < k; i++) {
                ListNode* next = cur->next;
                cur->next = pre;
                pre = cur;
                cur = next;
            }
            after->next = cur;
            before->next = pre;
            before = after;
            after = cur;
        }

        return dummy->next;
    }
};
// @lc code=end

