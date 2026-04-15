class Solution {
public:
    int solve(vector<int>& coins, int i, int amt, 
    vector<vector<int>> &dp){

        if(i == coins.size()-1){
            if(amt % coins[i] == 0){
                return amt/coins[i];
            }
            else return 1e9;
        }

        if(dp[i][amt] != -1) return dp[i][amt];

        int num1 = 1e9;
        if(coins[i] <= amt)
            num1 = 1 + solve(coins,i,amt-coins[i],dp);
        
        int num2 = 0+solve(coins,i+1,amt,dp);

        return dp[i][amt] = min(num1, num2);
    }

    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end(), greater<int>());
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, -1));
        
        long long res = (long long)solve(coins, 0, amount, dp);
        if(res >= 1e9) return -1;
        return res;
    }
};
