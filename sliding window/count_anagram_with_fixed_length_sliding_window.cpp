//https://www.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1
//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    bool check_equal (int a[], int b[]){
        for(int i = 0; i < 26; i++) {
            if(a[i] != b[i])
                return false;
        }
        return true;
    }
    
    int search(string &pat, string &txt) {
        // code here
        int len = txt.length();
        int count = 0;
        int expect[26] = {0};
        int window[26] = {0};
        
        if(len < pat.length()) return 0;
        
        for(int i = 0; i < pat.length(); i++)
            expect[pat[i]-'a']++;
        
        int l = 0, r = 0;
        while(r < len){
            window[txt[r]-'a']++;
            if(r-l+1 == pat.length()){
                if(check_equal(expect,window))
                    count++;
                window[txt[l]-'a']--;
                l++;
            }
            r++;
        }
        return count;
    }
};
