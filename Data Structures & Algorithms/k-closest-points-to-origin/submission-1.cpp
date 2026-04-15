class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        priority_queue< pair<double, vector<int>> > pq;

        for(vector<int> point : points){
            double distance = (double)sqrt(pow(point[0],2) + pow(point[1],2));
            cout << distance << " " << point[0] << " " << point[1] << endl;
            if(pq.size() < k) pq.push({distance, point});
            else if(distance < pq.top().first){
                pq.push({distance, point});
                pq.pop();
            }
        }

        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
