// 17. Letter Combinations of a Phone Number
// Link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/


class Solution {
public:
    void f(string digits,int pos, string &res, vector<string> &ans, vector<string> &letters){

        if(pos == digits.size()){
            ans.push_back(res);
            return;
        }

        for(auto it: letters[digits[pos] - '0']){
            res.push_back(it);
            f(digits,pos+1,res,ans,letters);
            res.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        vector<string> ans;

        if(digits.empty()) return ans;

        vector<string> letters({"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"});

        string res = "";

        f(digits,0,res,ans,letters);

        return ans;

    }
};