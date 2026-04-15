class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minheap;
        for(int x : nums){
            if(minheap.size() < k) minheap.push(x);
            else if(x > minheap.top()){
                minheap.push(x);
                minheap.pop();
            }
        }
        return minheap.top();
    }
};
