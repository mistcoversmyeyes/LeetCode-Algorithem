/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        auto cmp = [] (int a , int b){ return a >= b;};
        priority_queue<int,vector<int>, decltype(cmp)> min_heap(cmp);
        
        for (int i = 0; i < nums.size(); i++) {
            min_heap.push(nums[i]);
            if (min_heap.size() > k) {
                min_heap.pop();
            }
        }
        
        return min_heap.top();
    }
    
};
// @lc code=end

