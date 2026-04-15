class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int i = 0, j=n-1,maxi=0;
        int prefixMin = prices[0];
        
        int profit = 0;
        for(int i=1; i<n; i++){
            while(i<n && prices[i]-prefixMin > maxi){
                maxi = prices[i]-prefixMin;
                i++;
            }
            profit += maxi;
            prefixMin = min(prefixMin, prices[i]);

        }
        return maxi;
    }
};
