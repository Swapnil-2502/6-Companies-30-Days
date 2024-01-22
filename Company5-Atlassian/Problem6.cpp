3006. Find Beautiful Indices in the Given Array I
Link: https://leetcode.com/problems/find-beautiful-indices-in-the-given-array-i/description/


class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        int sSize = s.size();
        int aSize = a.size();
        int bSize = b.size();

        vector<int> ans, index_a,index_b;

        for(int i=0;i<= sSize - aSize; i++){
            if(s.substr(i,aSize) == a) index_a.push_back(i);
        }

        for(int i=0;i<= sSize - bSize; i++){
            if(s.substr(i,bSize) == b) index_b.push_back(i);
        }

        for(int i=0;i<index_a.size();i++){
            for(int j=0;j<index_b.size();j++){
                if( abs(index_a[i] - index_b[j]) <= k ){
                    ans.push_back(index_a[i]);
                    break;
                } 
            }
        }

        return ans;
    }
};
//TC = O(sSize);
//SC = O(3*sSize);