class Solution {
public:
    int f(vector<int>& coins, int n, int amount, map<int,int>& dp){
        // If there are overlapping subproblems and Without thinking just 
        // create dp array of dimensions of how many parameters are changing in each recursive call
        // Here index and amount is changing we could have created n x amount dimension of dp array
        // always try to think the base by reaching at 0th index
        if(n == 0){ // base case
            if(amount%coins[0] == 0) return amount/coins[0];
            return 1e9;
        }
        if(dp.find(amount) != dp.end()) return dp[amount];

        int coinCount1 = 1e9;
        if(amount >= coins[n]) // Taking the current coin if we can
            coinCount1 = 1 + f(coins,n,amount-coins[n],dp);
        int coinCount2 = 0 + f(coins,n-1,amount,dp); // else moving to next coin

        return dp[amount] = min(coinCount1, coinCount2);
    }

    int coinChange(vector<int>& coins, int amount) {
        if(!amount) return 0;
        sort(coins.begin(), coins.end()); // So that we are sure we are taking minimum number of coins
       
        map<int,int> dp; 
// Here we should map if at a point we reach a specific amount after that 
// how many coins are required to create sum "amount" we should not use 
// mapping with a specific element it wnon't make sense as an element 
//would repeat a thousand times 
        int res = f(coins,coins.size()-1,amount,dp);
        if(res >= 1e9) return -1;
        return res;
    }
};
