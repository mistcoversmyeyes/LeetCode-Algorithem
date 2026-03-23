/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
#include "vector"
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) {
            return {-1, -1};
        }

        auto lower_bound = [](const vector<int>& nums, int target){
            int l = 0;             // 不变量：subarray(begin(), begin() + l) == nums[0..l] 全 < target
            int r = nums.size();   // 不变量：subarray(begin() + r, end()) == nums[r..n] 全 >= target

            while (l < r) {
                int mid = (l + r) / 2;
                if (nums[mid] >= target)
                    r = mid;
                else
                    l = mid + 1;
            }
            return r;  // l == r，两个已知区域碰头，结合先前的不变量 得到 nums[l] 为第一个 >= target 的元素。
        };


        int lower = lower_bound(nums, target);
        int upper = lower_bound(nums, target + 1) - 1;
        
        if (lower <= upper)
            return {lower, upper};
        else
            return {-1, -1};
    }
};
// @lc code=end

