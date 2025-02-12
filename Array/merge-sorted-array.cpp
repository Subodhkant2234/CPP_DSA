class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            int i = m - 1;
            int j = n - 1;
            int k = m + n - 1;
    
            while (i >= 0 && j >= 0 && k >= 0) {
                if (nums1[i] < nums2[j]) {
                    nums1[k] = nums2[j];
                    k--;
                    j--;
                } else if (nums1[i] > nums2[j]) {
                    nums1[k] = nums1[i];
                    i--;
                    k--;
                } else {
                    nums1[k] = nums1[i];
                    k--;
                    i--;
                    nums1[k] = nums2[j];
                    k--;
                    j--;
                }
            }
    
            while (i >= 0) {
                nums1[k] = nums1[i];
                i--;
                k--;
            }
    
            while (j >= 0) {
                nums1[k] = nums2[j];
                j--;
                k--;
            }
    
            if (m == 0) {
                for (int i = 0; i < n; i++)
                    nums1[i] = nums2[i];
            }
        }
    };