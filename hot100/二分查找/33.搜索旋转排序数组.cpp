/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */
// @lc code=start
#include "vector"
#include <vector>

using namespace std;
class Solution {
public:
    int search_iter(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) {
            return -1;
        }
        if (n == 1) {
            if (target < nums[0] || target > nums[0]) {
                return -1;
            }
            else {
                return 0;
            }
        }

        int l = 0;
        int r = n;

        while (l < r) {
            int mid = (l + r) /2;
            // 如果 target 在左边递增数组中
            if (target >= nums[0]) {
                // 如果 mid 在左边递增数组中
                if (nums[mid] >= nums[0]) {
                    // 在左边递增数组中做 lower_bound
                    if (nums[mid] >= target) {
                        r = mid;
                    }
                    else {
                        l = mid + 1;
                    }
                }
                else {
                    // mid 在右边递增数组中，直接舍弃右半部分
                    r = mid;
                }
            }
            else {
                // 如果 mid 在右边递增数组中
                if (nums[mid] <= nums[n - 1] ) {
                    // 在右边递增数组中做 lower_bound
                    if (nums[mid] >= target) {
                        r = mid;
                    }
                    else{
                        l = mid + 1;
                    }
                }
                else {
                    // mid 在左边递增数组中，直接舍弃左半部分
                    l = mid + 1;
                }
            }
        }
        return l < n && nums[l] == target ? l : -1;
    }

    int search_recur(vector<int>& nums, int l, int r, int target){
        if (l == r) {
            return l;
        }

        int mid = (l + r) / 2;
        // 如果 target 在左边递增数组中
        if (target >= nums[0]) {
            // 说明 mid 在左边递增数组中
            if (nums[mid] >= nums[0]) {
                // 在左边递增数组中做 lower_bound
                if (nums[mid] >= target) {
                    return search_recur(nums, l, mid, target);
                }
                else {
                    return search_recur(nums, mid + 1, r, target);
                }
            }
            else {
                // mid 在右边递增数组中，直接舍弃右半部分
                return search_recur(nums, l, mid, target);
            }
        }
        else {
            // 如果在右边递增数组中
            if (nums[mid] <= nums[nums.size() - 1]) {
                // 在右边递增数组中做 lower_bound
                if (nums[mid] >= target) {
                    return search_recur(nums, l, mid, target);
                }
                else {
                    return search_recur(nums, mid + 1, r, target);
                }
            }
            else {
                // mid 在左边递增数组中，直接舍弃左半部分
                return search_recur(nums, mid + 1, r, target);
            }
        }
    }

    int search(vector<int>& nums, int target){
        int idx = search_recur(nums, 0, nums.size(), target);
        return idx < nums.size() && nums[idx] == target ? idx : -1;
    }
};
// @lc code=end

