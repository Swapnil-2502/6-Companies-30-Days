1385. Find the Distance Value Between Two Arrays
link: https://leetcode.com/problems/find-the-distance-value-between-two-arrays/


class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr1.begin(),arr1.end());
        sort(arr2.begin(),arr2.end());

        int ans = 0;
        for(auto var: arr1){
            int start = 0;
            int end = arr2.size() - 1;
            int mid = (start + end)/2;
            ans++;
            while(start <= end){

                mid = (start + end)/2;
                if((arr2[mid] <= (d+var))  and (arr2[mid] >= (var-d)))
                {
                    ans--;
                    break;
                }
                else if(arr2[mid] > (d+var)) end = mid-1;
                else start = mid+1;
            }
        }

        return ans;
    }
};
//TC = O(nlogn);
//SC = O(1);