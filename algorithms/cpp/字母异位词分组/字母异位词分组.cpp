// Source : https://leetcode.cn/problems/group-anagrams/description/
// Author : Yanan Wang
// Date   : 2023-10-08

/**
 * 把所有的元素都排一下序，若元素相等就代表是字母异位词
 * 创建一个string -- vector[string] 的hash
 * 在遍历的过程中，把排好序的str和原str直接插入就好
 * 最后取出hash中所有的value
 */

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        for (auto &str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            hash[key].push_back(str);
        }
        vector<vector<string>> ans;
        for (auto &[x, y] : hash) {
            ans.push_back(y);
        }
        return ans;
    }
};