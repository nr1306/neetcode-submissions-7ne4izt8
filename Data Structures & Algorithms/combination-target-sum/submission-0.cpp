class Solution {
public:
    void f(vector<int>& nums, int target, int i, vector<int> temp, set<vector<int>>& res){
        if(i == nums.size()) return;
        if(!target){
            res.insert(temp); 
        }

        if(target >= nums[i]){
            temp.push_back(nums[i]);
            f(nums,target-nums[i], i, temp, res);
            temp.pop_back(); // backtracking , removing last element to make diff combo
        }
        f(nums,target, i+1, temp, res);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> temp;
        set<vector<int>> res;
        f(nums,target,0,temp,res);
        vector<vector<int>> ans {res.begin(), res.end()};
        return ans;
    }
};
