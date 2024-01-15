532. K-diff Pairs in an Array
Link: https://leetcode.com/problems/k-diff-pairs-in-an-array/description/


class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==1) return 0;

        sort(nums.begin(),nums.end());

        int ptr1=0;
        int ptr2=1;

        int ans = 0;

        while(ptr2<n){
            int diff = nums[ptr2] - nums[ptr1];

            if(diff == k){
                ans++;

                int c1 = nums[ptr1], c2 = nums[ptr2];
                while(ptr1<n && c1 == nums[ptr1]){
                    ptr1++;
                }
                while(ptr2 < n && c2 == nums[ptr2]){
                    ptr2++;
                }
            }
            else if(diff > k){
                ptr1++;
            }
            else ptr2++;

            //edge case when k==0
            if(ptr1==ptr2) ptr2++;
        }

        return ans;
        
    }
};

//TC = O(NlogN);
//SC = O(1);