/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start;
#include <cstdio>
#include <vector>


using namespace std;
class Solution {
public:

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int i = 0;
        int j = 0;

        int bottom = 0;
        int top = matrix[0].size() - 1;
        int left = 0;
        int right = matrix.size() - 1;
        auto ret = vector<int>();

        while (true) {
            for (i = left, j = bottom; j <= top; j++) {
                ret.push_back(matrix[i][j]);
                // printf("i:%d, j: %d\n", i, j);
            }
            j--;
            left++;
            if (bottom > top || left > right) break;
            
            for (i = left, j = top; i <=right; i++) {
                ret.push_back(matrix[i][j]);
                // printf("i:%d, j: %d\n", i, j);
            }
            top--;
            i--;
            if (bottom > top || left > right) break;
            
            for (i = right, j = top; j >= bottom; j--) {
                ret.push_back(matrix[i][j]);
                // printf("i:%d, j: %d\n", i, j);
            }
            j++;
            right--;
            if (bottom > top || left > right) break;
            
            for (i = right ,j = bottom; i >= left; i--) {
                ret.push_back(matrix[i][j]);
                // printf("i:%d, j: %d\n", i, j);
            }
            i++;
            bottom++;
            if (bottom > top || left > right) break;
        }

        return ret;
    }
};
// @lc code=end

