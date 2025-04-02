class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        // code here
        int n = start.size();
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int i = 0, j = 0;
        int max_room = 0, required_room = 0;
        while(i < n && j < n){
            if(start[i] < end[j]){
                required_room++;
                i++;
                max_room = max(max_room, required_room);
            } else {
                required_room--;
                j++;
            }
        }
        return max_room;
    }
};
