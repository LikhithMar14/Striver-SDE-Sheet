//Recursion and Backtracking
//Binary Exponentiation

class Solution {
    public:
        long long mod = 1e9 + 7;
        //important
        long long mulMod(long long a, long long b) {
            return (a % mod * b % mod) % mod;
        }
    
        long long helper(long long n, long long k) {
            if (n == 0) return 1;
    
            long long half = helper(n >> 1, k);
    
            if (n & 1) {
                return mulMod(k, mulMod(half, half));
            }
            return mulMod(half, half);
        }
    
        int countGoodNumbers(long long n) {
            long long odd = (n + 1) >> 1;
            long long even = n >> 1;
    
            return mulMod(helper(odd, 5), helper(even, 4));
        }
    };
    
    