class Solution {
public:
    void solve(vector<int>& nums, vector<int> temp, int sum ,
    vector<vector<int>>& res, int i, int target){
        if(i == nums.size()){
            if(sum == target) 
                res.push_back(temp);
            return;
        }

        if(sum+nums[i] <= target){
            temp.push_back(nums[i]);
            sum += nums[i];
            solve(nums, temp, sum, res, i, target);
            temp.pop_back();
            sum-=nums[i];
        }
        solve(nums,temp,sum,res,i+1, target);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        int sum = 0;
        solve(nums, temp, sum, res, 0, target);
        return res;
    }
};
