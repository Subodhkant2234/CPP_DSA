class Solution{
public:
    int toyCount(int N, int K, vector<int> arr)
    {
        // code here
        int count = 0, sum = 0;
        sort(arr.begin(), arr.end());
        for(int i = 0; i < N; i++){
            if(sum + arr[i] <= K){
                count++;
                sum += arr[i];
            }   
        }
        return count;
    }
};
