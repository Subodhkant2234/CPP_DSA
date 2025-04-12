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
