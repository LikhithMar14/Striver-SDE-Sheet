#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
  void dfs(int r, int c , vector<vector<char>>& arr, int n , int m){
      arr[r][c] = 'Y'; 
      vector<int> dx{0, 0, 1, -1};
      vector<int> dy{1, -1, 0, 0};
      
      for(int i = 0; i < 4; i++){
          int nr = r + dx[i];
          int nc = c + dy[i];
          if(nr >= 0 && nr < n && nc >= 0 && nc < m && arr[nr][nc] == 'O'){
              dfs(nr, nc, arr, n, m);
          }
      }
  }

  vector<vector<char>> fill(vector<vector<char>>& arr) {
      int n = arr.size();
      int m = arr[0].size();
      //any thing which is directly conneceted outermost zeros cannot be enclosed by 'X' S
      
      for(int j = 0; j < m; j++){
          if(arr[0][j] == 'O') dfs(0, j, arr, n, m);
          if(arr[n-1][j] == 'O') dfs(n-1, j, arr, n, m);
      }

      for(int i = 0; i < n; i++){
          if(arr[i][0] == 'O') dfs(i, 0, arr, n, m);
          if(arr[i][m-1] == 'O') dfs(i, m-1, arr, n, m);
      }

      for(int i = 0; i < n; i++){
          for(int j = 0; j < m; j++){
              if(arr[i][j] == 'Y') arr[i][j] = 'O';
              else if(arr[i][j] == 'O') arr[i][j] = 'X';
          }
      }

      return arr;
  }
};
