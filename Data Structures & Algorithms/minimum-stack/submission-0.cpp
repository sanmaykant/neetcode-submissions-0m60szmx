class MinStack {
public:
    MinStack() = default;

    void push(int val) {
        orderedStack.push_back(val);
        if (minStack.empty() || val <= minStack.back())
            minStack.push_back(val);
    }

    void pop() {
        if (orderedStack.back() == minStack.back())
            minStack.pop_back();
        orderedStack.pop_back();
    }

    int top() {
        return orderedStack.back();
    }
    
    int getMin() {
        return minStack.back();
    }

private:
    std::vector<int> orderedStack;
    std::vector<int> minStack;
};
