/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
#include <vector>

using namespace std;
// struct TreeNode {
//   int val;
//   TreeNode *left;
//   TreeNode *right;
//   TreeNode() : val(0), left(nullptr), right(nullptr) {}
//   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//   TreeNode(int x, TreeNode *left, TreeNode *right)
//       : val(x), left(left), right(right) {}
// };

class Solution {
public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    TreeNode* head = new TreeNode();
    return buildTree_recur(head, preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
  }

  TreeNode *buildTree_recur(TreeNode *head, vector<int> &preorder,
                            vector<int> &inorder, int pre_left, int pre_right,
                            int in_left, int in_right) {
    if (pre_right < pre_left || in_right < in_left) {
        delete head;
        return nullptr;
    } else {
        head->val = preorder[pre_left];

        int root_index = in_left;
        while (inorder[root_index] != head->val) {
            root_index++;
        }

        int new_pre_left = pre_left + 1;
        int new_pre_right = pre_left + (root_index - in_left);
        int new_in_left = in_left;
        int new_in_right = root_index - 1;
        head->left = buildTree_recur(new TreeNode(), preorder, inorder, new_pre_left, new_pre_right,
                        new_in_left, new_in_right);
        new_pre_left = pre_left + (root_index - in_left) + 1;
        new_pre_right = pre_right;
        new_in_left = root_index + 1;
        new_in_right = in_right;
        head->right = buildTree_recur(new TreeNode(), preorder, inorder, new_pre_left, new_pre_right,
                        new_in_left, new_in_right);
        return head;
    }
  }
};
// @lc code=end
