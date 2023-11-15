// Source : https://leetcode.cn/problems/course-schedule-ii/description/
// Author : Yanan Wang
// Date   : 2023-11-15

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edges(numCourses);
        vector<int> in(numCourses);
        
        for (auto &elem : prerequisites) {
            int a = elem[0];
            int b = elem[1];
            edges[b].push_back(a);
            ++in[a];
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (in[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;
        while (!q.empty()) {
            int b = q.front();
            q.pop();
            ans.push_back(b);
            for (auto &a : edges[b]) {
                if (--in[a] == 0) {
                    q.push(a);
                }
            }
        }

        for (int i = 0; i < numCourses; ++i) {
            if (in[i] != 0) {
                return {};
            }
        }
        return ans;
    }
};