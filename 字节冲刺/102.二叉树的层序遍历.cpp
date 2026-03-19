/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include "vector"
#include "queue"
#include <queue>
#include <vector>


using namespace std;
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        vector<vector<int>> ret;
        queue<TreeNode*> qu;
        
        qu.push(root);
        while (!qu.empty()) {
            vector<int> tmp;
            for(int i = qu.size(); i > 0; i++){
                TreeNode* cur_node = qu.front();
                tmp.push_back(cur_node->val);
                if (cur_node->left) {
                    qu.push(cur_node->left);
                }

                if (cur_node->right) {
                    qu.push(cur_node->right);
                }
                qu.pop();
            }
            ret.push_back(tmp);
        }

        return ret;
    }
};
// @lc code=end

