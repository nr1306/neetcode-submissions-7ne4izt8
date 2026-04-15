class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>> maxheap;
        if(stones.size() == 1) return stones[0];

        for(int x : stones){
            maxheap.push(x);
        }

        while(maxheap.size() > 1){
            int stone1 = maxheap.top();
            maxheap.pop();
            int stone2 = maxheap.top();
            maxheap.pop();
            if(stone1 != stone2)
                maxheap.push(abs(stone1-stone2));
        }
        
        return maxheap.size() ? maxheap.top() : 0;
    }
};
