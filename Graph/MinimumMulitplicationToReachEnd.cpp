#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        vector<int> visited(100000, 0);
        queue<pair<int, int>> q;
        q.push({0, start});
        visited[start] = 1;

        while (!q.empty()) {
            pair<int, int> curr = q.front(); q.pop();
            int steps = curr.first;
            int node = curr.second;

            if (node == end) return steps;

            for (int i = 0; i < arr.size(); i++) {
                int next = (node * arr[i]) % 100000;
                if (!visited[next]) {
                    visited[next] = 1;
                    q.push({steps + 1, next});
                }
            }
        }

        return -1;
    }
};
