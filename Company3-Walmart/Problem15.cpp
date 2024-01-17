2707. Extra Characters in a String
Link: https://leetcode.com/problems/extra-characters-in-a-string/description/

class Solution {
public:
    int solve(int index, string &s, unordered_set<string> &st, vector<int> &dp){
        if(index == s.size()) return 0;

        if(dp[index] != -1) return dp[index];

        string str = "";
        int mn = s.size();
        for(int i=index;i<s.size();i++){
            str += s[i];
            int v = str.size();

            if(st.count(str)) v = 0;

            mn = min(mn, v + solve(i+1,s,st,dp));
        } 

        return dp[index] = mn;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        vector<int> dp(51,-1);

        unordered_set<string> st;

        for(string& it: dictionary) st.insert(it);

        return solve(0,s,st,dp);
    }
};

// class Solution {
// public:
//     int dp[51];
//     int solve(string& s, unordered_set<string>&st, int i)
//     {
//         if (i == s.size()) return 0;

//         if (dp[i] != -1) return dp[i];
        
//         string str = "";
//         int mn = s.size();
//         for (int j = i; j < s.size(); j++)
//         {
//             str+=s[j];
//             int v=str.size();
//            if(st.count(str)){
//              v=0;
//            }
//             mn = min(mn, v+solve(s,st,j+1));
//         }
//         return dp[i] = mn;
//     }
//     int minExtraChar(string s, vector<string>& d) 
//     {
//         memset(dp,-1,sizeof(dp));
//         unordered_set<string>st;
//         for (string& x : d){
//         st.insert(x);
//         }
//         return solve(s, st, 0);
//     }
// };