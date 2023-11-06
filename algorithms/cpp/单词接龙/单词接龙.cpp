// Source : https://leetcode.cn/problems/word-ladder/description/
// Author : Yanan Wang
// Date   : 2023-11-06

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> vis;
        unordered_set<string> list(wordList.begin(), wordList.end());

        if (beginWord == endWord) {
            return 1;
        }
        if (!list.count(endWord)) {
            return 0;
        }

        queue<string> q;
        q.push(beginWord);
        vis.insert(beginWord);

        int ans = 1;
        while(!q.empty()) {
            ++ans;
            int size = q.size();
            while(size--) {
                string word = q.front();
                q.pop();
                for (int i = 0; i < word.size(); ++i) {
                    string tmp = word;
                    for (char c = 'a'; c <= 'z'; ++c) {
                        tmp[i] = c;
                        if (tmp == endWord) {
                            return ans;
                        }
                        if (list.count(tmp) && !vis.count(tmp)) {
                            q.push(tmp);
                            vis.insert(tmp);
                        }
                    }
                }
            }
        } 
        return 0;
    }
};