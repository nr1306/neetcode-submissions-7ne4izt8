class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& res, vector<int> temp, int i){
        if(i == nums.size()){
            res.push_back(temp);
            return;
        }

        solve(nums,res,temp,i+1);
        temp.push_back(nums[i]);
        solve(nums,res,temp,i+1);
        temp.pop_back();    
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        solve(nums, res,temp,0);
        return res;
    }
};
