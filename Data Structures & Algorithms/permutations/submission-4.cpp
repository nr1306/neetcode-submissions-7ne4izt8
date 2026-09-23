class Solution {
public:
    void solve(vector<int>& nums, vector<int> temp, int ind, 
    vector<vector<int>>& res, map<int,int>& vis){
        if(temp.size() == nums.size()){
            res.push_back(temp);
        }

        for(int i = 0; i<nums.size(); i++){
            if(!vis[nums[i]]){
                temp.push_back(nums[i]);
                vis[nums[i]] = 1;
                solve(nums,temp,i+1,res,vis);
                temp.pop_back();
                vis[nums[i]] = 0;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        map<int,int> vis;
        solve(nums,temp,0,res,vis);
        return res;
    }
};
