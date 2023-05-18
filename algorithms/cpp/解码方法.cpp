// Source : https://leetcode.cn/problems/decode-ways/
// Author : Yanan Wang
// Date   : 2023-05-18

/**
 * 动态规划类题目的一般步骤：
 *   1. 状态表示 
 *        题目给出一个字符串，要求返回解码方法的总数，那么不妨假设dp[i]就是长度为i的字符串的解码方法总数
 *   2. 状态转移方程 
 *        根据一般套路，以dp[i]为结尾或者开头，然后根据i的最近几步（i-2、i-1、i+1、i+2等）推导出方程
 *        根据状态表示，这里可选用dp[i]为结尾开始推导
 *        dp[i]可以认为是 dp[i-1]和第i个字符单独解码时的方法总数 + dp[i-2]和第i-1与第i个字符组合解码时的方法总数
 *        当第i个字符单独解码时，s[i]属于[1, 9]，则dp[i]=dp[i-1]；若s[i]=0，则dp[i]=0
 *        当第i-1和第i个字符组合解码时，s[i-1]组合s[i]属于[10, 26]则dp[i]+ =dp[i-2]
 *   3. 初始化 
 *        若s[0]=0，则dp[0]=0，否则dp[0]=1
 *        若s[0]=0，则dp[1]=0，若s[0]组合s[1]属于[10, 26]并且s[1]!=0，则dp[1]=2，否则dp[1]=1
 *   4. 填表顺序 
 *        从左向右
 *   5. 返回值 
 *        给一个长度为n的字符串s，返回该字符串的总的解码方法，即返回该字符串最后一个字符的dp，即返回dp[n-1]
 */

class Solution {
public:
    int check(char ch)// [1, 9]
    {
        return ch == '0' ? 0 : 1;
    }
    int check(char ch1, char ch2)// [10, 26]
    {
        return (ch1 == '1' || (ch1 == '2' && ch2 <= '6')) ? 1 : 0;
    }
    int numDecodings(string s) {
        int n = s.size();
        if (n == 1) return check(s[0]);
        vector<int> dp(n);
        dp[0] = check(s[0]);
        dp[1] = check(s[0]) * check(s[1]) + check(s[0], s[1]);
        for (int i = 2; i < n; ++i)
        {
            if (check(s[i])) 
                dp[i] = dp[i - 1];
            if (check(s[i - 1], s[i])) 
                dp[i] += dp[i - 2];
        }
        return dp[n - 1];
    }
};