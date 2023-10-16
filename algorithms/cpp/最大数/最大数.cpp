// Source : https://leetcode.cn/problems/largest-number/description/ 
// Author : Yanan Wang
// Date   : 2023-10-16

/**
 * 本题对所有的数字进行排序即可，排序规则根据两个数的和大小进行排序，举例如下:
 *      eg:
 *          10, 2
 *          因为 102 < 210
 *          所以 2要排在10的前面
 * 但本题的排序有点特殊，需要证明一个东西: 从nums中任意挑选两个数a、b，使得ab、ba满足全序关系。
 * 离散知识：
 *      假设有一个集合N，从中任意挑选两个数x、y，如果x、y满足全序关系，那么集合N就能够进行排序。
 * 满足全序关系的三个充要条件:
 *      1、完全性:
 *              证明: (ab <= ba || ab >= ba) ==> (ab、ba能够进行排序)
 *                  因为
 *                      a、b分别都是一个数字，拼接后的ab和ba也都分别是一个数字
 *                  所以
 *                      ab、ba两个数字之间必然满足(ab <= ba || ab >= ba)
 *                  既
 *                      (ab <= ba || ab >= ba) ==> (ab、ba能够进行排序)
 *      2、反对称性:
 *              证明: (ab >= ba && ab >= ba) ==> (ab == ba)
 *                  假设a是x位，b是y位
 *                  那么
 *                      ab == 10^y * a + b, ba == 10^x * b + a
 *                  因为
 *                      10^y * a + b <= 10^x * b + a, 10^y * a + b >= 10^x * b + a
 *                  所以
 *                      10^y * a + b <= 10^x * b + a <= 10^y * a + b
 *                  所以
 *                      ab <= ba <= ab
 *                  根据夹逼原理，得
 *                      ab == ba
 *                  既
 *                      (ab >= ba && ab >= ba) ==> (ab == ba)
 *      3、传递性:
 *              证明: (ab >= ba && bc >= cb) ==> (ac >= ca)
 *                  假设a是x位，b是y位，c是z位
 *                  那么
 *                      ab == 10^y * a + b, ba == 10^x * b + a, bc == 10^z * b + c, cb == 10^y * c + b
 *                      ac == 10^z * a + c, ca == 10^x * c + a
 *                  因为
 *                      ab >= ba, bc >= cb
 *                      ac >= ca
 *                  所以 
 *                      10^y * a + b >= 10^x * b + a, 10^z * b + c >= 10^y * c + b  
 *                      10^z * a + c >= 10^x * c + a
 *                  所以
 *                      10^(y-1) * a >= 10^(x-1) * b, 10^(z-1) * b >= 10^(y-1) * c
 *                      10^(z-1) * a >= 10^(x-1) * c
 *                  所以
 *                      (10^(y-1))/(10^(x-1)) * a >= (10^(y-1))/(10^(z-1)) * c
 *                      ac >= ca
 *                  所以
 *                      10^(z-1) * a >= 10^(x-1) * c
 *                      ac >= ca
 *                  所以
 *                      ac >= ca
 *                      ac >= ca
 *                  既
 *                      (ab >= ba && bc >= cb) ==> (ac >= ca)
 */

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        for (auto &i : nums) {
            strs.push_back(to_string(i));
        }
        sort(strs.begin(), strs.end(), [](string &lhs, string &rhs){
            return lhs + rhs > rhs + lhs;
        });
        string ans;
        for (auto &str : strs) {
            ans += str;
        }
        if (ans[0] == '0') {
            return "0";
        }
        return ans;
    }
};