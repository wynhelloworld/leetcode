// Source : https://leetcode.cn/problems/fruit-into-baskets/description/
// Author : Yanan Wang
// Date   : 2023-08-03

/**
 * 把小作文读完之后，题目可以归纳为：从fruits中找最长的子数组，并且子数组中的元素种类不超过2。
 * 本题的暴力解法：
 *         left和right两层循环，每次遍历时用hash记录下元素的种类数和个数，种类数小于2时，记录下最长长度，当种类数大于2时，重新遍历。
 * 对暴力解法的优化：
 *         当种类数量大于2时，无需重新遍历，只需从left开始，去掉记录在hash里的元素即可，当hash里的种类数量重新<=2时，right再向遍历。
 *         即，滑动窗口。
 */

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int result = 0;
        unordered_map<int, int> hash;
        for (int left = 0, right = 0; right < fruits.size(); ++right) {
            ++hash[fruits[right]];
            while (hash.size() > 2) {
                if (0 == --hash[fruits[left]])
                    hash.erase(fruits[left]);
                ++left;
            }
            result = max(result, right - left + 1);
        }
        return result;
    }
};