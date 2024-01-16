692. Top K Frequent Words
Link: https://leetcode.com/problems/top-k-frequent-words/description/


class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;

        for(auto it: words){
            mp[it]++;
        }

        vector<pair<string,int>> v;
        for(auto it: mp){
            v.push_back(it);
        }

        auto cmp = [&](auto &a , auto &b){
            if(a.second==b.second){
                return a.first < b.first;
            }
            return a.second> b.second;
        };
        sort(v.begin() ,  v.end() , cmp);

        vector<string> ans;
        for(auto it: v){
            ans.push_back(it.first);
            k--;
            if(k==0) break;
        }

        return ans;
    }
};
//TC = O(nlogn);
//SC = O(n);