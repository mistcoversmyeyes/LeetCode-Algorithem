/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
#include "vector"
#include <list>
#include <queue>
#include <vector>

using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // auto adj_matrix = vector<vector<int>>(numCourses, vector<int>(numCourses, 0));
        // for (auto& prereq : prerequisites) {
        //     adj_matrix[prereq.back()][prereq.front()]++;
        // }

        auto adj_list = vector<list<int>>(numCourses, list<int>());
        for (auto& prereq : prerequisites) {
            adj_list[prereq.back()].push_back(prereq.front());
        }


        auto in_degree = vector<int>(numCourses, 0);
        
        auto get_indegree = [& prerequisites, & in_degree] (){
            for (auto& prereq : prerequisites) {
                in_degree[prereq.front()]++;
            }
        };
        get_indegree();
        
        auto qu = queue<int>();
        for (int i = 0; i < in_degree.size(); i++) {
            if (in_degree[i] == 0) {
                qu.push(i);
            }
        }

        while (!qu.empty()) {
            int node = qu.front();
            for (auto& adj_node : adj_list[node]) {
                in_degree[adj_node]--;
                if (in_degree[adj_node] == 0) {
                    qu.push(adj_node);
                }
            }

            qu.pop();
        }

        for (auto& degree : in_degree) {
            if (degree != 0) {
                return false;
            }
        }

        return true;
    }
};
// @lc code=end

