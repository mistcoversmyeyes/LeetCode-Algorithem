/*
 * @lc app=leetcode.cn id=3212 lang=cpp
 *
 * [3212] 统计 X 和 Y 频数相等的子矩阵数量
 */

// @lc code=start
#include <utility>
#include <vector>

using namespace std;
class Solution {
public:
    int m ,n;

    pair<int, int> to_fre_pair(char c){
        if (c == 'X') {
            return {1, 0};
        }
        else if (c == 'Y'){
            return {0,  1};
        }
        else {
            return {0, 0};
        }
    }

    pair<int, int> add(pair<int, int> a, pair<int, int> b){
        return {a.first + b.first, a.second + b.second};
    }

    pair<int, int> sub(pair<int , int> a, pair<int, int> b){
        return {a.first - b.first   , a.second - b.second};
    }

    void vaildate_and_inc(pair<int, int> a, int& cnt){
        if (a.first > 0 && a.first == a.second) {
            cnt++;
        }
    }

    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int cnt = 0;

        // 设 dp[i][j] 为 以 (i,j) 为边角的子矩阵中 X 和 Y 的频数 {fre_x, fre_y}
        m = grid.size();
        n = grid[0].size();
        auto dp = vector<vector<pair<int , int>>>(m, vector<pair<int, int>>(n, {0,0}));

        dp[0][0] = to_fre_pair(grid[0][0]); 
        vaildate_and_inc(dp[0][0], cnt);
        
        // dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] (i >= 1 && j >= 1)
        // dp[i][0] = dp[i - 1][0] + grid[i][j].to_fre_pair (i >= 0)
        // dp[0][j] = dp[0][j - 1] + grid[0][j].to_fre_pair (j >= 0)
        // dp[0][0] = grid[0][0].to_fre_pair 

        for (int i = 1;i < m;i++){
            dp[i][0] = add(dp[i - 1][0], to_fre_pair(grid[i][0]));
            vaildate_and_inc(dp[i][0], cnt);
        }

        for (int j = 1; j < n; j++) {
            dp[0][j] = add(dp[0][j - 1],  to_fre_pair(grid[0][j]));
            vaildate_and_inc(dp[0][j], cnt);
        }

        for (int i = 1; i < m;i++){
            for (int j = 1;j < n;j++){
                dp[i][j] = sub(add(dp[i - 1][j],dp[i][j - 1]),dp[i - 1][j -  1]);
                dp[i][j] = add(dp[i][j],to_fre_pair(grid[i][j]));
                vaildate_and_inc(dp[i][j], cnt);
            }
        }


        return cnt;
    }
};
// @lc code=end

