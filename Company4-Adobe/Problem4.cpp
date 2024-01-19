1425. Constrained Subsequence Sum
Link: https://leetcode.com/problems/constrained-subsequence-sum/description/


class Solution {
 #define pii pair<int, int>
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n);
        priority_queue<pii> pq;
        int ret = INT_MIN;
        dp[0] = nums[0];
        ret = max(ret, dp[0]);
        pq.push({dp[0], 0});
        for(int i = 1; i < nums.size(); i++) {
            pii t = pq.top();
            while(t.second < i - k) {
                pq.pop();
                t = pq.top();
            }
            dp[i] = max(0, t.first) + nums[i];
            ret = max(ret, dp[i]);
            pq.push({dp[i], i});
        }
        return ret;
    }
};