class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>> maxheap;
        for(int i=0; i<points.size(); i++){
            int distance = points[i][0] * points[i][0] + 
                            points[i][1] * points[i][1];
            maxheap.push({distance, points[i]});
            if(maxheap.size() > k) maxheap.pop();
        }

        vector<vector<int>> res;
        while(!maxheap.empty()){
            res.push_back(maxheap.top().second);
            maxheap.pop();
        }
        return res;
    }
};
