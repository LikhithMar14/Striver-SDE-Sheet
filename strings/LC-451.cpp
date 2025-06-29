#include<bits/stdc++.h>
using namespace std;

//somewhat more rash approach can easily done using priority queue


class Solution {
public:

    string frequencySort(string s) {
        vector<int> arr(128, 0);

        for (char it : s) {
            arr[it]++;
        }
        //learing lambda functions
        sort(s.begin(),s.end(),[&](char a, char b){
            if(arr[a] == arr[b])return a < b;
            return arr[a] > arr[b];
        });
        return s;

    }
};