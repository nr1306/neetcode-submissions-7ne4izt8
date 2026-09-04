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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd, map<int,int>& inMap){
        if(preStart > preEnd || inStart > inEnd) return NULL;

        int ele = preorder[preStart];
        int pos = inMap[ele]-1;
        int numsLeft = pos-inStart;

        TreeNode* root = new TreeNode(ele);

        root->left = solve(preorder, inorder, preStart+1, preStart+numsLeft, inStart, pos, inMap);

        root->right = solve(preorder, inorder, preStart+numsLeft+1, preEnd, pos+1, inEnd, inMap);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preStart = 0, preEnd = preorder.size()-1;
        int inStart = 0, inEnd = inorder.size()-1;
        
        map<int,int> inMap;
        for(int i=0; i<=inEnd; i++){
            inMap[inorder[i]] = i+1;
        }

        return solve(preorder, inorder, preStart, preEnd, inStart, inEnd, inMap);
    }
};
