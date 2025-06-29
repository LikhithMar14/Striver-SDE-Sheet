#include<bits/stdc++.h>
using namespace std;

    //with simple recursion
class Solution {
public:
    const int MOD = 1000000007;
    long long  solve(int n){
        if(n < 0)return 1;
        if(n%2)return 4*(solve(n-1)%MOD);
        return 5*(solve(n-1)%MOD);
    }
    int countGoodNumbers(long long n) {
        return static_cast<int>(solve(n-1) % MOD);
    }
};


//with binary exponentiation
class Solution {
public:
    const int MOD = 1000000007;

    long long binexp(long long base, long long exp) {
        if (exp == 0) return 1;
        long long half = binexp(base, exp / 2);
        long long res = (half * half) % MOD;
        if (exp % 2 == 1) res = (res * base) % MOD;
        return res;
    }

    int countGoodNumbers(long long n) {
        long long even_count = (n + 1) / 2;
        long long odd_count = n / 2;

        long long res = (binexp(5, even_count) * binexp(4, odd_count)) % MOD;
        return static_cast<int>(res);
    }
};
