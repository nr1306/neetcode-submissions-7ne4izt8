class Solution {
public:
    void f(vector<int>& nums, set<vector<int>>& res, vector<int> temp,
    int target, int i){
        if(!target){
            sort(temp.begin(),temp.end());
            res.insert(temp);
        }
        if(i == nums.size()){
            return;
        }


        // Taking the ith element 
        if(nums[i] <= target){
            temp.push_back(nums[i]);
            f(nums,res,temp,target-nums[i],i+1);
        // Then removing the element to make other combos
            temp.pop_back();
        }
        // Not taking the ith element
        f(nums,res,temp,target,i+1);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> res;
        vector<int> temp;
        f(candidates,res,temp,target,0);
        vector<vector<int>> ans(res.begin(), res.end());
        return ans;
    }
};
