/*
 * @lc app=leetcode.cn id=994 lang=cpp
 *
 * [994] 腐烂的橘子
 */

// @lc code=start
#include <functional>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
class Solution {
public:
    bool is_accessable(vector<vector<int>>& grid, int i , int j){
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) {
            return false;
        }
        return grid[i][j] == 1;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int cur_time = 0;
        int m = grid.size();
        int n = grid[0].size();
        int fresh_count = 0;
        int bad_count = 0;

        queue<pair<int, int>> nodes;
        for (int i =  0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    nodes.push({i, j});
                    bad_count++;
                }
                else if (grid[i][j] == 1) {
                    fresh_count++;
                }
            }
        }

        if (fresh_count == 0) {
            return 0;
        }
        while (!nodes.empty()) {
            int size = nodes.size();
            bool has_new_bad = false;
            for (int i  = 0; i < size; i++) {
                const auto& [x, y] = nodes.front();
                vector<pair<int, int>> adjs = {
                    {x - 1, y},
                    {x + 1, y},
                    {x, y - 1},
                    {x, y + 1},
                };

                for (const auto& [a,b] : adjs) {
                    if (is_accessable(grid, a, b)) {
                        grid[a][b] = 2;
                        fresh_count--;
                        bad_count++;
                        has_new_bad = true;
                        nodes.push({a, b});    
                    }
                }
                nodes.pop();
            }
            if (has_new_bad) {
                cur_time++;
            }
        }

        // 检查是否还有新鲜橘子
        if (fresh_count > 0) {
            return -1;
        }

        return cur_time;
    }
};
// @lc code=end

