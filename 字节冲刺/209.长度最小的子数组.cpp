/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
#include "algorithm"
#include <climits>
#include <vector>

using namespace std;
class Solution {
public:
    int minSubArrayLen1(int target, vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        // 初始化第一个合法窗口和其关联到的状态
        int left = 0;
        int right = 0;
        int cur_len = 1;
        int sum = nums[left];

        // 先扩张到第一个 sum >= target 的窗口
        while (right + 1 < nums.size() && sum < target) {
            right++;
            sum += nums[right];
            cur_len++;
        }

        if (sum < target) {
            return 0;
        }

        // 再把这个合法窗口收缩为以 right 结尾的最小合法窗口
        while (sum - nums[left] >= target) {
            sum -= nums[left];
            left++;
            cur_len--;
        }

        int ans = cur_len;

        // 循环开始的时候， nums[left..=right] 这个子数组，为以下标 right 结尾的，
        // sum >= target 的最小子数组。
        while (right < nums.size()) {
            // Step1: 检查窗口状态并更新答案
            if (cur_len < ans) {
                ans = cur_len;
            }
            
            // Step2.1 尝试获取下个窗口
            if (right + 1 == nums.size()) {
                break;
            }

            // 收缩左边界保证扩展后的窗口尽可能小
            while (sum + nums[right + 1] - nums[left]  >= target) {
                sum -= nums[left];
                left++;
                cur_len--;
            }

            right++;
            sum += nums[right];
            cur_len++;
        }
        return  ans;
    }

    int minSubArrayLen(int target, vector<int>& nums){
        
        // 初始化第一个满足不变量的窗口
        int left = 0;
        int right = 0;
        int sum = nums[left];
        int cur_len = right + 1 - left;
        if (sum >= target) {
            return cur_len; // 1 已经是最小的了
        }


        int ans = nums.size() + 1;
        // 每次循环开始之前，nums[left..= right] 为以 right 结尾的第一个 sum < target 的子数组
        while (right + 1 < nums.size()) {
            right++;
            sum += nums[right];
            cur_len++;

            while (sum >= target) {
                ans = min(ans, cur_len);
                sum -= nums[left];
                left++;
                cur_len--;
            }
        }

        // 如果最长的子数组 nums.size() 都不能满足 sum >= target
        if (ans == nums.size() + 1) {
            return 0;
        }
        return ans;
    }
};
// @lc code=end
