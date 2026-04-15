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
    static bool comparator(const Interval obj1, const Interval obj2){
        return obj1.start < obj2.start;
    }

    bool canAttendMeetings(vector<Interval>& intervals) {
        int n = intervals.size();
        if(n == 0) return true;
        sort(intervals.begin(), intervals.end(), comparator);
        int start = intervals[0].start;
        int end = intervals[0].end;
        for(int i=1; i<n; i++){
            if(intervals[i].start < end) {
                return false;
            }
            end = max(end, intervals[i].end);
        }
        return true;
    }
};
