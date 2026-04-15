class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxi = 0;
        int prefixMin = prices[0];

        for(int i=1; i<n; i++){
            if(prices[i] - prefixMin > maxi){
                maxi = prices[i] - prefixMin;
            }
            prefixMin = min(prices[i] , prefixMin);
        }
        return maxi;
    }
};
