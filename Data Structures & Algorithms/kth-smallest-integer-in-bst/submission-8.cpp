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
    void dfs(TreeNode* root, priority_queue<int, vector<int>>& maxheap, int k){
        if(!root) return;
        dfs(root->left,maxheap,k);
        dfs(root->right,maxheap,k);

        maxheap.push(root->val);
        if(maxheap.size() > k) maxheap.pop();
    }

    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int, vector<int>> maxheap;

        dfs(root, maxheap, k);

        return maxheap.top();
    }
};
