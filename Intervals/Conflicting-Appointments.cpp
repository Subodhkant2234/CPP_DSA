class Solution {
   public:
    struct CompareByStart {
        bool operator()(const Interval& a, const Interval& b) { return a.start < b.start; }
    };
    bool canAttendAllAppointments(vector<Interval>& Intervals) {
        // TODO: Write your code here
        sort(Intervals.begin(), Intervals.end(), CompareByStart());
        for (int i = 1; i < Intervals.size(); i++) {
            if (Intervals[i].start < Intervals[i - 1].end)
                return false;
        }
        return true;
    }
};
