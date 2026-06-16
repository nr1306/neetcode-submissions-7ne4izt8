class Solution {
public:
    static bool comparator(pair<int,int>& a, pair<int,int>& b){
        return a.first > b.first;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
       priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> heap;

       map<int,int> freq;
       for(int x : nums) freq[x]++;
       for(auto [key, value] : freq){
            heap.push({value,key});
            if(heap.size() > k) heap.pop();
       }

       vector<int> res;
       while(!heap.empty()){
            pair<int,int> temp = heap.top();
            heap.pop();
            res.push_back(temp.second);
       }
       return res;
    }
};
