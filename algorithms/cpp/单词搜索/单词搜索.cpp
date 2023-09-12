// Source : https://leetcode.cn/problems/word-search/description/
// Author : Yanan Wang
// Date   : 2023-09-12

// 当匹配到一个字符后，有四个方向可以去匹配下一个字符，但这四个方向不能有重复的，所以用一个used来进行标记
// 每次在匹配到一个字符后，都会去另外几个方向匹配下一个字符，那么这就是递归函数体
// 在遍历四个方向时，可以选择写四次函数调用，也可以用方向向量（用dx和dy来表示偏移量（方向））
// 还要注意的是，dfs要有返回值bool，要让调用者知道本次的选择是否正确，当正确时返回true，当错误时重新选下一个字符

class Solution {
private:
    int m, n;
    vector<vector<bool>> used;
    vector<int> dx, dy;
public:
    bool dfs(vector<vector<char>> &board, int i, int j, string &word, int pos) {
        if (pos == word.size()) return true;
        for (int k = 0; k < 4; ++k) {
            int x = i + dx[k], y = j + dy[k];
            if (x >= 0 && x < m && y >= 0 && y < n && !used[x][y] && board[x][y] == word[pos]) {
                used[x][y] = true;
                if (dfs(board, x, y, word, pos + 1)) return true;
                used[x][y] = false;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size();
        used.resize(m, vector<bool>(n, false));
        dx = {0, 0, 1, -1}, dy = {-1, 1, 0, 0};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0]) {
                    used[i][j] = true;
                    if (dfs(board, i, j, word, 1)) return true;
                    used[i][j] = false;
                }
            }
        }
        return false;
    }
};