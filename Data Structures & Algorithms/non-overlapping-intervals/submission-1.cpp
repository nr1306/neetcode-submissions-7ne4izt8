class Solution {
public:
    static bool comparator(vector<int>& interval1, vector<int>& interval2){
        return interval1[1] < interval2[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),comparator);

        int n = intervals.size();
        if(n == 1) return 0;
        int end = intervals[0][1];
        int count = 1; // we are gonna find the number of non-overlapping intervals
        for(int i=1; i<n; i++){
            if(intervals[i][0] >= end){
                count++; // if its start time is >= end then its non-overlapping
                end = intervals[i][1];
            }
        }
        return n - count;
    }
};
