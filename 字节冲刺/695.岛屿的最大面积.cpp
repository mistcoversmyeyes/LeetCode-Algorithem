/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start
#include <functional>
#include <utility>
#include <vector>


using namespace std;
class Solution {
public:
    int m = 0;
    int n = 0;
    auto dfs_visit(vector<vector<int>>& grid, int i, int j) -> int {
        int area = 1;
        grid[i][j] = 0;
        
        vector<pair<int, int>> adjs ={
            {i - 1, j},
            {i + 1, j},
            {i, j - 1},
            {i, j + 1}
        };
        
        
        for (const auto& [x, y] : adjs) {
            auto can_visit = [&] (){
                return x >= 0 && x < m && y >=0 && y < n && grid[x][y] == 1;
            };
            if (can_visit()){
                area += dfs_visit(grid, x, y);
            }
        }

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        m = grid.size();
        n = grid[0].size();


        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n ; j++) {
                if (grid[i][j] == 1) {
                    int cur_area = dfs_visit(grid, i, j);
                    max_area = max(cur_area, max_area);
                }
            }
        }   
        return max_area;
    }
};
// @lc code=end

