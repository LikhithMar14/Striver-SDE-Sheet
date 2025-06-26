#include<bits/stdc++.h>
using namespace std;

//simple problem using prefix sum + binary search
bool check(int mid, vector<int>&boards, vector<int>&pre, int k, int n){
    int cnt = 1;
    int last = 1;

    for(int i=1; i <= n; i++){
        if(pre[i]-pre[last-1] > mid){
            cnt++;
            last = i;

            if(cnt > k)return false;
        }
    }
    return true;
}
int findLargestMinDistance(vector<int> &boards, int k)
{   
    int n = boards.size();
    int l = *max_element(boards.begin(),boards.end());
    int h = accumulate(boards.begin(),boards.end(),0);

    vector<int>pre(n+1,0);
    for(int i=1; i <= n; i++)pre[i] = pre[i-1]+boards[i-1];



    int ans = -1;

    while(l <= h) {
        int mid = (l + ((h-l) >> 1));
        if(check(mid, boards,pre, k, n)){
            ans = mid;
            h = mid-1;
        }else l = mid+1;
    }
    return ans;
}