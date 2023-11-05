// Source : https://leetcode.cn/problems/minimum-genetic-mutation/description/
// Author : Yanan Wang
// Date   : 2023-11-05

class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> hash(bank.begin(), bank.end());
        unordered_set<string> vis;
        string change = "ACGT";
        if (startGene == endGene) {
            return 0;
        }
        if (hash.count(endGene) == 0) {
            return -1;
        }

        int ans = 0;
        queue<string> q;
        q.push(startGene);
        vis.insert(startGene);
        while(!q.empty()) {
            ++ans;
            int size = q.size();
            while(size--) {
                string gene = q.front();
                q.pop();
                for (int i = 0; i < 8; ++i) {
                    string tmp = gene;
                    for (int j = 0; j < 4; ++j) {
                        tmp[i] = change[j];
                        if (hash.count(tmp) != 0 && vis.count(tmp) == 0) {
                            if (tmp == endGene) {
                                return ans;
                            }
                            q.push(tmp);
                            vis.insert(tmp);
                        }
                    }
                }
            }
        }
        return -1;
    }
};