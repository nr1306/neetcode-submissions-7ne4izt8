class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, 
    vector<int>& newInterval) {
        int newStart = newInterval[0];
        int startInd = 0;
        int n = intervals.size();
        if(n == 0){
            intervals.push_back(newInterval);
            return intervals;
        } 

        for(int i=0; i<n; i++){
            if(newInterval[0] <= intervals[i][1]){
                newStart = min(newStart, intervals[i][0]);
                startInd = i;
                int newEnd = newInterval[1];

                while(i<n && newInterval[1] >= intervals[i][0]){
                    newEnd = max(newInterval[1], intervals[i][1]);
                    i++;
                }
                intervals.erase(intervals.begin()+startInd, intervals.begin()+i);
                intervals.insert(intervals.begin()+startInd, {newStart,newEnd});
                
                break;
            }
            if(i == n-1) intervals.push_back(newInterval); // If newInterval belongs to the last place
        }
            return intervals;
    }
};
