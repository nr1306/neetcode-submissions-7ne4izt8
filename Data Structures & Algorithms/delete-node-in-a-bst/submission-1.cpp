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
// We have 3 scenerios - Node we are deleting can be:
// leaf node , node with one children , node with 2 children
// If its leaf node we can delete it directly - in else it will return NULL
// If the node has 2 children - will find inorder successor of that node and replace it with that - Why inorder successor because when we right inorder of the given tree inorder successor means the element comes after that node which we are deleting - to maintain BST tree
// Inorder successor - smallest element in right subtree


    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;

        if(key > root->val){
            root->right = deleteNode(root->right, key);
        }
        else if(key < root->val){
            root->left = deleteNode(root->left, key);
        }
        else{
    // If it has only one children - we are just gonna take its children up and connect to its parent node
            if(!root->right) return root->left;
            if(!root->left) return root->right;

            TreeNode* curr = root->right;
            while(curr->left){
                curr = curr->left;
            }
            curr->left = root->left;
            TreeNode* res = root->right;
            delete root;
            return res;
        }

        return root;
    }
};