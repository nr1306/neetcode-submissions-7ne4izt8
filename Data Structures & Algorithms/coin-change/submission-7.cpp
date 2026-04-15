class Solution {
public:
    int mini = INT_MAX;
    void solve(vector<int>& coins, int i, int cnt, int amt){
        if(i == coins.size()-1){
            if(amt%coins[i] == 0){
                cnt += amt/coins[i];
                mini = min(mini, cnt);
            }
            return;
        }

        if(amt-coins[i] >= 0){
            solve(coins,i,cnt+1,amt-coins[i]);
        }
        solve(coins,i+1,cnt,amt);
    }

    int coinChange(vector<int>& coins, int amount) {
        int cnt = 0;
        solve(coins,0,cnt,amount);
        if(mini == INT_MAX) return -1;
        return mini;
    }
};
