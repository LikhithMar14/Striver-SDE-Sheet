//Random Problems

#include<bits/stdc++.h>
using namespace std;

class Solution {


public:

    int findContentChildren(vector<int>& g, vector<int>& s) {
        int i=0;
        int j = 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int ans = 0;

        while(i < g.size() && j < s.size()){
            if(g[i] <= s[j]){
                i++;
                ans++;
            }
            j++;
        }
        return ans;
        
    }
};




// User function Template for C++

class Solution {
  public:
    vector<int> minPartition(int N) {
        // code here
        //find lowerbound
        vector<int>a{1,2,5,10,20,50,100,200,500,2000};
        vector<int>res;
        int i = a.size()-1;
        
        while(N >= 0 && i >= 0){
            while(a[i] > N && i > 0)i--;
            N -= a[i];
            res.push_back(a[i]);
        }
        res.pop_back();
        return res;
    }
};