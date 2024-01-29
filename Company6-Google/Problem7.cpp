2233. Maximum Product After K Increments
Link: https://leetcode.com/problems/maximum-product-after-k-increments/description/


class Solution {
public:
    int mod = 1e9 + 7;

    int maximumProduct(vector<int>& nums, int k) {
        
        priority_queue<int,vector<int>, greater<int>> pq;

        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }

        while(k>0){
            int element = pq.top();
            pq.pop();
            element++;
            k--;
            pq.push(element);
        }

        long long ans = 1;

        while(!pq.empty()){
            ans *= pq.top();
            ans = ans%mod;
            pq.pop();
        }
        return ans;
    }
};

//TC = O(N + logN);
//SC = O(N);