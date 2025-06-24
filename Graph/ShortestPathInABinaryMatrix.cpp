#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if (grid[0][0] != 0 || grid[n - 1][m - 1] != 0)
            return -1;

        queue<pair<int, pair<int, int>>> q;
        q.push({1, {0, 0}}); 
        grid[0][0] = 1;

        vector<int> dx = {0, 0, 1, -1, 1, 1, -1, -1};
        vector<int> dy = {1, -1, 0, 0, 1, -1, 1, -1};

        while (!q.empty()) {
            auto [dist, coord] = q.front();
            auto [r, c] = coord;
            q.pop();

            if (r == n - 1 && c == m - 1) return dist;

            for (int i = 0; i < 8; i++) {
                int nr = r + dx[i];
                int nc = c + dy[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 0) {
                    q.push({dist + 1, {nr, nc}});
                    grid[nr][nc] = 1; 
                }
            }
        }

        return -1;
    }
};

