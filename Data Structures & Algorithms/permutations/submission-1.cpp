class Solution {
public:
    void f(vector<int>& nums, vector<vector<int>>& res,
    vector<int> temp, vector<bool> vis, int index){
        if(index == nums.size()){
            res.push_back(temp);
            return;
        }

        for(int i=0; i<nums.size(); i++){
            if(!vis[i]){
                vis[i] = true;
                temp.push_back(nums[i]);
                f(nums,res,temp,vis,index+1);
                temp.pop_back();
                vis[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> vis(nums.size(),false);
        vector<vector<int>> res;
        vector<int> temp;
        f(nums,res,temp,vis,0);
        return res;
    }
};
