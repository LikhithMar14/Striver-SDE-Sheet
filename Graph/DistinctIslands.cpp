#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    void dfs(int i, int j, int start, int end, vector<vector<int>>& grid, vector<pair<int, int>>& temp) {
        grid[i][j] = -1;
        temp.push_back({i - start, j - end});  

        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};
        
        for (int k = 0; k < 4; k++) {
            int row = dx[k] + i;
            int col = dy[k] + j;
            
            if (row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size() && grid[row][col] == 1) {
                dfs(row, col, start, end, grid, temp);
            }
        }
    }

    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        // easy with dfs
        // int cnt = 0;
        int n = grid.size();
        int m = grid[0].size();
        set<vector<pair<int, int>>> st;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    vector<pair<int, int>> temp;
                    dfs(i, j, i, j, grid, temp);
                    //cnt++;
                    st.insert(temp);
                }
            }
        }

        return st.size();
    }
};
