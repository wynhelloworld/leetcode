// Source : https://leetcode.cn/problems/matrix-block-sum/description/
// Author : Yanan Wang
// Date   : 2023-08-16

/** 
 *            i        k = 1
 *      x  x  x  x
 *      x  *  x  x
 *    j x  x  #  x
 *      x  x  x  *
 * 本题的意思就是，返回一个矩阵，矩阵中的每个元素等于（看上图）：由mat矩阵中，[i-k, j-k]到[i+k, j+k]对角线围成的矩阵的和。
 * [i-k, j-k]到[i+k, j+k]对角线围成的矩阵的和求法：
 *      1、先制造一个前缀和矩阵dp：
 *          dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + mat[i][j];
 *          但为了处理边界情况，dp多开辟一行和一列，方程改为如下：
 *          dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + mat[i - 1][j - 1];
 *      2、获取矩阵的左上角和右下角下标：
 *         int x1 = i-k, y1 = j-k;
 *         int x2 = i+k, y2 = j+k;
 *         但仅仅上面这样的写法，两下标是会越界的，所以下标获取改为如下：
 *         int x1 = max(0, i-k), y1 = max(0, j-k);
 *         int x2 = min(m-1, i+k), y2 = min(n-1, j+k);
 *      3、矩阵求和：
 *         ans[i][j] = dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1];
 *         但这样是不对的，因为ans和dp是存在下标映射关系的，因为当初的dp多开辟了一行和一列。解决办法就是
 *                                                                                  1、要么在矩阵求和这里给dp的下标都加1；
 *                                                                                  2、要么在下标获取那里统一都加1。  
 *      
 */

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + mat[i - 1][j - 1];
            }
        }
        vector<vector<int>> ans(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int x1 = max(0, i - k) + 1, y1 = max(0, j - k) + 1;
                int x2 = min(m - 1, i + k) + 1, y2 = min(n - 1, j + k) + 1;
                ans[i][j] = dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1];
            }
        }
        return ans;
    }
};

