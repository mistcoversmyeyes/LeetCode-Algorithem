/*
 * @lc app=leetcode.cn id=140 lang=cpp
 *
 * [140] 单词拆分 II
 */

// @lc code=start
#include "string"
#include <algorithm>
#include <functional>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, vector<string>> memo;
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        
        function<vector<string>(string)> dfs = [&](string str) -> vector<string> {
            if (memo.count(str)) return memo[str];
            if (str.empty()) return memo[str] = {""};
            
            vector<string> ans;
            for (int i = 1; i <= str.size(); i++) {
                string prefix = str.substr(0, i);
                if (wordSet.count(prefix)) {
                    for (string& suf : dfs(str.substr(i))) {
                        ans.push_back(suf.empty() ? prefix : prefix + " " + suf);
                    }
                }
            }
            return memo[str] = ans;
        };
        
        return dfs(s);
    }
};
// @lc code=end

