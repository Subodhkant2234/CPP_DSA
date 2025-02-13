#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int largestUniqueNumber(vector<int>& A) {
        int maxUnique = -1;
        unordered_map<int, int>mp;

        for(int x : A){
            mp[x]++;
        }

        for(int i = 0; i < A.size(); i++){
            if(mp[A[i]] == 1){
                maxUnique = max(maxUnique,  A[i]);
            }
        }
        // ToDo: Write Your Code Here.
        return maxUnique;
    }
};
