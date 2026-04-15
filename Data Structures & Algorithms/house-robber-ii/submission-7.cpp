class Solution {
public:
    int solve(vector<int>& nums, int i, vector<int>& dp){
        if(i >= nums.size()) return 0;

        if(dp[i] != -1) return dp[i];

        // if we are not robbing the ith house, we'll just move to i+1
        int money1 = 0 + solve(nums,i+1,dp);
        // If we are robbing ith house we'll move to i+2th house
        int money2 = nums[i] + solve(nums,i+2,dp);

        return dp[i] = max(money1, money2);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        
        vector<int> temp1 (nums.begin(), nums.begin()+n-1);
        vector<int> temp2 (nums.begin()+1, nums.end());
        
        vector<int> dp1(temp1.size()+1,-1), dp2(temp2.size()+1,-1);
        
        return max(solve(temp1, 0, dp1), solve(temp2, 0, dp2));
    }
};
