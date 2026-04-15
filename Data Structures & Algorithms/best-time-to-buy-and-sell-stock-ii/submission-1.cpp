class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 0;
        int localprofit = 0;
        int profit = 0;
        for(int i=1; i<prices.size(); i++){
// First we are checking that, if there are consecutive price increase, then we'll keep on update localprofit unless there is dip in profit
// When the dip comes we'll update the buyth item and add the profit
            if(prices[i] - prices[buy] > localprofit) 
                localprofit = prices[i] - prices[buy];
            else{
                buy = i;
                profit += localprofit;
                localprofit = 0;
            }
        }
        if(localprofit) profit += localprofit;
        return profit;
    }
};