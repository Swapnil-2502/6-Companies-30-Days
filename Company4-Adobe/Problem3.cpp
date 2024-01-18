820. Short Encoding of Words
LinK: https://leetcode.com/problems/short-encoding-of-words/description/


class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        set<string> s(words.begin(),words.end());

        for(auto &word: words){
            for(int i=1;i<word.size();i++){
                s.erase(word.substr(i));
            }
        }

        int ans = 0;

        for(auto word: s){
            ans += word.size()+1;
        }
        return ans;

        
    }
};

// TC : O(2N + N*S) 2N- for storing word in set s and counting valid encoding string, N*S- for erasing all suffixes of word.

// SC: O(N) - for set
// Here,
// N-Size of vector words
// S-Size of string word in words