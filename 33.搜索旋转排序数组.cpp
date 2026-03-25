/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */
// @lc code=start
#include "vector"

using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        // 先找出原有的数组旋转的位置 k
        int l = 0;
        int r = nums.size();
        // 不变量，保证循环过程中始终保持
        // nums[0...l] <= max
        // nums[r..n] > min
        while (l < r) {
            int mid = (l + r)/2;
            if (nums[mid] < nums[0]) {
                r = mid;
            }
            else if (nums[mid] >= nums[0]) {
                l = mid + 1;
            }
        }

        int k = l;
        
        // 在虚拟数组中二分
        l = 0, r = n;
        while (l < r) {
            int mid = (l + r) / 2;
            int realMid = (mid + k) % n;
            if (nums[realMid] == target) return realMid;
            if (nums[realMid] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return -1;
    }
};
// @lc code=end

