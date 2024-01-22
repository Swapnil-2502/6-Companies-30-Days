455. Assign Cookies
Link: https://leetcode.com/problems/assign-cookies/description/


class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int count = 0;
        int n = 0;
        int m = 0;

        while(n<s.size() && m<g.size()){
            if(s[n] >= g[m]){
                n++;
                m++;
                count++;
            }
            else{
                n++;
            }
        }

        return count;
    }
};

//TC = O(max( nlogn, mlogm)) n== size of s && m== size of g;
//Sc = O(1);