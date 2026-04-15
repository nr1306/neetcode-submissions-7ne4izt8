class KthLargest {
public:
    priority_queue<int, vector<int>,greater<int>> minheap;
    int n;
   
    KthLargest(int k, vector<int>& nums) {
        n = k;
        for(int num : nums){
            if(minheap.size() < n )
                minheap.push(num);
            else if(num > minheap.top()){
                minheap.push(num);
                if(minheap.size() > n)
                    minheap.pop();
            }
        }
    }
    int add(int val) {
        if(minheap.size() < n) minheap.push(val);
        else if(val > minheap.top()){
            minheap.push(val);
            if(minheap.size() > n) minheap.pop();
        }
        
        return minheap.top();
    }
};
