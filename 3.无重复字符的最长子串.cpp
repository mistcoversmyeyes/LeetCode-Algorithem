/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
#include <cstdio>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) {
            return 0;
        }
        int left_index = 0;
        int right_index = 0;
        unordered_map<char, int> appear;
        int max_length = 1;
        while (right_index < s.length()) {
            if (appear.find(s[right_index]) == appear.end()) {
                appear.insert(make_pair(s[right_index], right_index));
            }
            else {
                // 更新最长字串长度
                int cur_length = right_index - left_index;
                if (cur_length > max_length) {
                    max_length = cur_length;
                    printf("left_index = %d, right_index = %d", left_index, right_index);
                }

                // 跳过中间不可能的字串，将 left_index 指向移动到重复的字符的下一个位置，right_index 已经更新
                for (int i = left_index;i < appear.find(s[right_index])->second;i++) {
                    appear.erase(s[i]);
                }
                left_index = appear.find(s[right_index])->second + 1;
                appear[s[right_index]] = right_index;
            }
            
            right_index = right_index + 1;
        }
        int cur_length = right_index - left_index;
        if (cur_length > max_length) {
            max_length = cur_length;
        }
        return max_length;

    }
};
// @lc code=end

