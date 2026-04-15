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

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            if(node){
                res.append(to_string(node->val) + ",");
                q.push(node->left);
                q.push(node->right);
            }
            else
                res.append("#,"); // # to indicate null values
            
            q.pop();

        }
        // cout << res;
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string res) {
        if(res.size() == 0) return nullptr;
        
        stringstream ss (res);
        string ch;
        getline(ss,ch,',');

        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(stoi(ch));
        q.push(root);
        
        while(!q.empty()){

            TreeNode* node = q.front();

            getline(ss,ch,',');
            cout << ch << " ";
            if(ch == "#")
                node->left = nullptr;
            else{
                TreeNode* leftNode = new TreeNode(stoi(ch));
                node->left = leftNode;
                q.push(leftNode);
            }
            
            getline(ss,ch,',');
            cout << ch << " ";
            if(ch == "#")
                node->right = nullptr;
            else{
                TreeNode* rightNode = new TreeNode(stoi(ch));
                node->right = rightNode;
                q.push(rightNode);
            }

            q.pop();
            
        }
        return root;
    }
};
