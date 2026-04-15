class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxheap;
        for(int x : stones) maxheap.push(x);

        while(maxheap.size()>1){
            int x = maxheap.top();
            maxheap.pop();
            int y = maxheap.top();
            maxheap.pop();
            if(x != y) maxheap.push(abs(x-y));
        }
        if(maxheap.size()) return maxheap.top();
        return 0;
    }
};
