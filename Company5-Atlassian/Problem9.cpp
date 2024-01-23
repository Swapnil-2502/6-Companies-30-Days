1969. Minimum Non-Zero Product of the Array Elements
LinK:https://leetcode.com/problems/minimum-non-zero-product-of-the-array-elements/description/


class Solution {
public:
    const int MOD = 1000000007;

    long long power(long long x, long long y){
        if(y==0) return 1;

        long long ans = power(x,y/2);

        if(y%2==0) return (ans*ans)%MOD;
        else return ((ans*ans)%MOD * (x%MOD)) % MOD;
    }

    int minNonZeroProduct(int p) {
        if(p==1) return 1;

        long long maxi = pow(2,p);
        long long maxiNum = maxi - 1;
        long long result = power(maxiNum-1, (maxiNum-1)/2);

        return (result * (maxiNum % MOD))%MOD;
    }
};