#include<bits/stdc++.h>
using namespace std;

#define ll long long 


bool check(vector<ll>&arr, ll mid, ll k){
    ll sum = 0;
    ll cnt = 1;

    for(auto &it: arr){
        if(sum + it <= mid){
            sum += it;
        }else{
            cnt++;
            sum=it;
            if(it > mid)return false;
        }
    }
    return cnt <= k;
}


int main(){
    ll n,k;
    cin>>n>>k;
    
    vector<ll>arr(n);
    for(int i=0; i < n; i++)cin>>arr[i];
    
    ll h = accumulate(arr.begin(), arr.end(),0LL);

    ll l = *max_element(arr.begin(), arr.end());

    ll ans = h;
    while(l <= h){
            ll mid = l+(h-l)/2;

        if(check(arr,mid,k)){
            ans = mid;
            h=mid-1;
        }else{
            l=mid+1;    
        }
    }

    cout<<ans<<endl;

}