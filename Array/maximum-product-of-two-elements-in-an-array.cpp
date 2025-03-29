class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int largest = INT_MIN;
        int second_largest = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= largest) {
                second_largest = largest;
                largest = nums[i];
            } else if (second_largest < nums[i]) {
                second_largest = nums[i];
            }
        }
        return (largest - 1) * (second_largest - 1);
    }
};
