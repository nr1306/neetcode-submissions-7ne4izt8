class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int localprofit = 0;
        int buy = 0;
        int n = prices.size();
        for(int i=0; i<n; i++){
            if(prices[i] - prices[buy] > localprofit){
                localprofit = prices[i] - prices[buy];
            }
            else{
                buy = i;
                profit += localprofit;
                localprofit = 0;
            }
        }

        return profit + localprofit;
    }
};