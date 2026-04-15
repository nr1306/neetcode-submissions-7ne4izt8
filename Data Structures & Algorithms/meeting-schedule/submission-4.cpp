/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    static bool comparator(Interval& a, Interval& b){
        return a.end < b.end;
    }

    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), comparator);

        int start = intervals[0].start;
        int end = intervals[0].end;

        for(int i=1; i<intervals.size(); i++){
            if(intervals[i].start >= end){
                end = max(intervals[i].end , end);
            }
            else return false;
        }
        return true;
    }
};
