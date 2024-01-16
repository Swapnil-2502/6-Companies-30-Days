451. Sort Characters By Frequency
Link: https://leetcode.com/problems/sort-characters-by-frequency/description/


class Solution {
public:
    string frequencySort(string s) {
        string ans = "";

        priority_queue<pair<int,char>> pq;

        unordered_map<char,int> mp;

        for(int i=0;i<s.length();i++){
           mp[s[i]]++;
        }

        for(auto it:mp){
            pq.push({it.second,it.first});
        }

        while(!pq.empty()){
            int freq = pq.top().first;
            int character = pq.top().second;
            pq.pop();

            while(freq--){
                ans += character;
            }
        }

        return ans;
    }
};

//TC = O(1)unordered_map + O(nlogn)priority_queue + O(n);
//SC = O(n) + O(n);