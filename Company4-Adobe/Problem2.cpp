2745. Construct the Longest New String
Link: https://leetcode.com/problems/construct-the-longest-new-string/description/

class Solution {
public:
    int longestString(int x, int y, int z) {
        
        //Three cases 
        //Case 1: x==y then z can be used (x,y) +1 times

        //Case2: x>y then z can be used max(x,y) +1 times

        //Case3: x<y then z can be used max(x,y) +1 times

        int ans = 0;

        if(x==y){
            ans += x*2 + y*2 + z*2;
        }
        else if(x > y){
            ans += (y+1)*2 + y*2 + z*2;
        }
        else{ //x < y
            ans += x*2 + (x+1)*2 + z*2;
        }

        return ans;
    }
};
//Tc = O(3);
//SC = O(1);