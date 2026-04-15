class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int start = newInterval[0];
        int end = newInterval[1];

        int n = intervals.size();
        int startInd = 0;

        if(n == 0){
            intervals.push_back(newInterval);
            return intervals;
        }

        for(int i=0; i<n; i++){
            if(start <= intervals[i][1]){
                startInd = i;
                start = min(start, intervals[i][0]);
                while(i<n && end >= intervals[i][0]){
                    end = max(end, intervals[i][1]);
                    i++;
                }
                intervals.erase(intervals.begin()+startInd, intervals.begin()+i);
                vector<int> newInt {start, end};
                intervals.insert(intervals.begin()+startInd, newInt);
                break;
            }
            if(i == n-1) intervals.push_back(newInterval);
            // if no overlapping with any of interval. insert it in last place
        }

        return intervals;
    }
};
