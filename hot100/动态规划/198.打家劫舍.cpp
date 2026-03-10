/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:


    int rob(vector<int>& nums) {
        vector<int> dp(3, 0);

        // base case
        dp[0] = nums[0];
        if (nums.size() == 1) {
            return dp[0];
        }
        dp[1] = max(nums[0], nums[1]);
        // 状态转移方程
        for (int i = 2; i < nums.size(); i++) {
            dp[2] = max(dp[1], dp[0] + nums[i]);
            dp[0] = dp[1];
            dp[1] = dp[2];
        }

        return dp[2] == 0 ? dp[1] : dp[2];
    }
};
// @lc code=end

