#include<bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/maximal-rectangle/description/
//================================IMPORTANT================================================
class Solution {
public:
    int findAreaMax(vector<int>& heights) {
        int n = heights.size();
        vector<int> nextSmaller(n, n), prevSmaller(n, -1);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if (!st.empty()) prevSmaller[i] = st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if (!st.empty()) nextSmaller[i] = st.top();
            st.push(i);
        }

        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int width = nextSmaller[i] - prevSmaller[i] - 1;
            maxArea = max(maxArea, heights[i] * width);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if (n == 0) return 0;
        int m = matrix[0].size();
        vector<int> heights(m, 0);
        int res = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') heights[j]++;
                else heights[j] = 0;
            }
            res = max(res, findAreaMax(heights));
        }

        return res;
    }
};
