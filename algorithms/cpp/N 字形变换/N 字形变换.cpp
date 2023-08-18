// Source : https://leetcode.cn/problems/zigzag-conversion/description/
// Author : Yanan Wang
// Date   : 2023-08-18

/**
 * 方法一：模拟
 *        开一个矩阵，然后把s按Z字形排列放进去，然后遍历矩阵，将每个字符添加到ans。
 * 方法二：找规律
 *   s = "PAYPALISHIRING", numRows = 4
 *   这是Z字形矩阵图
 *     |---|---|---|---|---|---|---|
 *     | P |   |   | I |   |   | N |
 *     |---|---|---|---|---|---|---|
 *     | A |   | L | S |   | I | G |
 *     |---|---|---|---|---|---|---|
 *     | Y | A |   | H | R |   |   |
 *     |---|---|---|---|---|---|---|
 *     | P |   |   | I |   |   |   |
 *     |---|---|---|---|---|---|---|
 *  这是每个字母在s中的坐标
 *     |---|---|---|---|---|---|---|
 *     | 0 |   |   | 6 |   |   |12 |
 *     |---|---|---|---|---|---|---|
 *     | 1 |   | 5 | 7 |   |11 |13 |
 *     |---|---|---|---|---|---|---|
 *     | 2 | 4 |   | 8 |10 |   |   |
 *     |---|---|---|---|---|---|---|
 *     | 3 |   |   | 9 |   |   |   |
 *     |---|---|---|---|---|---|---|
 * 根据以上坐标可以发现规律：
 *      d = 2 * numRows - 2;   0 < k < n-1
 *      第0行：0 -> 0+d -> 0+2d -> ...
 *      第k行：(k -> d-k) -> (k+d -> d-k+d) -> (k+2d -> d-k+2d) ...       
 *      第n-1行：n-1 -> n-1+d -> n-1+2d -> ...
 * 按照规律，一行一行的将字符添加到ans。
 */

class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size(), d = 2 * numRows - 2;
        if (numRows == 1 || numRows >= n) return s;
        string ans;
        for (int i = 0; i < n; i += d)
            ans += s[i];
        for (int k = 1; k < numRows - 1; ++k) {
            for (int i = k, j = d - k; i < n; i += d, j += d) {
                ans += s[i];
                if (j < n) ans += s[j];
            }
        }
        for (int i = numRows - 1; i < n; i += d)
            ans += s[i];
        return ans;
    }
};