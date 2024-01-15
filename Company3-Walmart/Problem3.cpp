2385. Amount of Time for Binary Tree to Be Infected
Link: https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/?envType=daily-question&envId=2024-01-10

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int,vector<int>> mp;
    int amountOfTime(TreeNode* root, int start) {
        constructGraph(root);
        int minutes = 0;

        queue<int> q;
        q.push(start);

        unordered_set<int> vis;

        while(!q.empty()){
            minutes++;
            int size = q.size();
            while(size--){
                int node = q.front();
                q.pop();

                vis.insert(node);

                for(auto adjNode: mp[node]){
                    if(!vis.count(adjNode)){
                        q.push(adjNode);
                    }
                }
            }

        }
        return minutes-1;

    }

    void constructGraph(TreeNode* root){
        if(!root) return;

        if(root->left){
            mp[root->val].push_back(root->left->val);
            mp[root->left->val].push_back(root->val);
        }
        if(root->right){
            mp[root->val].push_back(root->right->val);
            mp[root->right->val].push_back(root->val);
        }
        constructGraph(root->left);
        constructGraph(root->right);
    }
};

//TC = O(N);
//SC = O(N);
//N is the number of nodes;