// Source : https://leetcode.cn/problems/number-of-islands/description/ 
// Author : Yanan Wang
// Date   : 2023-09-14

/* 解法一: DFS */
class Solution {
public:
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    int m, n;
    int old_color, new_color;

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (color == image[sr][sc]) {
            return image;
        }
        
        m = image.size();
        n = image[0].size();
        old_color = image[sr][sc];
        new_color = color;
        
        dfs(image, sr, sc);
        return image;
    }

    void dfs(vector<vector<int>> &image, int i, int j) {
        image[i][j] = new_color;
        for (int k = 0; k < 4; ++k) {
            int x = i + dx[k];
            int y = j + dy[k];
            if (x >= 0 && x < m && y >= 0 && y < n && image[x][y] == old_color) {
                dfs(image, x, y);
            }
        }
    }
};

/* 解法二: BFS */
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color) {
            return image;
        }

        int m = image.size();
        int n = image[0].size();
        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {-1, 1, 0, 0};
        int old_color = image[sr][sc];

        queue<pair<int, int>> q;
        q.push({sr, sc});

        while(!q.empty()) {
            auto [a, b] = q.front();
            q.pop();
            image[a][b] = color;
            for (int i = 0; i < 4; ++i) {
                int x = a + dx[i];
                int y = b + dy[i];
                if (x >= 0 && x < m && y >= 0 && y < n && image[x][y] == old_color) {
                    q.push({x, y});
                }
            }
        }
        return image;     
    }
};