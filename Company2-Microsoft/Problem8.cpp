1248. Count Number of Nice Subarrays
Link: https://leetcode.com/problems/count-number-of-nice-subarrays/description/

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        int n = nums.size();
        //Replacing odd elements with 1 and even with 0;
        vector<int> nums2(n,0);
        for(int i=0;i<n;i++){
            if(nums[i]%2 == 1) nums2[i] = 1;            
        }

        unordered_map<int,int> mp; //{PrefixSum,Count};
        int ans = 0;
        int PrefixSum = 0;

        mp[0] = 1;

        for(int i=0;i<n;i++){
            PrefixSum += nums2[i];

            if(mp.find(PrefixSum-k) != mp.end()) ans += mp[PrefixSum-k];

            if(mp.find(PrefixSum) != mp.end()) mp[PrefixSum]++;
            else mp[PrefixSum] = 1;
        }

        return ans;

    }
}