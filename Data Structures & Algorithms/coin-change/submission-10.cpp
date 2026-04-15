class Solution {
public:
    int mini = INT_MAX;
    
    long long solve(vector<int>& coins, int i, int amt,
    vector<int>& dp){

        if(i == coins.size()-1){
            if(amt%coins[i] == 0){
                return amt/coins[i];
            }
            return 1e9;
        }

        if(dp[amt] != -1) return dp[amt];

        long long res1 = 1e9;
        if(amt-coins[i] >= 0){
            res1 = 1 + solve(coins,i,amt-coins[i],dp);
        }
        long long res2 = 0 + solve(coins,i+1,amt,dp);

        return dp[amt] = min(res1, res2);
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        long long res = solve(coins,0,amount,dp);
        if(res >= 1e9) return -1;
        return res;
    }
};
