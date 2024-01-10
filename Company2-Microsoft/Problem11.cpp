2970. Count the Number of Incremovable Subarrays I
Link: https://leetcode.com/problems/count-the-number-of-incremovable-subarrays-i/description/

class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {

        int ans = 0;
        
        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                int lastElement = -1;
                bool flag = true;

                for(int k=0;k<nums.size();k++){
                    if(k >= i && k <= j) continue;
                    if(lastElement >= nums[k]){
                        flag = false;
                        break;
                    }
                    lastElement = nums[k];
                }

                if(flag) ans++;
            }
        }

        return ans;
    }
};

//TC = O(N^3)
//SC = O(1)