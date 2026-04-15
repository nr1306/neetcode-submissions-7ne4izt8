class Solution {
public:
    int f(vector<int>& nums, int i, vector<int>& dp){
        int n = nums.size();
        if(i >= n) return 0;

        if(dp[i] != -1) return dp[i];

        // We'll rob ith house and move to i+2th
        int money1 = nums[i] + f(nums,i+2, dp);
        // Or we'll move to i+1th house and don't rob the ith house
        int money2 = 0 + f(nums,i+1,dp);

        return dp[i] = max(money1,money2);
    }

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return f(nums,0,dp);
    }
};
