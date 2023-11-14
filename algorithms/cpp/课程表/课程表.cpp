// Source : https://leetcode.cn/problems/course-schedule/description/
// Author : Yanan Wang
// Date   : 2023-11-14

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> edges;
        vector<int> in(numCourses);
        
        for (auto &elem : prerequisites) {
            // b -> a
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
        
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (auto &elem : edges[x]) {
                if (--in[elem] == 0) {
                    q.push(elem);
                }
            }
        }

        for (int i = 0; i < in.size(); ++i) {
            if (in[i] != 0) {
                return false;
            }
        }
        return true;
    }
};