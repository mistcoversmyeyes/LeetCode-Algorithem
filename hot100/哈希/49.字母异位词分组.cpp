/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
#include <algorithm>
#include <unordered_map>
#include <utility>
#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        
        unordered_map<string, vector<int>> chrs2pos;
        int index = 0;
        for (auto str : strs) {
            sort(str.begin(), str.end(), [](char lhs, char rhs){
                return lhs < rhs;
            });
            if (chrs2pos.find(str) == chrs2pos.end()){
                chrs2pos.insert({str, vector<int>()});
            }
            chrs2pos.find(str)->second.push_back(index);
            index++;
        }

        for (const auto& item : chrs2pos) {
            vector<string> tmp;
            for (int idx : item.second){
                tmp.push_back(strs.at(idx));
            }            
            result.push_back(tmp);
        }

        return result;
    }
};
// @lc code=end

