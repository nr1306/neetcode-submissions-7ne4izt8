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
// Previous approach was creating meeting rooms for all conflicting meetings this was making it O(n^2)
// Then I thought if I sort the meeting end times then I would be able to directly check it with the first meeting 
// If I can schedule the meet in the first meeting room then I will update its end time by popping the top element from heap and then insert the new end time
// If I can't then there is no need to check the other ending times as they will conflict as well then I will simply insert the new end time into the heap
        priority_queue<int, vector<int>, greater<int>> minheap; 
        minheap.push(intervals[0].end);

        for(int i=1; i<n; i++){
            int start = intervals[i].start;
            int end = intervals[i].end;

            if(!minheap.empty() && minheap.top() <= start){
                minheap.pop();
            }
            minheap.push(end); // This covers the case when meeting is conflicting every meeting going on, and if this meeting can occour on the sane day then we'll update the end time
        }
        return minheap.size();
    }
};
