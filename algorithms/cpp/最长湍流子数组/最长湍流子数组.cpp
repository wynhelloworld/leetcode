// Source : https://leetcode.cn/problems/longest-turbulent-subarray/
// Author : Yanan Wang
// Date   : 2023-06-06

/**
 * 动态规划类题目的一般步骤：
 *   1. 状态表示
 *        设f[i]表示以i结尾的子数组中最后呈上升趋势的湍流子数组的最长长度
 *        设g[i]表示以i结尾的子数组中最后呈下降趋势的湍流子数组的最长长度
 *   2. 状态转移方程
 *        eg: [a, b, c, d]
 *                      i
 *                 |- c < d,  g[i - 1] + 1 
 *           f[i] -|- c = d,  1
 *                 |- c > d,  1
 *
 *                 |- c < d,  1
 *           g[i] -|- c = d,  1
 *                 |- c > d,  f[i - 1] + 1 
 *   3. 初始化
 *        f[0] = g[0] = 1, 因为一个元素也能称为长度为1的湍流子数组
 *   4. 填表顺序
 *        一起从左向右
 *   5. 返回值
 *        f和g里元素的最大值
 */

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        vector<int> f(n, 1);
        vector<int> g(n, 1);
        int result = 1;
        for (int i = 1; i < n; ++i) {
            if (arr[i - 1] < arr[i]) {
                f[i] = g[i - 1] + 1;
            } 
            if (arr[i - 1] > arr[i]) {
                g[i] = f[i - 1] + 1;
            } 
            result = max(result, max(f[i], g[i]));
        }
        return result;
    }
};