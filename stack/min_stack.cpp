class MinStack {
private:
    stack<int> mainStack;
    stack<int> auxStack;

public:
    MinStack() {}

    void push(int val) {
        mainStack.push(val);
        if (auxStack.empty() || val <= auxStack.top())
            auxStack.push(val);
    }

    void pop() {
        int data = mainStack.top();
        mainStack.pop();
        if (data == auxStack.top())
            auxStack.pop();
    }

    int top() { return mainStack.top(); }

    int getMin() { return auxStack.top(); }
};
