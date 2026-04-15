class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> freq;
        for(int x : nums) freq[x]++;

        // Now we have two options, we can store top k frequent elements in a heap
        // Or we can use another map keeping frequency as key
        // Then find the k most freq elements

        priority_queue<pair<int,int>, 
        vector<pair<int,int>>, greater<pair<int,int>> > minheap;
        
        for(auto itr : freq){
            minheap.push({itr.second, itr.first});
            if(minheap.size() > k) minheap.pop();
        }

        vector<int> res;
        while(!minheap.empty()){
            res.push_back(minheap.top().second);
            minheap.pop();
        }
        
        return res;
    }
};
