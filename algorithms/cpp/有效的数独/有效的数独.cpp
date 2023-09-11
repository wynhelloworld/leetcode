// Source : https://leetcode.cn/problems/valid-sudoku/
// Author : Yanan Wang
// Date   : 2023-09-11

// 本题利用三个数组来快速判断某行、某列、某块有重复数字
// 用bool checkRow[9][10]标识某行出现过的数字
// 用bool checkCol[9][10]标识某列出现过的数字
// 用bool checkGrid[3][3][10]标识某块出现过的数字

class Solution {
    // 全局变量会初始化为false
    bool checkRow[9][10];
    bool checkCol[9][10];
    bool checkGrid[3][3][10];
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    if (checkRow[i][num] || checkCol[j][num] || checkGrid[i / 3][j / 3][num]) {
                        return false;
                    }
                    checkRow[i][num] = true;
                    checkCol[j][num] = true;
                    checkGrid[i / 3][j / 3][num] = true;    
                }
            }
        }
        return true;
    }
};