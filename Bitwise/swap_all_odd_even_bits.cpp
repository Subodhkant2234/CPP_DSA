class Solution
{
    public:
    //Function to swap odd and even bits.
    unsigned int swapBits(unsigned int n)
    {
    	// Your code here
    	return ((n & 0xAAAAAAAA) >> 1) | ((n & 0x55555555) << 1);
    }
};
