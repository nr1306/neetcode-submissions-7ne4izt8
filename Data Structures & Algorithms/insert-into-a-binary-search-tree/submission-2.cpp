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
    void traverse(TreeNode* root, int val){
        TreeNode* curr = root;
        
        if(val < root->val){
            if(!root->left){
                TreeNode* node = new TreeNode(val);
                root->left = node;
                root = curr;
                return;
            }
            traverse(root->left, val);
        }
        else{
            if(!root->right){
                TreeNode* node = new TreeNode(val);
                root->right = node;
                root = curr;
                return;
            }
            traverse(root->right, val);
        }
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            root = new TreeNode(val);
            return root;
        }
        traverse(root, val);
        return root;
    }
};