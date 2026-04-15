class Solution {
public:
    bool f(vector<int>& nums, int i, vector<bool>& dp){
        if(i >= nums.size()-1) return true;
        if(!nums[i]) return false;

        if(dp[i]) return dp[i];

        for(int steps = nums[i] ; steps >= 1; steps--){
            if(f(nums,i+steps,dp)) return dp[i] = true;
        }
        return false;
    }

    bool canJump(vector<int>& nums) {
        if(nums.size() == 1) return true;
        vector<bool> dp(nums.size(), false);
        return f(nums,0, dp);
    }
};
