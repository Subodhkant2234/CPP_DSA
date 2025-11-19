https://www.geeksforgeeks.org/dsa/meeting-rooms-check-if-a-person-can-attend-all-meetings/
bool canAttendMeetings(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] < intervals[i-1][1])
            return false;  // overlap
    }
    return true;
}


class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        // Code Here
        sort(arr.begin(), arr.end());
        int n = arr.size();
        for(int i = 1; i < n; i++){
            if(arr[i-1][1] >  arr[i][0])
                return false;
        }
        return true;
    }
};




Question

Given intervals [s, e], return true/false if one person can attend all meetings (i.e., no overlap).

How to recognize it

Asks: “Can attend all?” or “Any overlap?”

Output: true/false

Approach

✔ Sort intervals by start time
✔ Check adjacent intervals for overlap

sort(intervals.begin(), intervals.end());
for (int i = 1; i < intervals.size(); i++)
    if (intervals[i][0] < intervals[i-1][1])
        return false;
return true;


Why this approach?
You must preserve interval pairing (start and end together).
→ Cannot separate starts and ends.
