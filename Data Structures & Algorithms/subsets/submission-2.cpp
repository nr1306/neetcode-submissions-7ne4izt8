class Solution {
public:
    void f(vector<int>& nums, vector<vector<int>>& res, vector<int> temp,
    int i){
        if(i == nums.size()){
            res.push_back(temp);
            return;
        }
        //not taking the ith element
        f(nums,res,temp,i+1);
        // isnerting the element to temp
        temp.push_back(nums[i]);
        f(nums,res,temp,i+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        f(nums,res,temp,0);
        return res;
    }
};
