/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


using namespace std;
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

class Solution {
public:
    bool isAncestor(TreeNode* root, TreeNode* p){
        if (!root) {
            return false;
        }
        else {
            return root == p || isAncestor(root->left, p) || isAncestor(root->right, p);
        }
    }

    TreeNode* candidateLowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        if (root == nullptr || root == p || root == q) {
            return root;
        }
        TreeNode* left = lowestCommonAncestorByPostorder(root->left, p, q);
        TreeNode* right = lowestCommonAncestorByPostorder(root->right, p, q);
        if (left && right) {
            return root;
        }
        if (left){
            return left;
        }
        else {
            return right;
        }
    }

    TreeNode* lowestCommonAncestorByAncestorCheck(TreeNode* root, TreeNode* p, TreeNode* q) {
        //base case
        if (isAncestor(root->left, p) && isAncestor(root->right, q) 
            || isAncestor(root->right, p) && isAncestor(root->left, q)
            || root == p || root == q) {
            return root;
        }

        // recursion case: 如果 pq 都在同一边
        if (isAncestor(root->left, p)) {
            return lowestCommonAncestorByAncestorCheck(root->left, p, q);
        }
        else {
            return lowestCommonAncestorByAncestorCheck(root->right, p, q);
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        return lowestCommonAncestorByPostorder(root, p, q);
    }
};
// @lc code=end
