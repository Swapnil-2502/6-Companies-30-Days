139. Word Break
Link: https://leetcode.com/problems/word-break/description/


// class Solution {
// public:
//     bool wordBreak(string s, vector<string>& wordDict) {
        
//     }
// };

class Solution {
public:
    set<string>dict;
    map<string,bool>dp;
    bool f(string s){
        if(s.length()==0) return true;
         
        if(dp.find(s)!=dp.end())     return dp[s];
     
       for(int i=0;i<s.length();i++){
           string r = s.substr(0,i+1);
           if(dict.count(r)){
               if(f(s.substr(i+1))){
                   return dp[s]=true;
               }
            //    return f(index,prev,n,s.substr(i+1,s.length()),temp);
           }
       }

       return dp[s]=false;    

    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        for(auto it : wordDict){
            dict.insert(it);
        }
        // string temp="";
        return f(s);
    }
};

//TC = O(N*M); N==length of string
//SC = O(M);    M=length of dict


