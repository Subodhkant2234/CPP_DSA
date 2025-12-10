Given an infinite sorted array consisting of 0s followed by 1s,
find the index of the first 1.

Example pattern:

0 0 0 0 0 1 1 1 1 1 ...


We cannot use normal binary search directly because the array is "infinite" → meaning you cannot rely on array length.

Step 1: Exponential Search

Find a bounded range [low, high] where 1 must lie.

We expand high exponentially until we hit a 1.

low = 0
high = 1

while arr[high] == 0:
    low = high
    high = high * 2


Now the first 1 must lie between low and high.

Step 2: Binary Search in this Range

Perform classical binary search in [low, high]
to find the first occurrence of 1.

code:
int firstOne(vector<int>& arr) {
    // Step 1: find high index where element becomes 1
    int low = 0;
    int high = 1;

    // Expand the high index exponentially
    while (arr[high] == 0) {
        low = high;
        high = high * 2;
    }

    // Step 2: Binary search for first 1 between low and high
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == 1) {
            ans = mid;         // possible answer
            high = mid - 1;    // look on the left side
        } else {
            low = mid + 1;     // go right
        }
    }

    return ans;
}

Important Things to Mention in Interview

If asked at Qualcomm:

✔ Cannot do n = arr.size() → array is infinite.
✔ Use exponential search to avoid TLE.
✔ Then binary search to find the first 1.
✔ Time complexity = O(log k).
✔ Works even if first 1 is at a very large index.
