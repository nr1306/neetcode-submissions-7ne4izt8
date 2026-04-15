class Solution {
public:
    int solve(int n, vector<int>& dp){
        if(n < 1) return 0;
        
        if(dp[n] != -1) return dp[n];

        int count1 = solve(n-1,dp);
        int count2 = 0;
        if(n > 2)
            count2 = solve(n-2,dp);

        return dp[n] = count1 + count2;
    }

    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        return solve(n,dp);
    }
};
