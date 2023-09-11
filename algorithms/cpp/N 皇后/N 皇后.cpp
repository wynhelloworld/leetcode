// Source : https://leetcode.cn/problems/n-queens/description/
// Author : Yanan Wang
// Date   : 2023-09-11

// 本题先画出一个递归树，每次递归时，遍历皇后在该行放的位置
// 在递归树中，每一层树代表一行
// 本题的重点是如何进行剪枝：
//         用三个数组表示皇后在某列、某条正对角线、某条副对角线上是否出现过
//        （因为递归是按行来进行的，所以不用判断某行是否出现过，因为在递归该行时，皇后一定没在该行出现过）
//         用bool checkCol[] 来标识某行是否出现过皇后
//         用bool checkDig1[] 来标识某正对角线是否出现过皇后
//         用bool checkDig2[] 来标识某副对角线是否出现过皇后
//         针对正、副对角线的判断，用到了一个数学知识：同一条对角线上的y-x是一个固定值
//         对于正对角线的一次函数：y = x + b，那么y-x是定值，根据该原理，所以处于该对角线上的点都能取到该定值，所以就能判断该对角线上是否出现过皇后， 但y-x有可能是负数，所以加上一个定值，所以最终定值为y-x+n-1
//         对于副对角线的一次函数：y = -x + b，原理根正对角线一样，但这里不用加定值，因为y+x不会出现负值

class Solution {
private:
    vector<bool> checkCol;
    vector<bool> checkDig1;
    vector<bool> checkDig2;
    vector<vector<string>> ans;
    vector<string> path;
public:
    void dfs(int n, int row = 0) {
        if (row == n) {
            ans.push_back(path);
            return;
        }
        for (int col = 0; col < n; ++col) {
            if (checkCol[col] || checkDig1[row - col + n - 1] || checkDig2[row + col]) {
                continue;
            }
            path[row][col] = 'Q';
            checkCol[col] = checkDig1[row - col + n - 1] = checkDig2[row + col] = true;
            dfs(n, row + 1);
            path[row][col] = '.';
            checkCol[col] = checkDig1[row - col + n - 1] = checkDig2[row + col] = false;
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        checkCol.resize(n, false);
        checkDig1.resize(n * 2 - 1, false);
        checkDig2.resize(n * 2 - 1, false);
        path.resize(n, string(n, '.'));
        dfs(n);
        return ans;
    }
};