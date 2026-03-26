/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
#include "vector"
#include <algorithm>
#include <vector>

using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // dp[i][j] 为 从 (0,0) 到 (i, j) 的所有路径的最小和
        // dp[0][0] = grid[0][0]
        // dp[i][j] = min(dp[i - 1]dp[j], dp[i][j - 1]) (i >=1 && j >= 1)
        // dp[i][j] = dp[i - 1][j] (j == 0)
        // dp[i][j] = do[i][j - 1] (i == 0)

        auto dp = vector<vector<int>>(m, vector<int>(n, 0));
        
        dp[0][0] = grid[0][0];
        
        for (int i = 1; i < m; i++) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }

        for (int j = 1; j < n ; j++) {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }

        for (int i = 1;i < m;i++){
            for (int j = 1;j < n; j++) {
                dp[i][j] = grid[i][j];
                dp[i][j] += min(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[m - 1][n - 1];
    }
};
// @lc code=end

