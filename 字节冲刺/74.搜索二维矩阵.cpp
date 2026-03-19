/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0;
        int j = matrix[0].size() - 1;

        // 循环开始的时候，将 target 与右上角的值比较
        // 选择删除一行/一列/返回当前位置
        while (true){
            if (target > matrix[i][j]) {
                i++;
                if (i >= matrix.size()) {
                    break;
                }
            }
            else if (target == matrix[i][j]) {
                return true;
            }
            else {
                j--;
                if (j < 0) {
                    break;
                }
            }
        }

        return false;

    }
};
// @lc code=end

