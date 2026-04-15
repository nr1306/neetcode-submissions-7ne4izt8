class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        for(int x : nums) mp[x]++;
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, 
        greater<pair<int,int>>> maxheap;

        for(auto itr : mp){
            maxheap.push({itr.second, itr.first});
            if(maxheap.size() > k) maxheap.pop();
        }
        vector<int> res;
        while(!maxheap.empty()){
            res.push_back(maxheap.top().second);
            maxheap.pop();
        }
        return res;
    }
};
