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
    

    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.size() == 0) return 0;

    // Here the room will be alloted first according to the start time OBV...DUH!!!
        sort(intervals.begin(), intervals.end(), comparator);
    
        priority_queue<int, vector<int> , greater<int>> minheap;
        minheap.push(intervals[0].end);

// We have created minheap in order put the min ending time of rooms first
// if the meeting can't be scheduled in a room whose meeting is going to end first then its going to create conflict with other rooms as well
// If we can schedule in the min ending time room, then will just update the end time and minheap will automatically put the the min ending time of room ahead.
// We just want to compare start time of meeting with min ending time of room 
        for(int i=1; i<intervals.size(); i++){
            if(!minheap.empty() && intervals[i].start >= minheap.top())
                minheap.pop();
            minheap.push(intervals[i].end);
        }
        return minheap.size();
    }
};
