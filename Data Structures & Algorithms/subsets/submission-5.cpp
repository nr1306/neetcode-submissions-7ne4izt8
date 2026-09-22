class Solution {
public:
    void solve(vector<int>& nums, vector<int> temp, int i, 
    vector<vector<int>>& res){
        if(i == nums.size()){
            res.push_back(temp);
            return;
        }

        solve(nums,temp,i+1,res);
        temp.push_back(nums[i]);
        solve(nums,temp,i+1,res);
        temp.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        solve(nums, temp, 0, res);
        return res;
    }
};
