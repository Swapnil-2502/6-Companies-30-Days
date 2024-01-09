299. Bulls and Cows
Link: https://leetcode.com/problems/bulls-and-cows/description/

class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.length();
        int bulls = 0;
        int cows = 0;

        for(int i=0;i<n;i++){
            if(secret[i] == guess[i]){
                bulls++;
                secret[i] = -1;
                guess[i] = -1;
            } 
        }

        for(int i=0;i<n;i++){
            if(secret.find(guess[i])!=-1 && guess[i]!=-1 ){
                cows++;
                secret[secret.find(guess[i])]=-1;
            }
        }
        string ans = "";
        ans = to_string(bulls)+"A"+to_string(cows)+"B";

        return ans;

    }

    //TC = O(N);
    //SC = O(N);
};