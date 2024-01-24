2958. Length of Longest Subarray With at Most K Frequency
Link: https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/description/


class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int start = 0, end = 0;
        int ans = 0;
        int n = nums.size();

        unordered_map<int,int> mp;

        while(end<n){
            if(mp[nums[end]] < k){
                mp[nums[end]]++;
                end++;
            }
            else{
                mp[nums[start]]--;
                start++;
            }
            ans = max(ans,end-start);
        }
        return ans;
    }
};
//TC = O(N);
//SC = O(N);