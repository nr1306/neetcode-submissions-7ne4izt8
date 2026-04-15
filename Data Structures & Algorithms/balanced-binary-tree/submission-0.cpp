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
        if(!root || !res) return 0;

        int leftH = dfs(root->left,res);
        // cout << leftH << " "  << endl;
        int rightH = dfs(root->right,res);

        if(abs(rightH - leftH) > 1){
            res = false;
        } 
        // cout << 1 + max(leftH, rightH) << endl;
        return 1 + max(leftH, rightH);
    }

    bool isBalanced(TreeNode* root) {
        bool res = true;
        dfs(root, res);
        return res;
    }
};
