// 2513. Minimize the Maximum of Two Arrays
// Link: https://leetcode.com/problems/minimize-the-maximum-of-two-arrays/description/

#define ll long long

class Solution {

    ll getGCD(int a, int b){
        if(b==0) return a;

        return getGCD(b,a%b);
    }

public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        
        ll ans = INT_MAX;
        ll low = 1, high = INT_MAX;

        ll lcm = (ll)((ll)divisor1 * (ll)divisor2) / (ll)getGCD(divisor1,divisor2);

        while(low<=high){
            int mid = (low + high) / 2;

            int notd1 = mid - mid/divisor1; // Total numbers not divisible by divisor1
            int notd2 = mid - mid/divisor2; // Total numbers not divisible by divisor2

            int notboth = mid - mid/lcm; // Total numbers not divisible by both divisor1 & divisor2

            if(notd1>=uniqueCnt1 && notd2>=uniqueCnt2 && notboth>=(uniqueCnt1+uniqueCnt2)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        return ans;
    }
};