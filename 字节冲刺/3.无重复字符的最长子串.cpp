/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) {
            return 0;
        }

        int ans = 1;
        int left = 0;
        int right = 0;
        int cur_len = 1;
        vector<bool> appear_in_window(128, false);
        appear_in_window[s[0]] = true;

        // 循环开始时，[left, right] 始终是一个合法窗口。
        while (right < s.size()) {
            // Step1: 根据现有窗口更新答案
            auto to_update = [&]() ->bool {
                return cur_len > ans;
            };
            if (to_update()) {
                ans = cur_len;
            }

            // Step2: 尝试获取下个窗口
            if (right + 1 == s.size()) {
                break;
            }

            char new_ch = s[right + 1];
            while (appear_in_window[new_ch]) {
                appear_in_window[s[left]] = false;
                left++;
                cur_len--;
            }

            right++;
            appear_in_window[new_ch] = true;
            cur_len++;
        }

        return ans;
    }
};
// @lc code=end
