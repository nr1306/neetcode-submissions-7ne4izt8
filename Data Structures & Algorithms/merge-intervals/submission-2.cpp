class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        int start = intervals[0][0];
        int end = intervals[0][1];

        for(int i=1; i<n; i++){
            int count = 1; // to check wheter we encounter overlapping intervals or not
            // also count is useful in finding the index where we started and encounter overlapping intervals by doing i-count
            while(i<n && intervals[i][0] <= end){
                end = max(end, intervals[i][1]);
                start = min(start,intervals[i][0]);
                cout << start << " ";
                i++;
                count++;
            }
            if(count > 1){ // If we found overlapping intervals
                // cout << 
                intervals.erase(intervals.begin()+i-count, intervals.begin()+i);
                intervals.insert(intervals.begin()+i-count, {start,end});
                i = i-count; // updating the index where we want to start
                n = intervals.size(); // updating the size of intervals as we have merge overlapping intervals
            }
            
            // New start and New end
            if(i<n){
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        return intervals;
    }
};
