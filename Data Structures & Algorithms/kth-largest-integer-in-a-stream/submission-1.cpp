class KthLargest {
    priority_queue<int,vector<int>,greater<int>> minheap;
    int target;
public:
    KthLargest(int k, vector<int>& nums) {
        target = k;
        for(int i=0; i<nums.size(); i++){
            minheap.push(nums[i]);
            if(minheap.size()>target) minheap.pop();
        }
    }
    
    int add(int val) {
        minheap.push(val);
        if(minheap.size()>target) minheap.pop();
        return minheap.top();
    }
};
