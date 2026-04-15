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
    int dfs(TreeNode* root, bool& res){
        if(!root) return 0;
        if(!res) return 0;
        
        int leftHeight = dfs(root->left, res);
        int rightHeight = dfs(root->right, res);

        if(abs(rightHeight-leftHeight) > 1){
            res = false;
        }
        return max(leftHeight,rightHeight) + 1;
    }

    bool isBalanced(TreeNode* root) {
        bool res = true;
        dfs(root, res);
        return res;
    }
};
