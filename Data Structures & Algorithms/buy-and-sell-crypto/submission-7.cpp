class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int buy = 0; // index of stock which we bought
        int n = prices.size();
        for(int i=1; i<n; i++){
            if(prices[i] < prices[buy]){
                buy = i; // It will be loss if we sell it on this day
                // Instead will buy this stock - and wont do any transaction
            }
            profit = max(profit , prices[i] - prices[buy]);
        }

        return profit;
    }
};
