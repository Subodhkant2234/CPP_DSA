using namespace std;
#include <iostream>

class Solution {
public:

  int findSquareSum(int num){
    int sum = 0;
    while(num){
      int digit = num%10;
      sum = sum + digit*digit;
      num = num/10;
    }
    return sum;
  }

  bool find(int num) {
    // TODO: Write your code here
    int slow = num;
    int fast = num;

    do{
      slow = findSquareSum(slow);
      fast = findSquareSum(findSquareSum(fast));
    }while(slow != fast);
    
    return slow == 1;
  }
};
