/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
#include "vector"
#include "string"
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.length() < p.length()) {
            return vector<int>();
        }


        auto ans = vector<int>();
        int k = p.length();
        vector<int> window(26, 0);
        vector<int> need(26, 0);

        int i = 0;
        int j = i + k - 1;
        
        // 初始化 p 包含的各个字母的数量
        for (int m = 0; m < k; m++) {
            need[p[m] - 'a']++;
        }
        // 初始化第一个窗口的状态
        for (int m = 0; m < k; m++) {
            window[s[m] - 'a']++;
        }

        // 循环不变量：
        // - 进入循环时 i..=j 这个窗口对应一个长度为 p.length() 的窗口。
        // - 窗口关联到的状态信息准确对应该窗口。
        while (j < s.length()) {
            auto to_update = [] (vector<int>& win, vector<int>& need){
                return win == need;
            };
            // 第一部分：检查候选窗口，判断是否要更新答案。
            if (to_update(window, need)) {
                ans.push_back(i);
            }
            // 第二部分：获取下个待搜索窗口，并更新下个窗口对应的状态信息。
            i++;
            j++;
            if (j == s.length())    break; 
            [&] (vector<int>& win){
                win[s[i - 1] - 'a']--;
                win[s[j] - 'a']++;
            }(window);
        }

        return ans;
    }
};
// @lc code=end

