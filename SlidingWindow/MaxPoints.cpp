#include<bits/stdc++.h>
using namespace std;

//Arbitary problem

//dp wagera sochne ka mann krega but sochne ka nahi
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int initialSum = 0;
        for(int i=0; i < k; i++)initialSum += cardPoints[i];
        int tmpSum = 0;
        int i = k;
        int j = n-1;
        int ans = initialSum;

        while(i){
            tmpSum += cardPoints[j];
            initialSum -= cardPoints[i-1];
            ans = max(ans,tmpSum+initialSum);
            j--;
            i--;
        }
        return ans;
    }
};