#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool dfs(int r, int c, int idx, int n, int m, vector<vector<char>>& board, string& word, vector<vector<int>>& vis) {
        if (idx == word.size()) return true;

        vector<int> dx{0, 0, 1, -1};
        vector<int> dy{1, -1, 0, 0};

        for (int i = 0; i < 4; i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && vis[nr][nc] == 0 && board[nr][nc] == word[idx]) {
                vis[nr][nc] = 1;
                if (dfs(nr, nc, idx + 1, n, m, board, word, vis)) return true;
                vis[nr][nc] = 0;
            }
        }

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    vector<vector<int>> vis(n, vector<int>(m, 0));
                    vis[i][j] = 1;
                    if (dfs(i, j, 1, n, m, board, word, vis)) return true;
                }
            }
        }

        return false;
    }
};
