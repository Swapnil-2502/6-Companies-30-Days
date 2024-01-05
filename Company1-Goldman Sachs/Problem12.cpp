1373. Maximum Sum BST in Binary Tree
Link:https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/description/

class Solution {
public:
    // int ANS = 0;
    vector<int> solve(TreeNode* root){
        if(!root) return {1,0,INT_MAX,INT_MIN};
        if(!root->left && !root->right) return {1,root->val,root->val,root->val};

        vector<int> l = solve(root->left);
        vector<int> r = solve(root->right);

        if(l[0] && r[0]){
            if(root->val > l[3] && root->val < r[2]){
                int x = l[2];
                int y = r[3];
                if(x == INT_MAX) x = root->val;
                if(y == INT_MIN) y = root->val;
                ANS = max(ANS,l[1]+r[1]+root->val);
                return {1,l[1]+r[1]+root->val,x,y};
            }
        }

        return {0,max(l[1],r[1]),0,0};
    } 

    int maxSumBST(TreeNode* root) {
        vector<int> ans = solve(root);
        if(ans[1] < 0) return 0;
        return ans[1];
        // if(ANS<0) return 0;
        // return ANS;
    }
};