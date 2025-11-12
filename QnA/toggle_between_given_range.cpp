class Solution {
  public:
    int toggleBits(int N , int L , int R) {
        // code here
        int mask = ~((~0)<<(R-L+1));
        return (N ^ (mask << (L-1)));
    }
};
