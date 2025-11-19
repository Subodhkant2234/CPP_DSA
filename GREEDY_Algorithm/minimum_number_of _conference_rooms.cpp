int minMeetingRooms(vector<vector<int>>& intervals) {
    if (intervals.empty()) return 0;

    vector<int> starts, ends;
    for (auto& t : intervals) {
        starts.push_back(t[0]);
        ends.push_back(t[1]);
    }

    sort(starts.begin(), starts.end());
    sort(ends.begin(), ends.end());

    int rooms = 0, endPtr = 0;

    for (int i = 0; i < starts.size(); i++) {
        if (starts[i] < ends[endPtr]) {
            rooms++;    // need new room
        } else {
            endPtr++;   // free one room
        }
    }

    return rooms;
}
