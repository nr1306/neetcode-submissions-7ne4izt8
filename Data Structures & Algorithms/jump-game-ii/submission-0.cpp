class Solution {
public:
    bool f(vector<int>& nums, int i, vector<bool>& dp,
    int count, int& mini){
        if(i>=nums.size()-1){
            mini = min(mini, count);
            return true;
        }
        if(!nums[i]) return false;

        if(dp[i]) return dp[i];

        for(int steps = nums[i]; steps>=1; steps--){
            if(f(nums,i+steps,dp,count+1,mini)) dp[i] = true;
        }
        return false;
    }

    int jump(vector<int>& nums) {
        int count = 0;
        int mini = INT_MAX;
        vector<bool> dp(nums.size(),false);
        f(nums, 0, dp, count, mini);
        return mini;
    }
};
