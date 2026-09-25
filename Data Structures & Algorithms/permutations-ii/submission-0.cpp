class Solution {
public:

    void solve(vector<int>& nums, vector<int> temp, 
    set<vector<int>>& res, map<int,int>& vis){
        if(temp.size() == nums.size()){
            res.insert(temp);
        }

        for(int i = 0; i<nums.size(); i++){
            if(!vis[i]){
                temp.push_back(nums[i]);
                vis[i] = 1;
                solve(nums,temp,res,vis);
                temp.pop_back();
                vis[i] = 0;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        vector<int> temp;
        map<int,int> vis;
        set<vector<int>> res;

        solve(nums,temp,res,vis);
        return vector<vector<int>> (res.begin(), res.end());
        // return vector<vector<int>> (res.begin(), res.end());
    }
};