// 216. Combination Sum III
// Link: https://leetcode.com/problems/combination-sum-iii/description/

class Solution {
public:

    void f(int index, int target, vector<int> &v,vector<vector<int>> &ans, vector<int> &ds,int k){
        if(target==0 && k==0) ans.push_back(ds);

        for(int i=index;i<v.size();i++){
            if(v[i] > target) break;

            ds.push_back(v[i]);
            f(i+1,target-v[i],v,ans,ds,k-1);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;

        vector<int> v;
        for(int i=1;i<=9;i++){
            v.push_back(i);
        }

        f(0,n,v,ans,ds,k);

        return ans;
    }
};