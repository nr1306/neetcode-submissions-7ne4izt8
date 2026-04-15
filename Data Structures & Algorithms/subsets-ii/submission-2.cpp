class Solution {
public:
    void solve(vector<int>& nums, set<vector<int>>& res, 
    vector<int> temp, int i){
        if(i == nums.size()){
            sort(temp.begin(), temp.end());
            res.insert(temp);
            return;
        }

        solve(nums, res, temp, i+1);
        temp.push_back(nums[i]);
        solve(nums, res, temp, i+1);
        temp.pop_back();
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> res;
        vector<int> temp;
        solve(nums, res, temp, 0);
        return vector<vector<int>> (res.begin(), res.end());
    }
};
