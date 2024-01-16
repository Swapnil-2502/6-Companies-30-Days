1208. Get Equal Substrings Within Budget
Link: https://leetcode.com/problems/get-equal-substrings-within-budget/description/


class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int curr_cost = 0;
        int maxi = 0;
        int left = 0;

        for(int right = 0; right<n; right++){
            curr_cost += abs(t[right] -s[right]);

            while(left<=right && curr_cost > maxCost){
                curr_cost -= abs(t[left] -s[left]);
                left++;
            }
            maxi = max(maxi,(right-left+1));
        }

        return maxi;
    }
};

//TC == O(N);
//SC == O(1);