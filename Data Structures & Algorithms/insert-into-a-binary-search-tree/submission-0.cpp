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
    void search(TreeNode* root, int val){
        if(val < root->val){
            if(root->left == NULL){
                TreeNode* node = new TreeNode(val);
                root->left = node;
                return;
            }
            search(root->left, val); // else
        }
        else{
            if(root->right == NULL){
                TreeNode* node = new TreeNode(val);
                root->right = node;
                return;
            }
            search(root->right, val); // else
        }
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            TreeNode* node = new TreeNode(val);
            return node;
        }
        search(root, val);
        return root;
    }
};