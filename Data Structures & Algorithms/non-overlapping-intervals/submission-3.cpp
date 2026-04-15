class Solution {
public:
    static bool comparator(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),comparator);

        int n = intervals.size();
        int count = 1;
        int start = intervals[0][0];
        int end = intervals[0][1];
        for(int i=1; i<n; i++){
            if(intervals[i][0] >= end){
                count++; // finding num of non-overlapping int, if the cond is true then we got 2 non-overlapping int at a same time thats why count is initialized as 1
                end = max(end, intervals[i][1]);
            }
        }
        return n-count;
    }
};
