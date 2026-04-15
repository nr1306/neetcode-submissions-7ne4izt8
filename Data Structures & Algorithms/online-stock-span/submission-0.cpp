class StockSpanner {
    vector<int> stocks;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        stocks.push_back(price);
        int span = 0;
        int n = stocks.size();
        for(int i=n-1; i>=0; i--){
            if(stocks[i] <= price) span++;
            else break;
        }
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */