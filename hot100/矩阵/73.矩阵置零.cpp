/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

// @lc code=start
#include "vector"
#include <vector>


using namespace std;
class Solution {
public:
    int m = 0, n = 0;
    // 感觉这题背诵一下思路就行了，也没什么好说的
    // 记住！不要直接在原 matrix 上修改，会往后面的行加上 '0'，影响后续判断。
    void setZeroes(vector<vector<int>>& matrix) {
        this->m = matrix.size();
        this->n = matrix[0].size();

        vector<bool> raw_has_zero(m, false);
        vector<bool> col_has_zero(n, false);
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    raw_has_zero[i] = true;
                    col_has_zero[j] = true;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            if (raw_has_zero[i]) {
                matrix[i] = move(vector<int>(n,0));
            }
        }
        
        for (int j = 0; j < n; j++) {
            if (col_has_zero[j]) {
                for (int i = 0; i < m; i++) {
                    matrix[i][j] = 0;
                }
            }
        }

        return;
    }
};
// @lc code=end

