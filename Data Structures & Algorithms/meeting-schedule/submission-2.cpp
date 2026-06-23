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
    static bool comp(const Interval &a, const Interval &b){
        if(a.start == b.start) return a.end < b.end;
        return a.start < b.start;
    }

    bool canAttendMeetings(vector<Interval>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), comp);
        if (n < 2) return true;
        int r = intervals[0].end; 
        for (int i = 1; i < n; i++) {
            if (r > intervals[i].start) return false;
            r = max(r, intervals[i].end);
        }
        return true;
    }
};
