#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/asteroid-collision/description/
//================================IMPORTANT================================================
//We are using a stack to store the asteroids
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int>st;
        vector<int>res;
        for(int i=0; i < n; i++){
            int curr = asteroids[i];
            while(!st.empty() && st.top() > 0 && curr < 0){
                int top = st.top();
                if(top == abs(curr)){
                    st.pop();
                    curr = 0;
                    break;
                }
                if(top > abs(curr)){
                    curr= 0;
                    break;
                }
                if(top < abs(curr)){
                    st.pop();
                    continue;
                }

            }
            if(curr != 0)st.push(curr);
        }

        while(!st.empty()){
            res.push_back((int)st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};