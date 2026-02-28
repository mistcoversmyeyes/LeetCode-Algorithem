/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第 K 小的元素
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
#include <stack>

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
    int kthSmallest(TreeNode* root, int k) {
        int res = 0;
        int count = 0;
        dfs(root, k, count, res);
        return res;
    }
    
    // 从大到小搜索以 root 为根节点的二叉树，并且同时记录搜索到的节点的个数。
    void dfs(TreeNode* root,const int& k, int& count, int& res)  {
        if (root == nullptr){
            return ;
        }
        else {
            dfs(root->left, k, count, res);
            count++;
            if (count == k){
                res = root->val;
                return ;
            }
            dfs(root->right, k, count, res);
        }
    }
};
// @lc code=end

