/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
#include <cstdio>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // 构建哈希表
        unordered_set<int> is_in_nums;
        for (auto& item : nums) {
            is_in_nums.insert(item);
        }

        int max_length = 0;

        // 遍历整个哈希表中的元素，找到子序列的开始元素，然后计算每个对应子序列的长度
        for (auto item : is_in_nums) {
            if (is_in_nums.find(item - 1) == is_in_nums.end()) {
                int cur_length = 1;
                for (int cur_item = item;
                     is_in_nums.find(cur_item + 1) != is_in_nums.end();
                     cur_item = cur_item + 1) {
                    cur_length++;
                    // printf("%d", cur_item);
                }
                if (cur_length >= max_length ) {
                    max_length = cur_length;
                }
            }
        }
        return max_length;
    }
};
// @lc code=end

