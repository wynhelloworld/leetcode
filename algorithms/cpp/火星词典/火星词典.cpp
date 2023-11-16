// Source : https://leetcode.cn/problems/Jf1JuT/description/
// Author : Yanan Wang
// Date   : 2023-11-16

class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, unordered_set<char>> edges;
        unordered_map<char, int> in;
        for (auto &word : words) {
            for (auto &c : word) {
                in[c] = 0;
            }
        }
        int n = words.size();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                string &word1 = words[i];
                string &word2 = words[j];
                int k = 0;
                while (k < word1.size() && k < word2.size()) {
                    if (word1[k] != word2[k]) {
                        if (!edges[word1[k]].count(word2[k])) {
                            edges[word1[k]].insert(word2[k]);
                            ++in[word2[k]];
                        }
                        break;
                    }
                    ++k;
                }
                if (k < word1.size() && k == word2.size()) {
                    return "";
                }
            }
        }
        queue<char> q;
        for (auto &[k, v] : in) {
            if (v == 0) {
                q.push(k);
            }
        }      
        string ans;
        while (!q.empty()) {
            auto c = q.front();
            q.pop();
            ans.push_back(c);
            for (auto &elem : edges[c]) {
                if (--in[elem] == 0) {
                    q.push(elem);
                }
            }
        }
        for (auto &[k, v] : in) {
            if (v != 0) {
                return "";
            }
        }
        return ans;
    }
};