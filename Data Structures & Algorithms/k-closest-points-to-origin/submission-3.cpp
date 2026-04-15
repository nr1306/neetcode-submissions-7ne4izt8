class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,vector<int> >, 
        vector<pair<double, vector<int>> >> maxheap;

        for(vector<int> coord : points){
            double dist = (double)sqrt(coord[0]*coord[0] + coord[1]*coord[1]);
            pair<double, vector<int> > dist_coord = {dist, coord};
            maxheap.push(dist_coord);
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
