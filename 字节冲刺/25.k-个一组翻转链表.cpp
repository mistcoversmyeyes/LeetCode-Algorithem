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



using namespace std;
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
        ListNode* dummy = new ListNode(0, head);
        ListNode* before = dummy;   // 始终指向已k 个一组反转过的链表的尾部
        ListNode* after = head;     // 始终指向下组被反转链表反转后的尾部

        while (true) {
            int n = k;
            // 尝试凑够一组
            ListNode* fast = after;
            for (; fast && n > 0; n--) {
                fast = fast->next;
            }
            if (n > 0) {
                before->next = after;
                break;
            }

            // 反转这组链表
            n = k;
            ListNode* pre = nullptr;
            ListNode* cur = after;
            while(cur && n > 0){
                ListNode* next = cur->next; 
                cur->next = pre;
                pre = cur;
                cur = next;
                n--;
            }

            // 将 k 个反转后的链表末尾接上新反转的链表
            before->next = pre;
            before = after;
            after = cur;
        }

        return dummy->next;

    }
};
// @lc code=end

