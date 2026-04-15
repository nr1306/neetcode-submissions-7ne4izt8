class Solution {
public:
    int f(vector<int>& cost, int i, int n, vector<int>& dp){
        if(i >= n) return 0;

        if(dp[i] != -1) return dp[i];

    // taking one step down from top floor
        int cost1 = cost[i] + f(cost,i+1,n,dp);
    // taking 2 steps down from top
        int cost2 = INT_MAX;
        if(n>1)
            cost2 = cost[i] + f(cost,i+2,n,dp);

        return dp[i] = min(cost1,cost2);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,-1);
        // dp[0] = cost[0];
        // dp[1] = cost[1];
        return min (f(cost,0,n,dp), f(cost,1,n,dp));
    }
};
