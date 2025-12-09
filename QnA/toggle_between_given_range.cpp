class Solution {
  public:
    int toggleBits(int N , int L , int R) {
        // code here
        int mask = ~((~0)<<(R-L+1));
        return (N ^ (mask << (L-1)));
    }
};


class Solution {
public:
    int toggleBits(int N, int L, int R) {
        int width = R - L + 1;            // how many bits to toggle
        int mask = (1 << width) - 1;      // create mask of width bits (all 1s)
        mask <<= (L - 1);                 // shift to start at bit L
        
        return N ^ mask;                  // toggle bits
    }
};
