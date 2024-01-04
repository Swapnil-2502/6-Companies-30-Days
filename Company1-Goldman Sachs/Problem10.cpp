// 2261. K Divisible Elements Subarrays
// Link: https://leetcode.com/problems/k-divisible-elements-subarrays/description/

class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        
        int n = nums.size();

        set<vector<int>> s;

        for(int i=0;i<n;i++){

            vector<int> ds;
            int countK = 0;

            for(int j=i;j<n;j++){

                ds.push_back(nums[j]);

                if(nums[j] % p == 0) countK++;

                if(countK > k) break;

                s.insert(ds);
            }
        }

        return s.size();
    }
};