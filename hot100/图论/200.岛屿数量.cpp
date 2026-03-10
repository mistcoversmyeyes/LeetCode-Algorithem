/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
#include <cstdlib>
#include <functional>
#include <tuple>
#include <utility>
#include <vector>
#include <queue>

using namespace std;
class Solution {
public:

    auto is_land(vector<vector<char>>& grid, int x, int y, int m, int n) -> bool {
        if (x < 0 || y < 0 || x >= m || y >= n){
            return false;
        }
        return grid[x][y] == '1';
    }


    auto dfs_visit(vector<vector<char>>& grid, int i, int j, int m, int n)-> void{
        grid[i][j] = '0';
        
        vector<tuple<int, int>> adjacents = {
            {i - 1,j},
            {i + 1,j},
            {i, j - 1},
            {i, j + 1}
        };
        for (const auto& [a, b] : adjacents){
            if (is_land(grid, a, b, m, n)) {
                dfs_visit(grid, a, b, m, n);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int num_island = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if (is_land(grid, i, j, m, n)) {
                    dfs_visit(grid, i, j, m, n);
                    num_island++;
                }
            }
        }

        return num_island;
    }
};

// @lc code=end

