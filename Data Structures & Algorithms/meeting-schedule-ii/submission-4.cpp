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
        return a.start < b.start;
    }

    static bool comparator1(Interval& a, int& b){
        return a.start >= b;
    }

    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        if(n == 0) return n;
        sort(intervals.begin(), intervals.end(), comparator);
        
        int start = intervals[0].start;
        int end = intervals[0].end;
        
        vector<int> meetR; // we are gonna store meeting end times in particular room, if a meeting is conflicting we are putting in different room 
        meetR.push_back(end);
        
        for(int i=1; i<n; i++){
            start = intervals[i].start;
            end = intervals[i].end;
            int size = meetR.size();
            int j=0;
            for(; j<size; j++){
                int endTemp = meetR[j]; // end time of jth meeting room
                if(start < endTemp)
                    continue;
                else{
                    meetR[j] = end; // updating the end time of that meeting room
                    break;
                }
            }
            if(j == size){
                meetR.push_back(end); // This meeting was conflicting with every meeting so added to new room
            }
        }
        return meetR.size();
    }
};
