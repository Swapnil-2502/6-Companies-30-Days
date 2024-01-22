2943. Maximize Area of Square Hole in Grid
Link: https://leetcode.com/problems/maximize-area-of-square-hole-in-grid/description/

//Intuition

// In this we just have to check how many consecutive bars we can remove. By removing k bars it will create (k+1) unit free space.

class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());

        int horiCount = 1;
        int count1 = 1;
        for(int i=0;i<hBars.size()-1;i++){
            if(hBars[i+1] == hBars[i]+1){
                count1++;
            }
            else{
                count1 = 1;
            }
            horiCount = max(horiCount,count1);
        }

        int vertCount = 1;
        int count2 = 1;
        for(int i=0;i<vBars.size()-1;i++){
            if(vBars[i+1] == vBars[i]+1){
                count2++;
            }
            else{
                count2 = 1;
            }
            vertCount = max(vertCount,count2);
        }
       

        int ans = min(horiCount,vertCount) + 1;
        return ans*ans;
    }
};

//TC = O(nlogn);
//SC = O(1);
