#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        // ToDo: Write Your Code Here.
        unordered_map<int, int>mp;
        vector<int> res;
        int next = 0;

        for(int i = 0; i < nums.size(); i++){
            next = target - nums[i];
            if(mp.find(next) != mp.end()){
                res.push_back(i);
                res.push_back(mp[next]);
                return res;
            } else {
                mp[nums[i]] = i;
            }
        }
        return res;     
    }
};
