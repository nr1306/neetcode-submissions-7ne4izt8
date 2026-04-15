class Solution {
public:
    int solve(int n, vector<int>& dp){
        if(n<=0) return 0;

        if(dp[n] != -1) return dp[n];

        int steps = solve(n-1,dp);
        if(n >= 2)
            steps += solve(n-2,dp);
        
        return dp[n] = steps;
    }

    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        dp[1] = 1;
        dp[2] = 2;
        return solve(n,dp);
    }
};
