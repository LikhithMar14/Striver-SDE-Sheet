#include<bits/stdc++.h>
using namespace std;
#define ll long long 



bool check(vector<ll>&arr, ll mid, ll k){
    ll sum = 0;
    for(auto &it: arr){
        sum += mid/it;
    }

    return sum >= k;
}

int main() {
    ll n,k;
    cin>>n>>k;
    vector<ll>arr(n);
    for(int i=0; i < n; i++)cin>>arr[i];
    ll h = *min_element(arr.begin(), arr.end())*k;
    //ll h=1e18;
    ll l = 1;

    ll ans = -1;

    while(l <= h){
        ll mid = l+(h-l)/2;

        if(check(arr, mid, k)){
            h = mid-1;
            ans = mid;
        }else{
            l = mid+1;
        }
    }

    cout<<ans<<endl;
}