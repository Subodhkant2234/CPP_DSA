class Solution {
   public:
    // Function to merge two sorted halves of the array
    void merge(vector<int>& arr, int low, int mid, int high) {
        // Temporary array to store merged elements
        vector<int> temp;
        int left = low;
        int right = mid + 1;

        // Loop until subarrays are exhausted
        while (left <= mid && right <= high) {
            // Compare left and right elements
            if (arr[left] <= arr[right]) {
                // Add left element to temp
                temp.push_back(arr[left]);
                // Move left pointer
                left++;
            } else {
                // Add right element to temp
                temp.push_back(arr[right]);
                // Move right pointer
                right++;
            }
        }

        // Adding the remaining elements of left half
        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }

        // Adding the remaining elements of right half
        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }

        // Transferring the sorted elements to arr
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }
    void mergeSortHelper(vector<int>& nums, int low, int high) {
        if (low >= high) return;
        int mid = (low + high) / 2;
        mergeSortHelper(nums, low, mid);
        mergeSortHelper(nums, mid + 1, high);
        merge(nums, low, mid, high);
    }
    vector<int> mergeSort(vector<int>& nums) {
        int n = nums.size() - 1;
        mergeSortHelper(nums, 0, n);
        return nums;
    }
};
