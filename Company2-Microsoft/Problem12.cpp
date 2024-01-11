2002. Maximum Product of the Length of Two Palindromic Subsequences
Link: https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/description/


class Solution {
public:

    bool palin(string &s){
        int n = s.length();
        for(int i=0;i<n/2;i++){
            if(s[i] != s[n-i-1]) return false;
        }
        return true;
    }

    void f(int index, string s,string &s1,string &s2, int &ans){
        if(index >= s.length()){
            if(palin(s1) && palin(s2)){
                int temp = s1.length() * s2.length();
                ans = max(ans,temp);
            }

            return;
        }

        //Not Pick;
        f(index+1,s,s1,s2,ans);

        //Pick
        //Two Cases: 1.Pick in s1 & 2.Pick in s2
        s1.push_back(s[index]);
        f(index+1,s,s1,s2,ans);
        s1.pop_back();

        s2.push_back(s[index]);
        f(index+1,s,s1,s2,ans);
        s2.pop_back();

    }
    
    int maxProduct(string s) {
        int ans = 0;
        string s1 = "", s2 = "";

        f(0,s,s1,s2,ans);

        return ans;
    }
};