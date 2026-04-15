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
    void dfs(TreeNode* root, int localMaxi, int val, int& count){
        if(!root){
            return;
        }
        int node = root->val;
        if((node >= localMaxi && node >= val)) count++; // good node
        localMaxi = max(localMaxi, node); // updating the localMaxi

        dfs(root->left, localMaxi, val, count);
        dfs(root->right, localMaxi, val, count);
    }

    int goodNodes(TreeNode* root) {
        if(!root) return 0;

        int localMaxi = root->val;
        int val = root->val;
        int count = 1;
        dfs(root->left,localMaxi,val,count);
        dfs(root->right,localMaxi,val,count);
        return count;
    }
};
