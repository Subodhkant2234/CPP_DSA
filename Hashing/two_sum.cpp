class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        // code here
        unordered_set<int> s;
        for(int var : arr){
            if(s.find(target-var) != s.end())
                return true;
            else
                s.insert(var);
        }
        return false;
    }
};
