class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int> , vector<pair<int,int>> > maxheap;

        for(int a : arr){
            int dist = abs(x-a);
            pair<int,int> coord {dist , a};

            maxheap.push(coord);
            if(maxheap.size() > k) maxheap.pop();
        }

        vector<int> res;
        while(!maxheap.empty()){
            pair<int,int> coord = maxheap.top();
            maxheap.pop();
            if(res.empty())
                res.push_back(coord.second);
            else{
                auto itr = lower_bound(res.begin(), res.end(), coord.second);
                if(itr == res.end())
                    res.push_back(coord.second);
                else{
                    int ind = itr - res.begin();
                    res.insert(res.begin()+ind , coord.second);
                }
            }
        }

        return res;
    }
};