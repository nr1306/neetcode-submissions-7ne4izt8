class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if(arr.size() == k) return arr;
        priority_queue<pair<int,int>, vector<pair<int,int>>> maxheap;
        for(int ele : arr){
            int diff = abs(ele-x);
            maxheap.push({diff,ele});
            if(maxheap.size()>k) maxheap.pop();
        }

        vector<int> res;
        while(!maxheap.empty()){
            pair<int,int> ele = maxheap.top();
            maxheap.pop();
            res.push_back(ele.second);
        }
        sort(res.begin(), res.end());
        return res;
    }
};