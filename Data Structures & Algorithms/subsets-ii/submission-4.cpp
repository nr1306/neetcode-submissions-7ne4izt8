class Solution {
public:
    set<vector<int>> res;

    void solve(vector<int>& nums, vector<int> temp, int i){
        if(i >= nums.size()){
            res.insert(temp);
            return;
        }
        

        solve(nums,temp,i+1);
        temp.push_back(nums[i]);
        solve(nums,temp,i+1);
        temp.pop_back();
        
        while(i+1 < nums.size() && nums[i] == nums[i+1]) i++;
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        solve(nums,temp,0);
        return vector<vector<int>> (res.begin(), res.end());
    }
};
