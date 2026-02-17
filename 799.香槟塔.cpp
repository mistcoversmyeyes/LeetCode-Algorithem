/*
 * @lc app=leetcode.cn id=799 lang=cpp
 *
 * [799] 香槟塔
 */

// @lc code=start
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
double champagneTower(int poured, int query_row, int query_glass) {
    // 简单粗暴：逐层模拟溢出
    vector<double> row(1, poured);  // 第0行
    
    for (int i = 0; i < query_row; i++) {
        vector<double> next(i + 2, 0.0);  // 下一行
        
        for (int j = 0; j <= i; j++) {
            double overflow = max(0.0, row[j] - 1);  // 只计算溢出部分
            next[j] += overflow / 2;      // 左下
            next[j + 1] += overflow / 2;  // 右下
        }
        
        row = move(next);  // 滚动数组
    }
    
    return min(1.0, row[query_glass]);  // 杯子最多1，不能溢出
}
};
// @lc code=end

