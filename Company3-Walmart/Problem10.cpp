331. Verify Preorder Serialization of a Binary Tree
Link: https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/description/


class Solution {
public:
    bool isValidSerialization(string preorder) {
        int n = preorder.size();
        int vacancy = 1;
        int i=0;
        while(i<n){

            vacancy--;

            if(vacancy<0) return false;

            if(preorder[i] != '#') vacancy+=2;

            while(preorder[i] != ',' && i<n) i++;

            i++;
        }

        return vacancy == 0;
    }
};

//TC = O(N);
//SC = O(1);