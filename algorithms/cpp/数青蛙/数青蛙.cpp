// Source : https://leetcode.cn/problems/minimum-number-of-frogs-croaking/description/
// Author : Yanan Wang
// Date   : 2023-08-19

/**
 * 为了追求一个完整的croak，所以在遍历croakOfFrogs时，若遇到'r'则需要看前面是否有'c'，若遇到'o'则需要看前面是否有'r'...，所以建立一个表
 *  |---|---|---|---|---|
 *  | c | r | o | a | k |
 *  |---|---|---|---|---|
 *  |   |   |   |   |   |
 *  |---|---|---|---|---|
 * 这张表的含义是：假设'o' == 1，则意味着已经有一个蛙鸣声叫到了'o'，
 *              如果之后遍历到了'a'，则'o' == 0， 'a' == 1，
 *              意味着，已经有一个蛙鸣声叫到了'a'
 * 所以，针对r o a k，若遍历到了这些字符，则这些字符的前一个字符必须>0，然后前一个字符--，这些字符++
 *      但是c则不同，因为题目要求返回最少数量的青蛙，当k>0时，意味着已经有k个青蛙完成了蛙鸣。那么此时遍历到c时，就可以用这k个青蛙中的一个继续去蛙鸣，
 *      所以针对c，若k==0，c++；
 *               若k>0，k--，c++
 * 最后还要检查，c r o a 是否为0，因为若不为0则意味着有蛙鸣声没有完成。
 */

class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        string target = "croak";
        int n = target.size();
        vector<int> hash(n);
        unordered_map<char, int> index;
        for (int i = 0; i < n; ++i)
            index[target[i]] = i;
        for (auto &ch : croakOfFrogs) {
            if (ch == 'c') {
                if (hash[n - 1] != 0) --hash[n - 1];
                ++hash[0];
            } else {
                int i = index[ch];
                if (hash[i - 1] == 0) return -1;
                --hash[i - 1];
                ++hash[i];
            }
        }
        for (int i = 0; i < n - 1; ++i) 
            if (hash[i] != 0)
                return -1;
        return hash[n - 1];
    }
};