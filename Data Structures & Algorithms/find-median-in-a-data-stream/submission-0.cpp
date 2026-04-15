class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> minheap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        minheap.push(num);
        cout << minheap.top() << endl;
    }
    
    double findMedian() {
        queue<int> popped_ele;
        int size = minheap.size();
        if(size == 1) return minheap.top();
        int prev = -1;
        for(int i=0; i<size/2; i++){
            prev = minheap.top();
            popped_ele.push(prev);
            minheap.pop();
        }
        double ans;
        if(size%2 == 0) ans = ((double)prev + minheap.top())/2.0;
        else ans = minheap.top();
        
        while(!popped_ele.empty()){
            minheap.push(popped_ele.front());
            popped_ele.pop();
        }
        return ans;
    }
};
