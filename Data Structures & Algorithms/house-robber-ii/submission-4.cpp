class Solution {
public:
    int solve(vector<int>& nums, int i, vector<int>& dp){
        if(i > nums.size()-1)
            return 0;
        
        if(dp[i] != -1) return dp[i];

        int money1 = 0 + solve(nums,i+1,dp);
        int money2 = nums[i] + solve(nums,i+2,dp);

        return dp[i] = max(money1, money2);

    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> dp1(n,-1), dp2(n,-1);
    // Its circular so if we are robbing first house, we'll skip the last house coz it will make it adjacent
    // If we are skipping the first house then we can include the last house
        
        vector<int> temp1 (nums.begin(), nums.begin()+n-1);
        vector<int> temp2 (nums.begin()+1, nums.end());
        
        int money1 = solve(temp1,0,dp1);
        int money2 = solve(temp2,0,dp2);

        return max(money1, money2);
    }
};
