void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b){
	// Write your code here.
		int N = a.size();
		int M = b.size();
	    int left = N - 1;
        int right = 0;

        while (left >= 0 && right < M) {
            if (a[left] > b[right]) {
                int tmp = a[left];
                a[left] = b[right];
                b[right] = tmp;
                left--;
                right++;
            } else {
                break;
            }
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
	
}
