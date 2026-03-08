/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
#include <stack>
#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    vector<string> ans;
    int n;
    auto is_prune_case(int remain_braket, int left, int right,const string& path)-> bool {
        if (left < right || left > n ) {
            return true;
        }
        return false;
    }
    
    auto is_vaild(int left, int right, const string& path)-> bool {
        if (left != right) {
            return false;
        }
        stack<int> s;
        for (const auto& c : path) {
            if (c == '(') {
                s.push(1);
            } else if (c == ')') {
                if (s.empty()) {
                    return false;
                }
                s.pop();
            }
        }
        return s.empty();
    }

    auto dfs_visit(int remain_braket, int left, int right, string& path ){
        if (remain_braket == 0) {
            if (is_vaild(left, right, path)) {
                ans.push_back(path);
            }
            return;
        }
        if (is_prune_case(remain_braket, left, right, path)) {
            return;
        }
        path.push_back('(');
        dfs_visit(remain_braket - 1, left + 1, right, path);
        path.pop_back();
        path.push_back(')');
        dfs_visit(remain_braket - 1, left, right + 1, path);
        path.pop_back();
        return;
    }

    vector<string> generateParenthesis(int n) {
        this->n = n;
        string path("");
        dfs_visit(2 * n, 0, 0, path);
        return ans;
    }
};
// @lc code=end

