class Solution {
public:
    int f(int n, int& count, vector<int>& dp){
        if(n<=0){
            count++;
            return count;
        }
        if(dp[n] != -1) return dp[n];

        int steps1 = f(n-1,count,dp);
        int steps2 = 0;
        if(n>1)
            steps2 = f(n-2,count,dp);
        
        return dp[n] = steps1+steps2;
    }

    int climbStairs(int n) {
        int count = 0;
        vector<int> dp(n+1,-1);
        dp[1] = 1;
        dp[2] = 2;
        return f(n,count,dp);
    }
};
