// 利用 stacks LIFO 的性质，同时用两个 stacks 分别寸入栈的值和最小值。

class MinStack {
private:
    stack<int> stack_, stack_min_;
public:
    void push(int x) {
        stack_.push(x);
        stack_min_.push(stack_min_.empty()||x<stack_min_.top() ? x : stack_min_.top()); // 此处注意考虑 stack_min_ 为空的情况
    }
    
    void pop() {
        if (stack_.empty()) return;
        stack_.pop();
        stack_min_.pop();
    }
    
    int top() {
        return stack_.top();
    }
    
    int getMin() {
        return stack_min_.top();
    }
};
