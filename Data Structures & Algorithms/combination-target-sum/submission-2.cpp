class Solution {
public:
    void f(vector<int>& nums, set<vector<int>>& res, vector<int> temp,
    int target, int i){
        if(!target)
            res.insert(temp);
        if(i == nums.size()){
            return;
        }

        // Taking the ith element and stay coz we can take this element again
        if(nums[i] <= target){
            temp.push_back(nums[i]);
        // We can stay and take this element again
            f(nums,res,temp,target-nums[i],i);
        
        // FOLLOWING FUNC CALL WILL BE REPETIVE
        // // Or take element and move ahead
        //     f(nums,res,temp,target-nums[i],i+1);
        
        // Then removing the element to make other combos
            temp.pop_back();
        }
        // Not taking the ith element
        f(nums,res,temp,target,i+1);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        set<vector<int>> res;
        vector<int> temp;
        f(nums,res,temp,target,0);
        vector<vector<int>> ans(res.begin(),res.end());
        return ans;
    }
};
