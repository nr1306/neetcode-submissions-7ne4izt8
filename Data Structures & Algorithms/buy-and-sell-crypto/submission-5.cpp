class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prefixMin = prices[0];
        int maxProfit = 0;
        for(int i=1; i<prices.size(); i++){         
            maxProfit = max(maxProfit,prices[i]-prefixMin);
            prefixMin = min(prefixMin, prices[i]);
        }
        return maxProfit;
    }
};
