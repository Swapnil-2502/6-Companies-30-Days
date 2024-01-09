462. Minimum Moves to Equal Array Elements II
Link: https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/description/

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int result = 0;

        int medianIndex = nums.size()/2;
        for(int i=0;i<nums.size();i++){
            result += abs(nums[i] - nums[medianIndex]);
        }

        return result;
    }
    //TC = O(nLogn);
    //Sc = O(1);
};