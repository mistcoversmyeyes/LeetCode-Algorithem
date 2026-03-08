/*
 * @lc app=leetcode.cn id=1980 lang=cpp
 *
 * [1980] 找出不同的二进制字符串
 */

// @lc code=start
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
    auto to_binary_string(int num, int n) -> string {
        string result(n, '0');
        for (int i = 0; i < n; ++i) {
            if (num & (1 << i)) {
                result[n - 1 - i] = '1';
            }
        }
        return result;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        // 哈希法，将所有字符串转换为整数，存储在哈希表中，然后从0到2^n-1的整数中找出第一个不在哈希表中的整数，转换为二进制字符串返回。
        auto cmp = [](const string& s) -> size_t {
            size_t result = 0;
            for (const auto& ch : s) {
                result = result * 2 + (ch - '0');
            }
            return result;
        };

        unordered_set<string, decltype(cmp)> sets(nums.begin(), nums.end(), nums.size(), cmp);

        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int num = i;
            string s = to_binary_string(num, n);
            if (sets.find(s) == sets.end()) {
                return s;
            }
        }
        return to_binary_string(n, n);
    }
};
// @lc code=end

