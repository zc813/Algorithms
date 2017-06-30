// 利用 stacks LIFO 的性质，同时用两个 stacks 分别寸入栈的值和最小值。

class MinStack {
private:
    vector<int> stack_, stack_min_;
public:
    void push(int x) {
        stack_.push_back(x);
        stack_min_.push_back(stack_min_.empty()||x<stack_min_.back() ? x : stack_min_.back()); // 此处注意考虑 stack_min_ 为空的情况
    }
    
    void pop() {
        if (stack_.empty()) return;
        stack_.pop_back();
        stack_min_.pop_back();
    }
    
    int top() {
        return stack_.back();
    }
    
    int getMin() {
        return stack_min_.back();
    }
};
