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
            int size = q.size();
            while(size--){
                TreeNode* node = q.front();
                q.pop();

                if(node){
                    res.append(to_string(node->val) + ",");
                    q.push(node->left);
                    q.push(node->right);
                }

                else 
                    res += "#,";
            }
        }
        
        cout << res;
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "") return NULL;

        stringstream ss(data);
        string ele;

        getline(ss, ele, ',');
        int val = stoi(ele);

        TreeNode* root = new TreeNode(val);

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){

            int size = q.size();
            
            while(size--){
                TreeNode* node = q.front();
                q.pop();

                getline(ss, ele, ',');
                if(ele == "#")
                    node->left = NULL;
                else{
                    int val = stoi(ele);
                    node->left = new TreeNode(val);
                    q.push(node->left);
                }

                getline(ss,ele,',');
                if(ele == "#")
                    node->right = NULL;
                else{
                    int val = stoi(ele);
                    node->right = new TreeNode(val);
                    q.push(node->right);
                }
            }

        }

        return root;
    }
};
