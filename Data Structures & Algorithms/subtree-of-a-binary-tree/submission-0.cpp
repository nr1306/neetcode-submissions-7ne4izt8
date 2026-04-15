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
    bool dfs(TreeNode* root, TreeNode* subroot){
        if(!root) return false;
        
        if(root->val == subroot->val && checksubTree(root, subroot)){
            return true;
        }

        if(dfs(root->left,subroot) || dfs(root->right,subroot))
            return true;

    }

    bool checksubTree(TreeNode* root, TreeNode* subroot){
        if((!root && subroot) || (root && !subroot)) return false;
        if(!subroot && !root)
            return true;
        
        if(root->val != subroot->val) return false;

        if(checksubTree(root->left,subroot->left)  && checksubTree(root->right,subroot->right) )
            return true;
    }   

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return dfs(root, subRoot);
    }
};
