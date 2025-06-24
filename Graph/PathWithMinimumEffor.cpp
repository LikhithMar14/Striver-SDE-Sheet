#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dis(n, vector<int>(m, 1e9));

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({0, {0, 0}});
        dis[0][0] = 0;

        vector<int> dx{0, 0, 1, -1};
        vector<int> dy{1, -1, 0, 0};

        while (!pq.empty()) {
            auto [el, pos] = pq.top();
            auto [r, c] = pos;
            pq.pop();

            //Important
            if (r == n - 1 && c == m - 1) return el;

            for (int i = 0; i < 4; i++) {
                int nr = r + dx[i];
                int nc = c + dy[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    int diff = abs(heights[nr][nc] - heights[r][c]);
                    int effort = max(el, diff);

                    if (effort < dis[nr][nc]) {
                        dis[nr][nc] = effort;
                        pq.push({effort, {nr, nc}});
                    }
                }
            }
        }

        return 0; 
    }
};
