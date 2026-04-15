class Solution {
public:
    void solve(vector<int>& nums, vector<int> temp, 
    vector<vector<int>>& res, vector<int>& vis, int i){
        int size = nums.size();
        if(i == size){
            res.push_back(temp);
            return;
        }

        for(int k=0; k<size; k++){
            if(!vis[k]){
                temp.push_back(nums[k]);
                vis[k] = 1;
                solve(nums,temp,res,vis, i+1);
                temp.pop_back();
                vis[k] = 0;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        vector<int> vis(nums.size(), 0);
        solve(nums, temp, res, vis, 0);
        return res;
    }
};
