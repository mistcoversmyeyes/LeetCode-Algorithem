/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除了自身以外数组的乘积
 */

// @lc code=start
#include <cstdio>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // output[i] = pre_mult[i - 1] * post_mult[i + 1]
        vector<int> output = vector(nums.size(), 0);
        
        // 第一次遍历，计算前缀积，存储在结果数组中
        int pre_mult = 1;
        for (int i = 0; i < nums.size();i++){
            output[i] = pre_mult;
            
            pre_mult *= nums[i];
        }

        // 第二次遍历，计算后缀积，并乘到结果数组中
        int post_mult = 1;
        for (int i = nums.size() - 1;i >= 0;i--){
            output[i] *= post_mult;
            post_mult *= nums[i];
        }

        return output;
    }
};
// @lc code=end

