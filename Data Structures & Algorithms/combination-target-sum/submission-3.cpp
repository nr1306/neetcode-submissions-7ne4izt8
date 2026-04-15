class Solution {
public:
    void f(vector<int>& nums, int target, vector<vector<int>>& res,
    vector<int> temp, int i){
        if(i == nums.size()){
            if(target == 0) res.push_back(temp);
            return;
        }
        if(nums[i]<= target){
            temp.push_back(nums[i]);
            f(nums,target-nums[i],res,temp,i);
            temp.pop_back();
        }
        f(nums,target,res,temp,i+1);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        f(nums,target,res,temp,0);
        return res;
    }
};
