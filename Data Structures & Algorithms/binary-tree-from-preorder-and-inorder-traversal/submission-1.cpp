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

    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, 
    map<int,int>& inMap, int prestart, int preend, int instart, int inend){
        if(instart > inend || prestart > preend){
            return nullptr;
        }

        int pos = inMap[preorder[prestart]];
        int numsleft = pos - instart;

        TreeNode* root = new TreeNode(preorder[prestart]);

        root->left = dfs(preorder, inorder, inMap,prestart+1, 
        prestart+numsleft, instart, pos);

        root->right = dfs(preorder,inorder,inMap,prestart+numsleft+1, 
        preend, pos+1, inend);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int instart = 0, prestart = 0;
        int inend = inorder.size()-1, preend = preorder.size()-1;

        map<int,int> inMap;
        for(int i=0; i<=inend; i++){
            inMap[inorder[i]] = i;
        }

        return dfs(preorder,inorder,inMap, prestart, preend, 
        instart, inend);
    }
};
