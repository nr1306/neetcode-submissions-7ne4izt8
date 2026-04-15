class Solution {
public:
    int f(vector<int>& coins, int n, int amount, int count, int& minCount){
        if(!amount){
            minCount = min(minCount, count);
            return minCount;
        }
        if(n == -1) return INT_MAX; // If all the combinations are tried out and no sum amount found

        int coinCount1 = INT_MAX;
        if(amount >= coins[n]) // Taking the current coin if we can
            coinCount1 = f(coins,n,amount-coins[n],count+1,minCount);
        int coinCount2 = f(coins,n-1,amount,count,minCount); // else moving to next coin

        return min(coinCount1, coinCount2);
    }

    int coinChange(vector<int>& coins, int amount) {
        if(!amount) return 0;
        sort(coins.begin(), coins.end());
        int count = 0;
        int minCount = INT_MAX;

        int res = f(coins,coins.size()-1,amount,count,minCount);
        if(res == INT_MAX) res = -1;
        return res;
    }
};
