718. Maximum Length of Repeated Subarray
Link: https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/


class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int maxiLength = 0;
        int n = nums1.size();
        int m = nums2.size();

       
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(nums1[i-1]==nums2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    maxiLength = max(maxiLength,dp[i][j]);
                } 
                else dp[i][j] = 0;
               
            }
        }
        return maxiLength;
        //TC = O(n*m);
        //SC = O(n*m);



        // vector<int> curr(n+1,0), prev(n+1,0);
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=n;j++){
        //         if(nums1[i-1]==nums2[j-1]){
        //             curr[j] = 1 + prev[j-1];
        //             maxiLength = max(maxiLength,curr[j]);
        //         } 
        //         else curr[j] = 0;
               
        //     }
        //     prev = curr;
        // }
        // return maxiLength;

    }
};