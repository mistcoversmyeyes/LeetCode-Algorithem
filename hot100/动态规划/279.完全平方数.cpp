/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
#include <algorithm>
#include <climits>
#include <cstdint>
#include <vector>


using namespace std;
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX / 2);
        // base case
        dp[0] = 0;

        for (int i = 0; i <= n; i++) {
            for (int j = 1; i - j * j >= 0; j++) {
                dp[i] = min(dp[i - j*j] + 1, dp[i]);
            }
        }

        return dp[n];
    }
};
// @lc code=end

