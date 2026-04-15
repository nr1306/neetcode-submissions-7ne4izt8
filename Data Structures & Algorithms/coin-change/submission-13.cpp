class Solution {
public:
    int solve(vector<int>& coins, int i, int amt, vector<int>& dp){
        if(i == coins.size()-1){
            if(amt % coins[i] == 0){
                return amt/coins[i];
            }
            else return 1e9;
        }

        if(dp[amt] != -1) return dp[amt];

        int num1 = 1e9;
        if(coins[i] <= amt)
            num1 = 1 + solve(coins,i,amt-coins[i],dp);
        
        int num2 = 0+solve(coins,i+1,amt,dp);

        return dp[amt] = min(num1, num2);
    }

    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end(), greater<int>());
        
// If we are giving dp array dimension equal to coin.size, it indicates, that if we land at ith index, and dp[i] != -1, does it mean that everytime we land at ith index we will get the sum of elements >=i equal to amt (any number of comb)
// No that is not the case, we need to take the dimension of dp as amount+1, what it indicates that if we land at this x amt, then it is definitely possible to reach to target after making some combinations
// Its not the case with i that if we land at index i we'll get combination of elements = amount, we are not giving attention to amt value here
        vector<int> dp(amount+1,-1);
        
        
        long long res = (long long)solve(coins, 0, amount, dp);
        if(res >= 1e9) return -1;
        return res;
    }
};
