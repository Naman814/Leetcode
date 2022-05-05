class MyStack {
public:
    vector<int> v;
    MyStack() {
        
    }
    
    void push(int x) {
        v.push_back(x);
    }
    
    int pop() {
       int x = v.back();
       v.pop_back();
       return x;
    }
    
    int top() {
        return v.back();
    }
    
    bool empty() {
        return v.size() ? false : true;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */