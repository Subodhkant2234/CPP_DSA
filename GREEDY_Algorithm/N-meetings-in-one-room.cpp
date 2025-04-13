class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        int n = start.size();
        vector<pair<int,int>> meets;
        for(int i=0;i<n;i++){
            meets.push_back({end[i],start[i]});
        }
        sort(meets.begin(),meets.end());
        int cnt = 0;
        int last = -1;
        for(int i=0;i<n;i++){
            if(last<meets[i].second){
                cnt++;
                last = meets[i].first;
            }
        }
        return cnt;
    }
};


/*
#include <iostream>
#include <vector>
#include <algorithm>

int maxMeetings(std::vector<int>& start, std::vector<int>& end) {
    std::vector<std::pair<int, int>> meetings;
    for (size_t i = 0; i < start.size(); ++i) {
        meetings.push_back({start[i], end[i]});
    }

    std::sort(meetings.begin(), meetings.end(), [](auto& a, auto& b) { return a.second < b.second; });

    int count = 0, last_end = 0;
    for (auto& meeting : meetings) {
        if (meeting.first > last_end) {
            ++count;
            last_end = meeting.second;
        }
    }
    return count;
}
*/
