// Source : https://leetcode.cn/problems/sudoku-solver/description/
// Author : Yanan Wang
// Date   : 2023-09-12

// 本题有了《36. 有效的数独》的基础：利用三个数组标记board中是否出现过该数字
// 本题先遍历一遍board，初始化三个标记数组
// 然后就开始递归board中的每个方格，往方格里填数字，去递归下个方格
// dfs要有返回值bool，以便调用者知道这个方格本次填的数字是否成功，当不成功时，这个方格去填下一个数字，当成功时返回true

class Solution {
private:
    bool checkRow[9][10];
    bool checkCol[9][10];
    bool checkGrid[3][3][10];
public:
    bool dfs(vector<vector<char>> &board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if('.' == board[i][j]) {
                    for (int num = 1; num <= 9; ++num) {
                        if (checkRow[i][num] || checkCol[j][num] || checkGrid[i / 3][j / 3][num]) {
                            continue;
                        }
                        board[i][j] = num + '0';
                        checkRow[i][num] = checkCol[j][num] = checkGrid[i / 3][j / 3][num] = true;
                        if (dfs(board)) return true;
                        board[i][j] = '.';
                        checkRow[i][num] = checkCol[j][num] = checkGrid[i / 3][j / 3][num] = false;
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if ('.' != board[i][j]) {
                    int num = board[i][j] - '0';
                    checkRow[i][num] = checkCol[j][num] = checkGrid[i / 3][j / 3][num] = true;
                }
            }
        }
        dfs(board);
    }
};