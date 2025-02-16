#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
string decimalToBinary(int num) {
    // ToDo: Write Your Code Here.
    stack<int>st;
    string s = "";
    while(num){
        st.push(num%2);
        num = num/2;
    }

    while(st.empty() == false){
        s += to_string(st.top());
        st.pop();
    }
    return s;
}
};
