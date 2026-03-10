/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
#include "string"
#include "vector"
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
    bool wordBreak_memo(string& s, int k, unordered_set<string>& words, unordered_map<int, bool>& memo){
        if (memo.count(k)) {
            return memo[k];
        }
        if (k == s.length()) {
            memo[k] = true;
            return true;
        }
        
        bool ret;
        
        for (int i = k; i < s.length(); i++) {
            auto prefix = s.substr(k, i + 1 - k);
            ret = words.count(prefix) &&  wordBreak_memo(s,i + 1 , words, memo);
            if (ret) {
                break;
            }
        }
        memo.insert({k, ret});
        return ret;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        auto words = unordered_set<string>(wordDict.begin(), wordDict.end());
        auto memo = unordered_map<int, bool>();

        return wordBreak_memo(s,0, words, memo);
        
    }
};
// @lc code=end

