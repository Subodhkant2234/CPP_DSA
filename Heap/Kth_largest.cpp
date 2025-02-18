class Solution {
  public:
    // Function to return kth largest element from an array.
    int KthLargest(vector<int> &arr, int k) {
        // Your code here
        priority_queue<int, vector<int>, greater<int>> mp; //min heap 
        for(int i = 0; i < arr.size(); i++){
            if(mp.size() < k){
                mp.push(arr[i]);
            } else{
                if(mp.top() < arr[i]){
                    mp.pop();
                    mp.push(arr[i]);
                }
            }
        }
        return mp.top();
    }
};
