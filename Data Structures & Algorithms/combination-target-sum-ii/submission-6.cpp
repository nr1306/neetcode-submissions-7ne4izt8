class Solution {
public:
    void solve(vector<int>& nums, vector<int> temp, int sum,
    int i, int target, set<vector<int>>& res){
        if(i == nums.size()){
            if(sum == target){
                sort(temp.begin(), temp.end());
                res.insert(temp);
            } 
            return;
        }

        if(sum + nums[i] <= target){
            sum += nums[i];
            temp.push_back(nums[i]);
            solve(nums, temp, sum, i+1, target, res);
            temp.pop_back();
            sum -= nums[i];
        }
        solve(nums,temp, sum, i+1, target, res);
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        set<vector<int>> res;
        vector<int> temp;
        int sum = 0;
        solve(nums, temp, sum, 0, target, res);
        return vector<vector<int>>(res.begin(), res.end());
    }
};
