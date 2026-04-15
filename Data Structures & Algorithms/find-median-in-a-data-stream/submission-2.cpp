class MedianFinder {
public:
    priority_queue<int> smallHeap; // Its gonna be maxheap
    priority_queue<int,vector<int>, greater<int>> largeHeap; // minheap


    MedianFinder() {
        
    }
    
    void addNum(int num) {
        smallHeap.push(num);

        if(!largeHeap.empty() && smallHeap.top() > largeHeap.top()){
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }

        if(smallHeap.size() > largeHeap.size()+1){
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }

        if(largeHeap.size() > smallHeap.size()+1){
            smallHeap.push(largeHeap.top());
            largeHeap.pop();
        }
    }
    
    double findMedian() {
        int size1 = smallHeap.size();
        int size2 = largeHeap.size();
        int size = size1 + size2;

        double res = 0.0;

        if(size1 == size2){
            res = (smallHeap.top() + largeHeap.top())/2.0;
        }
        else {
            res = size1 > size2 ? smallHeap.top() : largeHeap.top();
        }

        return res;
    }
};
