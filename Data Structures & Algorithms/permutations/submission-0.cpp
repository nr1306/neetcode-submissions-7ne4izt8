class Solution {
public:
    void f(vector<int>& nums, vector<vector<int>>& res, vector<bool>& vis,
    vector<int> temp){
        int n = nums.size();
        if(temp.size() == nums.size()){
            res.push_back(temp);
            return;
        } 

        for(int i=0; i<n; i++){
            if(!vis[i]){
                temp.push_back(nums[i]);
                vis[i] = true;
                f(nums,res,vis,temp);
                temp.pop_back();
                vis[i] = false;
            }
        }

    
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        vector<bool> vis(n,false);
        vector<int> temp;
        
        f(nums,res,vis,temp);
        return res;
    }
};
