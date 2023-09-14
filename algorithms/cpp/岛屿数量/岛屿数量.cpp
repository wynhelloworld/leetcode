// Source : https://leetcode.cn/problems/flood-fill/description/ 
// Author : Yanan Wang
// Date   : 2023-09-14

class Solution {
private:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int m, n;
    int oldColor, newColor;
public:
    void dfs(vector<vector<int>> &image, int i, int j) {
        image[i][j] = newColor;
        for (int k = 0; k < 4; ++k) {
            int x = i + dx[k], y = j + dy[k];
            if (x >= 0 && x < m && y >= 0 && y < n && image[x][y] == oldColor) {
                dfs(image, x, y);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (color == image[sr][sc]) {
            return image;
        }
        m = image.size(), n = image[0].size();
        oldColor = image[sr][sc];
        newColor = color;
        dfs(image, sr, sc);
        return image;
    }
};