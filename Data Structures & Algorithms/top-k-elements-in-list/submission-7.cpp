class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(nums.size() == 1) return nums;
        
        priority_queue<pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>> 
        minheap;

        map<int,int> freq;
        for(int x : nums) freq[x]++;

        for(auto itr : freq){
            minheap.push({itr.second, itr.first});
            if(minheap.size() > k) minheap.pop();
        }

        vector<int> res;
        while(!minheap.empty()){
            pair<int,int> ele = minheap.top();
            res.push_back(ele.second);
            minheap.pop();
        }
        return res;
    }
};
