class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            minHeap;

        for (int x : nums)
            mp[x]++;

        for (auto& val : mp) {
            minHeap.push({val.second, val.first});
            if (minHeap.size() > k)
                minHeap.pop();
        }

        vector<int> res;
        while (k--) {
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return res;
    }
};
