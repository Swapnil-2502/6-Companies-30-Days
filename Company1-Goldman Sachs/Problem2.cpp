// 2933. High-Access Employees
// https://leetcode.com/problems/high-access-employees/description/


//Gist: first store the inputs in map as a -> vector of times
// Now sort the vector of times , then check if there exists index 2,
// Then if time of index2 - time of index0 < 100 if yess append to ans vector

class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        unordered_map<string,vector<int>> mp;

        for(auto &it: access_times){
            int time = stoi(it[1]);
            mp[it[0]].push_back(time);
        }

        //Sort the array part of the map
        for(auto &it:mp){
            sort(it.second.begin(),it.second.end());
        }

        vector<string> ans;

        for(auto &it: mp){
            vector<int> &time = it.second;

            for(int i=2;i<time.size();i++){
                if(time[i]-time[i-2] < 100){
                    ans.push_back(it.first);
                    break;
                }
            }
        }

        return ans;
    }

    // TC = O(nlogn) sorting + O(n) iterate 2D array 
    // SC = O(n) sorting ans + O(n) map space
};