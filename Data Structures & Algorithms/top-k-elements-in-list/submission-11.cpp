class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, 
        greater<pair<int,int>>> minheap;

        map<int,int> freq;
        for(int x : nums){
            freq[x]++;
        }

        for(auto [key,val] : freq){
            minheap.push({val,key});
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
