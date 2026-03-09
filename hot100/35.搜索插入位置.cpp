/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
#include "vector"
#include "iostream"
#include <vector>

using namespace std;
class Solution {
public:
    int searchInsert_recursion(vector<int>& nums, int target, int left, int right) {
        if (left > right) {
            return left;
        }
        int mid = (right + left) / 2;
        // cout << "mid:" << mid << endl;
        if (target < nums[mid]) {
            return searchInsert_recursion(nums, target, left, mid - 1);
        }
        else if (target == nums[mid]) {
            return mid;
        }
        else {
            return searchInsert_recursion(nums, target, mid + 1, right);
        }
    }

    int searchInsert_iteration(vector<int>& nums, int target){
        int l = 0;
        int r = nums.size() - 1;
        int mid = (l  + r)/2;

        while (l <= r) {
            if (target < nums[mid]) {
                r = mid - 1;
            }
            else if (target == nums[mid]) {
                return mid;
            }
            else {
                l = mid + 1;
            }
            mid = (l + r) / 2;
        }

        return l;
    }

    int searchInsert(vector<int>& nums, int target) {
        return searchInsert_iteration(nums, target);
    }
};
// @lc code=end

