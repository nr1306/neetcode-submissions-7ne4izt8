class Solution {
public:
    void solve(vector<int>& nums, vector<int> temp, int i,
    int target, vector<vector<int>>& res){
        if(i == nums.size()){
            if(!target){
                res.push_back(temp);
            }
            return;
        }

        if(nums[i] <= target){
            temp.push_back(nums[i]);
            solve(nums,temp,i,target-nums[i],res);
            temp.pop_back();
        }
        solve(nums,temp,i+1,target,res);
        
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> temp;
        solve(nums,temp,0,target,res);
        return res;
    }
};
