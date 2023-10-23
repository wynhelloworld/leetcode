// Source : https://leetcode.cn/problems/optimal-division/description/
// Author : Yanan Wang
// Date   : 2023-10-23

/**
 * 本题, 无论如何➕括号, 最终的形式一定是 x/y , 那么想让x/y最大, 那就让x最大, y最小
 *       一个数学原理: a/(b/c/d/e)  ==  a*c*d*e/b
 *       并且, 本题无论如何➕括号, a一定在分子上, b一定在分母上,
 *       所以, 可以用上面的数学原理, 将所有的其它数字全部转移到分子上, 即可使得除法最优
 */

class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return to_string(nums[0]);
        } 
        if (n == 2) {
            return to_string(nums[0]) + "/" + to_string(nums[1]);
        }
        string ans(to_string(nums[0]) + "/(" + to_string(nums[1]));
        for (int i = 2; i < nums.size(); ++i) {
            ans += "/" + to_string(nums[i]);            
        }
        ans += ")";
        return ans;
    }
};