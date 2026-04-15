class MedianFinder {
public:
    vector<int> ele;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        auto itr = lower_bound(ele.begin(), ele.end(), num);
        if(itr == ele.end()) ele.push_back(num);
        else{
            int ind = itr-ele.begin();
            ele.insert(ele.begin()+ind, num);
        }
    }
    
    double findMedian() {
        double ans;
        int size = ele.size();
        if(size%2 == 0){
            int a = ele[size/2];
            int b = ele[size/2-1];
            ans = ((double)a + b)/2.0;
        }
        else ans = double(ele[size/2]);
        return ans;
    }
};
