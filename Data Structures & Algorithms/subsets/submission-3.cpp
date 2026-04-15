class Solution {
public:
    void f(vector<int>& nums, vector<int> temp, 
    vector<vector<int>>& res, int i){
        if(i == nums.size()){
            res.push_back(temp);
            return;
        }
        f(nums,temp,res,i+1);
        temp.push_back(nums[i]);
        f(nums,temp,res,i+1);
        temp.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        f(nums, temp, res, 0);
        return res;
    }
};
