class Solution {
public:
    bool solve(vector<int>& nums, int i, vector<bool>& dp){
        int n = nums.size();
        if(i >= n-1){
            return true;
        }

        if(!nums[i]) return false;

        if(dp[i]) return dp[i];

        for(int j=i+1; j<=i+nums[i]; j++){
            if(solve(nums,j,dp)) 
                return dp[i] = true;
        }
        return dp[i] = false;
    }

    bool canJump(vector<int>& nums) {
       vector<bool> dp(nums.size()+1, false);
       return solve(nums, 0, dp);
    }
};
