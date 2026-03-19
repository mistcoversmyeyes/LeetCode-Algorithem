/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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
#include "queue"
#include "vector"
#include <algorithm>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) {
            return {};
        }
        bool left = true;
        auto qu = queue<TreeNode*>();
        qu.push(root);
        vector<vector<int>> ans;
        
        while (!qu.empty()) {
            vector<int> path;
            for (int i = qu.size(); i > 0; i--) {
                TreeNode* cur = qu.front();
                path.push_back(cur->val);
                if (cur->left)  qu.push(cur->left);
                if (cur->right) qu.push(cur->right);
                qu.pop();
            }
            if (left){
                left = false;
            }
            else {
                reverse(path.begin(), path.end());
                left = true;
            }
            ans.push_back(path);
        }

        return ans;
    }
};
// @lc code=end

