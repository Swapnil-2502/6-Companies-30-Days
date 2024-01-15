class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int>ans;
        vector<int> dp(n,1),hash(n);
        int lastIndex = 0;
        int maxi = 1;

        for(int curr=0;curr<nums.size();curr++){
           hash[curr] = curr;
           for(int prev=0;prev<curr;prev++){
               if(nums[curr] % nums[prev] == 0 && 1+dp[prev] > dp[curr]){
                   dp[curr] = 1+dp[prev];
                   hash[curr] = prev;
               }
           }
           if(maxi < dp[curr]){
               maxi = dp[curr];
               lastIndex = curr;
           }
        }

        ans.push_back(nums[lastIndex]);
        while(hash[lastIndex] != lastIndex){
            lastIndex = hash[lastIndex];
            ans.push_back(nums[lastIndex]);
        }


        return ans;
    }
};

//TC = O(nlogn);
//SC = O(n*2);