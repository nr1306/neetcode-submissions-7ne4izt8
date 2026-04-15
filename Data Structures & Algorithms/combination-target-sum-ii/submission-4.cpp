class Solution {
public:
    void f(vector<int>& nums, int target, set<vector<int>>& res,
    vector<int> temp, int i){
        if(i == nums.size()){
            if(target == 0){
                sort(temp.begin(), temp.end());
                res.insert(temp);
            } 
            return;
        }
        if(nums[i]<= target){
            temp.push_back(nums[i]);
            f(nums,target-nums[i],res,temp,i+1);
            temp.pop_back();
        }
        f(nums,target,res,temp,i+1);
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        set<vector<int>> res;
        vector<int> temp;
        f(nums,target,res,temp,0);
        return vector<vector<int>> (res.begin(), res.end());
    }
};
